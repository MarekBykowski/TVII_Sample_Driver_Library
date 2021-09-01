/***************************************************************************//**
* \file main_cm7_0.c
*
* \version 1.0
*
* \brief Main example file for CM7
*
********************************************************************************
* \copyright
* Copyright 2016-2020, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "cy_project.h"
#include "cy_device_headers.h"

/* Include default crypto configuration.
 * You can use other configuration instead follows.
 */
#include "crypto/cy_crypto_config.h"

/* For CRYPTO client that can run on the both CPUs */
cy_stc_crypto_context_t        cryptoCtx;

/* Test vector */
uint8_t modulus[] = 
{
/* This is a modulus. (a part of public key)
 * Refer public_key.txt
 */
/* Big endien format */
    0xc5,0x98,0xb6,0xe7,0xb8,0x02,0x87,0x90,0xfa,0x77,0x75,0x1e,0xcf,0x55,0x30,0x8a,
    0xd0,0x73,0x46,0x3e,0x97,0x23,0x89,0xf1,0xc2,0x22,0xdb,0xa9,0xf5,0x99,0xeb,0xd5,
    0x88,0xbf,0x2a,0x87,0x74,0x89,0xc9,0x79,0x52,0x37,0xd1,0x33,0x86,0xce,0x82,0x3f,
    0xc4,0x06,0x91,0x42,0x0f,0x91,0x09,0x17,0xb8,0x41,0xd0,0x47,0x5f,0xfe,0xaf,0x34,
    0x51,0x68,0xd4,0xbe,0x4a,0xc7,0x6c,0xd7,0x43,0xe5,0xa6,0x21,0x4e,0xab,0x4f,0x9e,
    0x05,0x72,0x9a,0x9a,0x02,0xc1,0x0e,0x78,0x72,0x53,0x90,0x65,0x93,0x90,0x49,0x67,
    0x3f,0x21,0xc4,0x0e,0x4b,0xf2,0xdc,0xf0,0x8f,0xd3,0x09,0x6f,0x0c,0xc9,0x91,0x6e,
    0xbf,0xfb,0xac,0x76,0x45,0xf4,0xf3,0x48,0xb1,0xf4,0x33,0x0b,0xde,0x75,0x90,0xf9,
};

uint8_t publicExponent[] = 
{
/* This is a part of public key. (So called e)
 * Refer public_key.txt
 */
/* Big endien format */
    0x01, 0x00, 0x01
};

uint8_t encryptedSignature[] = 
{
/* PKCS#1 v1.5 signature with SHA256.
 * This value is calculated from private_key.pem and plain_text.txt.
 * You can calculate the value if using OpenSSL:
 *  openssl dgst -sha256 -sign private_key.pem plain_text.txt > signature.sig
*/
/* Big endien format */
    0x19,0xE8,0x9F,0xE9,0xD9,0xCC,0x33,0x5E,0xCE,0x15,0xC9,0x31,0x8F,0x62,0x28,0x63,
    0xC4,0xB6,0xF8,0x1D,0xE5,0x00,0xDD,0x9B,0xB5,0x08,0x53,0x30,0x75,0xF0,0x98,0xB5,
    0xFB,0xAE,0xA2,0x55,0xF0,0xBA,0xD5,0x06,0x40,0x2D,0x61,0x7E,0xE1,0x7E,0xCF,0x05,
    0x0C,0xEF,0x54,0xD5,0xDA,0xEF,0xC4,0xBE,0xCC,0xB6,0x5C,0xDB,0xF2,0xDC,0xD2,0xAC,
    0x13,0x0F,0x61,0x72,0x8A,0xA9,0x2E,0xD5,0xC8,0x78,0xF8,0x6F,0xB7,0xF1,0x36,0xA3,
    0x7C,0x1A,0x04,0xBF,0xB3,0x64,0xFB,0xD3,0x1A,0x63,0x5A,0xBC,0x65,0x8B,0x4F,0x24,
    0x50,0xA3,0x91,0xA1,0x27,0x41,0x86,0x2C,0x82,0x47,0xB9,0xEC,0x30,0xC3,0xA6,0xF9,
    0xD1,0xE5,0xA3,0x7F,0x44,0xB6,0x57,0x8F,0x55,0x2A,0x17,0xFE,0xDD,0x1C,0xD0,0x41,
};

