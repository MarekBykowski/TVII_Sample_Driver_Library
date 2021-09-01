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

uint8_t privateExponent[] = 
{
/* This is private key. (So called d)
 * Refer private_key.txt
 */
/* Big endien format */
    0x9a,0xb1,0x4b,0x08,0x2f,0x93,0xb3,0x64,0x39,0xe1,0xc9,0x8c,0x3c,0x4e,0xfa,0x38,
    0xc2,0xa6,0x6c,0x68,0xd5,0xd4,0x19,0xcb,0x6d,0xeb,0xf2,0x42,0xa5,0xa7,0x41,0xed,
    0x23,0x28,0x5d,0xf8,0x3b,0xb1,0x1f,0x4c,0xde,0xa4,0x1a,0x20,0x97,0xba,0x16,0x58,
    0x2b,0x73,0xe4,0xc6,0x6d,0xff,0x62,0xb9,0xf2,0x23,0x7c,0x16,0x54,0xbd,0xc3,0x94,
    0xf6,0xa3,0x71,0x27,0xc6,0xb7,0xc2,0x23,0xd5,0x75,0xc1,0xeb,0xc1,0xfd,0x36,0x61,
    0x9e,0x37,0xe1,0x86,0xb6,0x1e,0xe5,0x8b,0x0c,0xe7,0xd0,0x7e,0x95,0x34,0x46,0x0c,
    0xb2,0x11,0x3f,0xe0,0x23,0xa6,0x55,0x3d,0x1b,0xdd,0xc9,0x04,0x7f,0x3e,0x47,0x69,
    0x9b,0x8b,0x05,0xa8,0x57,0xec,0x0a,0xe6,0x66,0x04,0x77,0xec,0x74,0x0e,0xe5,0x81,
};

uint8_t publicExponent[] = 
{
/* This is a part of public key. (So called e)
 * Refer public_key.txt
 */
/* Big endien format */
    0x01, 0x00, 0x01
};

uint8_t cipherTxt[] = 
{
/* This value is calculated from
 * public_key.pem and plain_text.txt. (without any padding, the plain text is just 1024bits)
 * You can calculate the value if using OpenSSL:
 *  openssl rsautl -encrypt -pubin -inkey public_key.pem -in plain_text.txt -raw -out encrypted_with_publickey.encrypted
*/
/* Big endien format */
    0xA9,0x51,0xE4,0x0D,0xD8,0x2C,0x7A,0xB7,0x06,0xB7,0x50,0x3C,0xC3,0xBB,0x59,0x3F,
    0x64,0x71,0xA0,0x7C,0x36,0xD2,0x18,0x57,0xA2,0xD2,0xB1,0xBE,0x0C,0x40,0x58,0x2C,
    0x55,0xE4,0xFB,0xDD,0x5C,0x0D,0xB3,0x23,0x5B,0x47,0x4C,0xD1,0x17,0x2C,0xCC,0xB4,
    0xB1,0x85,0x4A,0x73,0x99,0xBA,0x53,0x20,0xF4,0xD6,0xFE,0xED,0x2C,0x8F,0xB9,0xB7,
    0x7B,0x9A,0xCE,0x48,0xE6,0x46,0x71,0x06,0xF4,0xC6,0xFA,0xD6,0x03,0xE3,0x24,0x5E,
    0x46,0x7D,0x14,0x83,0x9D,0x5B,0x54,0x89,0x63,0x70,0xD7,0x12,0x89,0x5E,0xD9,0xD4,
    0x36,0xE4,0x4F,0x8D,0x1A,0xF9,0xF0,0xD5,0x3E,0x96,0xD9,0x3C,0x51,0x69,0x65,0xE5,
    0xE7,0xA3,0xAB,0xE5,0xBD,0xBA,0x69,0x2F,0xD3,0xB5,0xA9,0xD6,0x9E,0xE6,0xCE,0xF5,
};

uint8_t decryptedTxt[1024/8];

