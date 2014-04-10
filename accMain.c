//
//  main.c
//  accounting
//
//  Created by bill on 4/5/14.
//  Copyright (c) 2014 buildAll. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "accHead.h"




int main(void)
{
    
    int actionID = -1;
    
    creatDir();
    
   // printf(directory);
   // printf("\n");
    
    
    
    newDay = false;
    
    newDay = checkDayChange();
    
    resetTodayTotal();
    
    
    
    
    do
    {
    displayWelcome();

    actionID = getAction();
    
    handleAction(actionID);
        
        if (actionID !=0)
        {
            printf("Please any key to continue...\n");
            getchar();
            system("clear");
        }
        
    }while (actionID !=0);
 /*
    if (checkDayChange()) {
        printf("Today is a new day!");
    }
    else
    {
        printf("Today is not passed");
    }
 */
  /*
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    printf( "%d\n", t->tm_mon+1 );
    printf( "%d\n", t->tm_mday );
    printf( "%d\n", t->tm_year+1900 );
    printf( "%d\n", t->tm_hour );
    printf( "%d\n", t->tm_min );
    printf( "%d\n", t->tm_sec );
    */
   // printf("hello world!\n");
	//printf("please enter the money you spend:\n");
	//scanf("%d",&firstEx.moneyExpense);
	//printf("You have paid %d\n",firstEx.moneyExpense);
    

    
    //getTotalConsume(firstEx.moneyExpense);
    
    
    /* Obtain current time as seconds elapsed since the Epoch. */
   
    
    //firstEx.dateExpense = c_time_string;
    
    
    
  

    
    
	return 0;
}