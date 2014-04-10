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
#include "accHead.h"


#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>










char* getTodayDate()
{
    
    time_t currentTime;
    char* cTimeString;
    
    currentTime = time(NULL);
    
    if (currentTime == ((time_t)-1))
    {
        fprintf(stderr, "Failure to compute the current time.");
        return 0;
    }
    
    /* Convert to local time format. */
    cTimeString = ctime(&currentTime);
    
    if (cTimeString == NULL)
    {
        fprintf(stderr, "Failure to convert the current time.");
        return 0;
    }
    
    //*(cTimeString++) = '\0';
    
    return cTimeString;
}

void displayWelcome()
{
    FILE* interfaceForUser;
    long length;
    long count;
    float todayTotal;
    
    char* msgForUser = NULL;
    char chOfFile;
    
    bool dateWrtieDone = false;
    
    char* todayDate;
    
    
    if((interfaceForUser = fopen("/Users/bill/Documents/Program/cProgramming/demoAPP/Accounting/accounting/accounting/Work/interfaceForUser", "r+")) == NULL)
    {
        printf("system fail, type 0\n");
        exit(0);
    }
    else
    {
        fseek(interfaceForUser,0L,SEEK_END);
        length = (int)ftell(interfaceForUser);
        //printf("the file's length is %1dB\n",length);
        //fclose(interfaceForUser);
        
        todayDate = getTodayDate();
        todayTotal = calTodayTotal(0);
        
    }
    
    rewind(interfaceForUser);
    
    msgForUser = (char*)malloc(length*sizeof(char));
    
   // fgets(msgForUser, length, interfaceForUser);
    //fputs(msgForUser, stdout);
    for (count = 0L; count<length; count++)
    {
        chOfFile = getc(interfaceForUser);
        
        if (dateWrtieDone && (chOfFile == ':'))
        {
            fseek(interfaceForUser, 1L, SEEK_CUR);
           // fwrite(&todayTotal, sizeof(float), 1, interfaceForUser);
           // break;
            fseek(interfaceForUser, 1L, SEEK_CUR);
            putchar(':');
            printf("%.1f RMB today\n",todayTotal);
            dateWrtieDone = true;
            continue;
        }
        
        if ((!dateWrtieDone) && (chOfFile == ':'))
        {
            
           /*
            fseek(interfaceForUser, 0L, SEEK_CUR);
            fwrite(todayDate, sizeof(char)*strlen(todayDate), 1, interfaceForUser);
            */
            fseek(interfaceForUser, 1L, SEEK_CUR);
            putchar(':');
            printf("%s",todayDate);
            dateWrtieDone = true;
            continue;
        }
        
        if (chOfFile == '#')
        {
            break;
        }
        
        if (chOfFile == '\r')
            putchar('\n');
        else
            putchar(chOfFile);
        
    }
  /*
    rewind(interfaceForUser);
    
    fseek(interfaceForUser,0L,SEEK_END);
    length = (int)ftell(interfaceForUser);
    
    rewind(interfaceForUser);
    
    fread(msgForUser, sizeof(char), length, interfaceForUser);
    fprintf(stdout, msgForUser);
*/
    
    
    
    free(msgForUser);
    
    fclose(interfaceForUser);
    
    
    return;
}






int getAction()
{
    int  actionID = -1;
    char ch;
    bool inputSuccess = true;
    
    //fflush(stdin);
    printf(" Please enter the number to choose your action:\n");
    while (1)
    {
        inputSuccess = true;
        scanf("%d",&actionID);
        switch (actionID)
        {
            case quit:
            case newExpense:
            case checkToday:
            case checkMonth:
            case checkYear:
            case checkHistory:
                
                while ((ch = getchar())!='\n')
                {
                    if ((ch == '.')||(!(ch>='0'&&ch<='6')))
                    {
                        printf("Please only enter the number from 0 to 6 \n");
                        printf(" Please enter the number to choose your action:\n");
                        inputSuccess = false;
                        while ((ch = getchar())!='\n');
                        break;
                    }
                }
                
                if (!inputSuccess) {
                    fflush(stdin);
                    break;
                }
                
                printf(" Please wait a moment, I am trying my best to do the action\n");
                system("clear");
                return actionID;
                //break;
                
                
                
            default:
//                fflush(stdin);
//                fflush(stdout);
                  printf(" Sorry, I can not provide this service, please re-enter your choice:\n ");
                //fflush(stdin);
                //fflush(stdout);
                
                while ((ch = getchar())!='\n')
                {
                    //putchar(ch);;
                }
                
                //printf("Please enter the number to choose your action:\n");
                //scanf("%d",&actionID);
                continue;
                //return actionID;
                //break;
        }
        
    }
}



void getNewExpense()
{
    struct Expense newExpense;
    float totalConsumeToday;
    
    char  ch;
    
    bool reGet = false;
    
    int counter = 0;
    
    
    do {
        reGet = false;
        counter = 0;
       // while ((ch = getchar())!='\n');
        printf("Please enter the money you spent:\n");
        scanf("%f",&newExpense.moneyExpense);
        while ((ch = getchar())!='\n')
        {
            if ((ch >= '0' && ch <= '9')|| ch == '.')
            {
                if (ch == '.')
                {
                    counter++;
                    if (counter >= 1)
                    {
                        reGet = true;
                        printf("There shall be only one '.'\n");
                        while ((ch = getchar())!='\n');
                        //counter = 0;
                        break;
                        
                    }
                    /*
                    if (counter >= 2)
                    {
                        reGet = true;
                        printf("There shall be only one '.'\n");
                        while ((ch = getchar())!='\n');
                        counter = 0;
                        break;

                    }
                    else if(counter == 0 || counter == 1)
                        reGet = false;
                     */
                }
                
            }
            else
            {
                reGet = true;
                printf("Please enter number for your expense...\n");
                while ((ch = getchar())!='\n');
                    break;
            }
            
        }
    } while (reGet);
    
    totalConsumeToday = calTodayTotal(newExpense.moneyExpense);
    printf("Expense recorded!\n");

    
    return;
}

