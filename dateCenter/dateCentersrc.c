#include "dateCenterinc.h"
#include <stdlib.h>

#include <stdio.h>



void dateToday()
{
    time_t now = time(NULL);
    struct tm *today = localtime(&now);
    
    todayDay = today->tm_mday;
    todayMonth = today->tm_mon+1;
    todayYear = today->tm_year;

    return;
}

void dateGetPrevious(char *path,int type)
{
   FILE* dateFile; 

   



    if((dateFile = fopen(path, "r+")) == NULL)
    {
        printf("Please create the date first !\n");
        return;
    }


    switch(type)
    {
        case 0:
        fread(&oldDay, sizeof(int), 1, dateFile);
        break;
        case 1:
        fread(&oldMonth, sizeof(int), 1, dateFile);
        break;
        case 2:
        fread(&oldYear, sizeof(int), 1, dateFile);
    }
        
    fclose(dateFile);

    return;
}


void dateStroeCreate(char *path,int type)
{
    FILE* dateFile; 



    if((dateFile = fopen(path, "r+")) == NULL)
    {
        //printf("No data file be found, trying to create a new one\n");
        if((dateFile = fopen(path, "w+")) == NULL)
        {
            printf("system fail, type 0\n");
            exit(0);
        }
        else
        {   
            switch(type)
            {
                case 0:
                fwrite(&todayDay, sizeof(int), 1, dateFile);
                break;
                case 1:
                fwrite(&todayMonth, sizeof(int), 1, dateFile);
                break;
                case 2:
                fwrite(&todayYear, sizeof(int), 1, dateFile);
            }
        }
    }

    fclose(dateFile);

    return;
}

bool dateCheckChange(int newDate, int oldDate)
{
    if (newDate != oldDate)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void dateUpdate(char *path, int newDate)
{
    FILE* dateStoreFile;

    int dateNew = newDate;

    if((dateStoreFile = fopen(path, "r+")) == NULL)
    {
            printf("system fail, type 0\n");
            exit(0);
    }

    rewind(dateStoreFile);

    fwrite(&dateNew, sizeof(int), 1, dateStoreFile);

    fclose(dateStoreFile);

    return;
}