/* The plain text that encrypted to cipherTxt (except end of the string \0) */
/* Endianess is also big endian */
uint8_t decryptedTxt_ref[] = "hogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehoge";

/* The plain text. Same as decryptedTxt_ref */
/* Endianess is also big endian */
uint8_t plainTxt[] = "hogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehogehoge";

uint8_t encryptedTxt[1024u/8u];

uint8_t encryptedTxt_ref[] = 
{
/* Same as cipherTxt */
/* Big endien format */
    0xA9,0x51,0xE4,0x0D,0xD8,0x2C,0x7A,0xB7,0x06,0xB7,0x50,0x3C,0xC3,0xBB,0x59,0x3F,
    0x64,0x71,0xA0,0x7C,0x36,0xD2,0x18,0x57,0xA2,0xD2,0xB1,0xBE,0x0C,0x40,0x58,0x2C,
    0x55,0xE4,0xFB,0xDD,0x5C,0x0D,0xB3,0x23,0x5B,0x47,0x4C,0xD1,0x17,0x2C,0xCC,0xB4,
    0xB1,0x85,0x4A,0x73,0x99,0xBA,0x53,0x20,0xF4,0xD6,0xFE,0xED,0x2C,0x8F,0xB9,0xB7,
    0x7B,0x9A,0xCE,0x48,0xE6,0x46,0x71,0x06,0xF4,0xC6,0xFA,0xD6,0x03,0xE3,0x24,0x5E,
    0x46,0x7D,0x14,0x83,0x9D,0x5B,0x54,0x89,0x63,0x70,0xD7,0x12,0x89,0x5E,0xD9,0xD4,
    0x36,0xE4,0x4F,0x8D,0x1A,0xF9,0xF0,0xD5,0x3E,0x96,0xD9,0x3C,0x51,0x69,0x65,0xE5,
    0xE7,0xA3,0xAB,0xE5,0xBD,0xBA,0x69,0x2F,0xD3,0xB5,0xA9,0xD6,0x9E,0xE6,0xCE,0xF5,
};

uint8_t barretCoef[1024u/8u + 1u];  /* Must be modulo length + 1 BITS */
uint8_t inverseModulo[1024u/8u];    /* Must be same as modulo length */
uint8_t rBar[1024u/8u];             /* Must be same as modulo length */

/***********************************************************************************************************************
 * RSA decryption
 ***********************************************************************************************************************/