float calTodayTotal(float newExpense)
{
    FILE* today;
    float totalConsumeToday;
    
    
    if((today = fopen("/Users/bill/Documents/Program/cProgramming/demoAPP/Accounting/accounting/accounting/Work/totalToday", "r+")) == NULL)
       
       printf("SYSTEM ERROR\n");// It needs add a error handler here
    
    
    rewind(today);
    
    
    fread(&totalConsumeToday, sizeof(float), 1, today);
    rewind(today);
    
    if (newExpense>0)
    {
        totalConsumeToday += newExpense;
        fwrite(&totalConsumeToday, sizeof(float), 1, today);
        rewind(today);
    }
   
    fclose(today);
    
    return totalConsumeToday;
}


void handleAction(int actionID)
{
    switch (actionID) {
        case quit:
            printf("It is my pleasure to provide service to you, hope to see you soon! Bye!\n");
            break;
        case newExpense:
            printf("I am going to record the new expense, pls wait...\n");
            getNewExpense();
            break;
        case checkToday:
            printf("Your expense of today as follow:\n");
            break;
        case checkMonth:
            printf("Your expense of this month as follow:\n");
            break;
        case checkYear:
            printf("Your expense of this year as follow:\n");
            break;
        case checkHistory:
            printf("Total expense I can remember as follow:\n");
            break;
            
        default:
            printf("system error!");
            //getAction();
            break;
    }
    getchar();
    return;
}

bool checkDayChange()
{
    FILE* dateFile;
    time_t now = time(NULL);
    struct tm *today = localtime(&now);
    
    int todayDate = today->tm_mday;
    int preDate;
    
    if ((dateFile = fopen("/Users/bill/Documents/Program/cProgramming/demoAPP/Accounting/accounting/accounting/Work/date", "r+"))==NULL) {
        printf("system error!\n");
        return false;
    }
    fread(&preDate, sizeof(int), 1, dateFile);
    
    if (todayDate == preDate)
    {
        rewind(dateFile);
        fclose(dateFile);
        return false;
    }
    else
    {
        rewind(dateFile);
        fwrite(&todayDate, sizeof(int), 1, dateFile);
        rewind(dateFile);
        fclose(dateFile);
        printf("Today is a new day!\n");
        //newDay = true;
        return true;
    }
    
}


void resetTodayTotal()
{
    FILE* todayConsume;
    int resetToday = 0;
    if (newDay)
    {
        if ((todayConsume = fopen("/Users/bill/Documents/Program/cProgramming/demoAPP/Accounting/accounting/accounting/Work/totalToday", "r+")) == NULL)
        {
            printf("System error!\n");
            return;
        }
        
        fwrite(&resetToday, sizeof(int), 1, todayConsume);
        fclose(todayConsume);
    }
    return;
    
}

char* getUserName()
{
    char* szUserName;
    szUserName = getenv("USER");
    
    //printf(szUserName);
    return szUserName;
}

void creatDir(void)
{
    struct stat st = {0};
    char * userName;
    
    char  directory[1024] = "/Users/";
    
    //char new_dir[]="/User/bill/Library/Application Support/AccountRobert";
    
    userName = getUserName();
    
   // printf(userName);

    strcat(directory, userName);
    
    strcat(directory, "/Library/Application Support/AccountRobert");
    
    if (stat(directory, &st) == -1)
    {
        
        if(!(mkdir(directory, S_IRWXG)))
            
            
            printf("Creat sucessfully");
            printf(directory);
        
       
    }
    
   // mkdir("/Users/bill/Test", S_IRWXG);
    
   // printf(directory);
    
/*
    if (mkdir(new_dir, S_IRWXU|S_IRGRP|S_IXGRP) != 0)
        perror("mkdir() error");
    else if (chdir(new_dir) != 0)
        perror("first chdir() error");
    else if (chdir("..") != 0)
        perror("second chdir() error");
    else if (rmdir(new_dir) != 0)
        perror("rmdir() error");
    else
        puts("success!");
    
    
    printf("\n");
  */
    return;
}

int getTotalConsume(int expenseThisTime)
{
	int howMuch;
	int totalConsume;
    
	FILE *  storeTotal;
    
	howMuch = expenseThisTime;
    
	if((storeTotal = fopen("/Users/bill/Documents/Program/cProgramming/demoAPP/Accounting/accounting/accounting/Total", "r+")) == NULL)
    {
    	printf("Can not open this file\n");
        
        return -1;
    }
    
    rewind(storeTotal);
	
	fread(&totalConsume, sizeof(int), 1, storeTotal);
    
    printf("Before this expense, the Total Consume is %d", totalConsume);
    printf("\n");
    
    totalConsume += howMuch;
    
    rewind(storeTotal);
    
    fwrite(&totalConsume, sizeof(int), 1, storeTotal);
    
    printf("After this expense, Total Consume is %d\n", totalConsume);
    printf("\n");
    
    rewind(storeTotal);
    
    fclose(storeTotal);
    
    return totalConsume;
}