/* The plain text that is used to calculate the HASH in the signature. */
uint8_t plainTxt[] = "hogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehoge";
uint8_t decryptedSignature[1024/8];
uint8_t calculatedHash[CY_CRYPTO_SHA256_DIGEST_SIZE];

cy_en_crypto_rsa_ver_result_t verifyResult;

/***********************************************************************************************************************
 * RSA decryption
 ***********************************************************************************************************************/
void Run_RSA(void)
{
    cy_stc_crypto_context_rsa_t cryptoRsaContext;
    cy_stc_crypto_context_sha_t cryptoShaContext;

    /* At first convert endianness big to little.
     * Input keys and message are treated as little endian integer by Cy_Crypto_Rsa_Proc/Cy_Crypto_Rsa_CalcCoefs.
     */
    Cy_Crypto_Rsa_InvertEndianness(modulus, sizeof(modulus));
    Cy_Crypto_Rsa_InvertEndianness(publicExponent, sizeof(publicExponent));
    Cy_Crypto_Rsa_InvertEndianness(encryptedSignature, sizeof(encryptedSignature));

    /* Decrypt with the public key */
    {
        cy_stc_crypto_rsa_pub_key_t pubKeyPtr = 
        {
            .moduloPtr          = &modulus,
            .moduloLength       = 1024,     /* 1024 bits */
            .pubExpPtr          = &publicExponent,
            .pubExpLength       = 17,       /* 17 bits */
            .barretCoefPtr      = NULL,     /* Can be NULL. All coefficients will be calculated in  Cy_Crypto_Rsa_Proc */
            .inverseModuloPtr   = NULL,     /* Same as above */
            .rBarPtr            = NULL,     /* Same as above */
        };

        /* At first decrytp the received signature. */
        Cy_Crypto_Rsa_Proc
        (
            &cryptoCtx,
            &cryptoRsaContext,
            &pubKeyPtr,
            &encryptedSignature,
            1024u / 8u,         /* Size in byte */
            &decryptedSignature
        );
        /* Wait for completion */
        Cy_Crypto_Sync(true, &cryptoCtx);

        /* Calculated result is little endian */
        /* Then to compare with reference value, convert endianness to big endian. */
        Cy_Crypto_Rsa_InvertEndianness(decryptedSignature, sizeof(decryptedSignature));

        /* Calculate the hash from the plain text */
        Cy_Crypto_Sha_Run
        (
            &cryptoCtx,
            &cryptoShaContext,
            &plainTxt,
            sizeof(plainTxt) - 1u,  /* Except \0 */
            &calculatedHash,
            CY_CRYPTO_MODE_SHA256
        );
        /* Wait for completion */
        Cy_Crypto_Sync(true, &cryptoCtx);

        /* Finally verify decrypted signature with calculated digest */
        cy_stc_crypto_context_rsa_ver_t cryptoRsaVerContext;
        Cy_Crypto_Rsa_Verify
        (
            &cryptoCtx,
            &cryptoRsaVerContext,
            &verifyResult,
            CY_CRYPTO_MODE_SHA256,
            &calculatedHash,
            &decryptedSignature,
            sizeof(decryptedSignature)
        );
        /* Wait for completion */
        Cy_Crypto_Sync(true, &cryptoCtx);

        /* Check the result. */
        /* You can remove following ASSERT */
        CY_ASSERT(verifyResult == CY_CRYPTO_RSA_VERIFY_SUCCESS);
        /* Then you can get the result from cryptoRsaVerContext */
    }
}

/***********************************************************************************************************************
 * main function
 ***********************************************************************************************************************/
int main(void)
{
    SystemInit();

    // Example had been originally tested with "cache off", so ensure that caches are turned off (may have been enabled by new startup.c module)
    SCB_DisableICache(); // Disables and invalidates instruction cache
    SCB_DisableDCache(); // Disables, cleans and invalidates data cache

    __enable_irq(); /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    /* Initialize and enable CRYPTO */
    {
        cy_en_crypto_status_t status;
        do
        {
            status = Cy_Crypto_Init(&cryptoConfig, &cryptoCtx);
        } while(status != CY_CRYPTO_SUCCESS);
        Cy_Crypto_Enable(&cryptoCtx);
    }

    /* Run RSA */
    Run_RSA();

    for(;;)
    {
    }
}



/* [] END OF FILE */
