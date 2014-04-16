//
//  accFunction.c
//  accounting
//
//  Created by bill on 4/6/14.
//  Copyright (c) 2014 buildAll. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
//#include <conio.h>
#include "dataHandleinc.h"


#include <sys/types.h>
#include <sys/stat.h>
//#include <unistd.h>

char* dataGetHome()
{
    char* userHomePath;

    //userHomePath = getenv("HOME");
    userHomePath = getenv(FINDHOME);
    return userHomePath;
}



char* dataUserName()
{
    char* szUserName;
    //szUserName = getenv("USER");
   
   szUserName = getenv("LOGNAME");

    
    //printf(szUserName);
    return szUserName;
}
#if(0)
char* dataPathCrate(char* type)
{
    struct stat st = {0};
    char * userName;
    
    char  directory[1024] = {'\0'};

    
    
    //char new_dir[]="/User/bill/Library/Application Support/AccountRobert";
    
    userName = dataGetHome();
    
   // printf(userName);

    strcpy(directory, userName);
    
    strcat(directory, APPDIRECTORY);
    
    if (stat(directory, &st) == -1)
    {
        
        if((mkdir(directory, 07777)) == 0)
            printf("system error !\n");
            exit(1);  
    }

    strcat(directory, type);
/*
    for (int i = 0; i < strlen(directory); ++i)
    {
        path[0] = directory[0];
    }
*/
    printf(directory);
    printf("\n");

    return directory;
}
#endif

void dataPathCreate(char* path,char*type)
{
    struct stat st = {0};
    char * userHome;
    
    //char  directory[1024] = "/Users/";

    //char startString[] = "/Users/";// It can be defined as a MARCO to distinguish the OS from MAC OS and WINDOWS
/*
    for (int i = 0; i < sizeof(startString); ++i)
    {
        path[0]=startString[0];
    }
 */ 
    //strcpy(path, startString);   
    //char new_dir[]="/User/bill/Library/Application Support/AccountRobert";
    
    userHome = dataGetHome();
    
   // printf(userName);

    strcpy(path, userHome);
    
    strcat(path, APPDIRECTORY);
    
    if (stat(path, &st) == -1)
    {
        
        if((mkdir(path, 07777)) == 0)
            printf("system error !\n");
            exit(1);  
    }

    strcat(path, type);
/*
    for (int i = 0; i < strlen(path); ++i)
    {
        path[0] = path[0];
    }
*/
  //    printf(path);
  //  printf("\n");

    return;
}

float dataGet(char* path)
{
    FILE* data;

    float consume = 0;

    
    if((data = fopen(path, "r+")) == NULL)
    {
       // printf("No data file be found, trying to create a new one\n");
        if((data = fopen(path, "w+")) == NULL)
        {
            printf("system fail, type 0\n");
            exit(0);
        }
        else
        {
            fwrite(&consume, sizeof(float), 1, data);
        }
    }
    
    
    rewind(data);
    
    fread(&consume, sizeof(float), 1, data);
    
    //printf("read completed, the numebr is %.2f\n", consume);
    
    fclose(data);
    
    return consume;
}



void dataStore(char *path, float content)
{
    FILE* store;

    float consume = content;

    if((store = fopen(path, "r+")) == NULL)
    {
            printf("system fail, type 0\n");
            exit(0);
    }

    rewind(store);

    fwrite(&consume, sizeof(float), 1, store);

    fclose(store);

    return;
}

float dataCompute(float newConsume, float totalConsume)
{
    float total;

    total = newConsume + totalConsume;

    return total;
}




void dataReset(char* originalPath,char* objectPath)
{
    FILE* originalFile;
    FILE* objectFile;


    float originalData;
    float objectData;

    


    if((originalFile = fopen(originalPath,"r+")) == NULL)
    {
        printf("Please create the data file first");  
        return;  
    }    

    

    fread(&originalData,sizeof(float),1,originalFile);

    rewind(originalFile);
    
    if((objectFile = fopen(objectPath,"r+")) == NULL)
    {
        printf("Please create the data file first");  
        return;  
    }    

    //rewind(dataFile);

    fread(&objectData,sizeof(float),1, objectFile);
    rewind(objectFile);

    objectData = originalData + objectData;

    fwrite(&objectData, sizeof(float), 1, objectFile);
    
    originalData = 0;

    fwrite(&originalData, sizeof(float), 1, originalFile);

    fclose(originalFile);
    fclose(objectFile);
    return;
}