/***************************************************************************//**
* \file wav.c
*
* \version 1.0
*
* \brief Supporting example file
*
********************************************************************************
* \copyright
* Copyright 2016-2020, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>


typedef struct WAV_struct
{
    unsigned long  ChunkID;
    unsigned long  ChunkSize;
    unsigned long  Format;
    unsigned long  SubChunk1_ID;
    unsigned long  SubChunk1_Size;
    unsigned short AudioFormat;
    unsigned short ChannelNumber;
    unsigned long  SampleRate;
    unsigned long  ByteRate;
    unsigned short BlockAlign;
    unsigned short BitsPerSample;
    unsigned long  SubChunk2_ID;
    unsigned long  Subchunk2_Size;  
    unsigned short *Data;           
}Wave;
Wave wave;


int i   =   0;
int NUM =   0;

int main()
{

   signed short *p;
   
   FILE *fp,*fp2;   
   
   fp = fopen("audio.wav","rb");
   if(fp == 0)
      {
        printf("open filed failed!\n");
        return 0;
   }

   fp2 = fopen("wav.h","w");
   if(fp2 == 0)
   {
        printf("open filed failed!\n");
        return 0;
   }
    
    fseek(fp, 0L, SEEK_END); // seek to end of file
    int size = ftell(fp); // get current file pointer
    fseek(fp, 40L, SEEK_SET); // seek back to beginning of file
    printf("Size:%d\n",size);
    
    
    fread(&wave.Subchunk2_Size, sizeof(wave.Subchunk2_Size), 1, fp);
    wave.Data = (short*)malloc(sizeof(short)*wave.Subchunk2_Size/2);  
    fseek(fp, 44L, SEEK_SET); 
 
    
    printf("Start \n");
    
    fprintf(fp2, "%s\n", "#if (Wav_used == 1)");
    fprintf(fp2, "int size = %d; \n", size);
    fprintf(fp2, "const uint16_t DATA[%d]= \n", size);
    fprintf(fp2, "%s\n", "{");
    
 
    
    for(;;)
    {    
        if(NUM >= (size/2) && i >= (size/2))
        {
            printf("NUM:%d\n",NUM);
            printf("I:%d\n",i);            
            printf("End \n");
            break;
        }
        else
        {
            NUM = NUM + 32;
            for(i;i < NUM ;i++)                                            //change here
            {
                fread(&wave.Data[i], sizeof(short), 1, fp);
                p = (signed short*)wave.Data;
                fprintf(fp2, "0x%04hX, ",p[i]);
            }  
        }
    }

    fprintf(fp2, "\n");        
    fprintf(fp2, "%s\n", "};");
    fprintf(fp2, "%s\n", "#endif "); 
    
    fclose(fp2);
    fclose(fp);
    
    printf("Finished \n"); 
    

}
    