void Run_RSA(void)
{
    cy_stc_crypto_context_rsa_t cryptoRsaContext;

    /* At first convert endianness big to little.
     * Input keys and message are treated as little endian integer by Cy_Crypto_Rsa_Proc/Cy_Crypto_Rsa_CalcCoefs.
     */
    Cy_Crypto_Rsa_InvertEndianness(cipherTxt, sizeof(cipherTxt));
    Cy_Crypto_Rsa_InvertEndianness(modulus, sizeof(modulus));
    Cy_Crypto_Rsa_InvertEndianness(privateExponent, sizeof(privateExponent));
    Cy_Crypto_Rsa_InvertEndianness(publicExponent, sizeof(publicExponent));
    Cy_Crypto_Rsa_InvertEndianness(plainTxt, sizeof(plainTxt) - 1); /* Without end of \0 */

    /* Decrypt with the private key */
    {
        cy_stc_crypto_rsa_pub_key_t pubKeyPtr = 
        {
            .moduloPtr          = &modulus,
            .moduloLength       = 1024,     /* 1024 bits */
            .pubExpPtr          = &privateExponent,
            .pubExpLength       = 1024,     /* 1024 bits */
            .barretCoefPtr      = NULL,     /* Can be NULL. All coefficients will be calculated in  Cy_Crypto_Rsa_Proc */
            .inverseModuloPtr   = NULL,     /* Same as above */
            .rBarPtr            = NULL,     /* Same as above */
        };

        Cy_Crypto_Rsa_Proc
        (
            &cryptoCtx,
            &cryptoRsaContext,
            &pubKeyPtr,
            &cipherTxt,
            1024u / 8u,         /* Size in byte */
            &decryptedTxt
        );
        /* Wait for completion */
        Cy_Crypto_Sync(true, &cryptoCtx);

        /* Calculated result is little endian */
        /* Then to compare with reference value, convert endianness to big endian. */
        Cy_Crypto_Rsa_InvertEndianness(decryptedTxt, sizeof(decryptedTxt));

        /* Compare with reference value just for testing. */
        /* You can remove following ASSERT */
        CY_ASSERT(memcmp(&decryptedTxt, &decryptedTxt_ref, 1024u/8u) == 0);
        /* Then you can get the result from decryptedTxt */
    }

    /* Encrypt with the public key */
    {
        cy_stc_crypto_rsa_pub_key_t pubKeyPtr = 
        {
            .moduloPtr          = &modulus,
            .moduloLength       = 1024,     /* 1024 bits */
            .pubExpPtr          = &publicExponent,
            .pubExpLength       = 17,       /* 17 bits */
            .barretCoefPtr      = NULL, /* Can be NULL. All coefficients will be calculated in  Cy_Crypto_Rsa_Proc */
            .inverseModuloPtr   = NULL, /* Same as above */
            .rBarPtr            = NULL, /* Same as above */
        };

        Cy_Crypto_Rsa_Proc
        (
            &cryptoCtx,
            &cryptoRsaContext,
            &pubKeyPtr,
            &plainTxt,
            1024u / 8u,         /* Size in byte */
            &encryptedTxt
        );
        /* Wait for completion */
        Cy_Crypto_Sync(true, &cryptoCtx);

        /* Calculated result is little endian */
        /* Then to compare with reference value, convert endianness to big endian. */
        Cy_Crypto_Rsa_InvertEndianness(encryptedTxt, sizeof(encryptedTxt));

        /* Compare with reference value just for testing. */
        /* You can remove following ASSERT */
        CY_ASSERT(memcmp(&encryptedTxt, &encryptedTxt_ref, 1024u/8u) == 0);
        /* Then you can get the result from encryptedTxt */
    }

    /* Encrypt with the public key */
    /* You can calculate the accelerator coefficients by Cy_Crypto_Rsa_CalcCoefs */
    {
        cy_stc_crypto_rsa_pub_key_t pubKeyPtr = 
        {
            .moduloPtr          = &modulus,
            .moduloLength       = 1024,     /* 1024 bits */
            .pubExpPtr          = &publicExponent,
            .pubExpLength       = 17,       /* 17 bits */
            .barretCoefPtr      = &barretCoef,
            .inverseModuloPtr   = &inverseModulo,
            .rBarPtr            = &rBar,
        };

        /* Calculate the coefficients previously */
        Cy_Crypto_Rsa_CalcCoefs
        (
            &cryptoCtx,
            &cryptoRsaContext,
            &pubKeyPtr
        );
        /* Wait for completion */
        Cy_Crypto_Sync(true, &cryptoCtx);

        /* Then encrypt the message */
        Cy_Crypto_Rsa_Proc
        (
            &cryptoCtx,
            &cryptoRsaContext,
            &pubKeyPtr,
            &plainTxt,
            1024u / 8u,         /* Size in byte */
            &encryptedTxt
        );
        /* Wait for completion */
        Cy_Crypto_Sync(true, &cryptoCtx);

        /* Calculated result is little endian */
        /* Then to compare with reference value, convert endianness to big endian. */
        Cy_Crypto_Rsa_InvertEndianness(encryptedTxt, sizeof(encryptedTxt));

        /* Compare with reference value just for testing. */
        /* You can remove following ASSERT */
        CY_ASSERT(memcmp(&encryptedTxt, &encryptedTxt_ref, 1024u/8u) == 0);
        /* Then you can get the result from encryptedTxt */
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
