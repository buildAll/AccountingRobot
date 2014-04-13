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


#include "accMaininc.h"




int main(void)
{
    

    
    
    
  /*  
    newDay = false;
    
    newDay = checkDayChange();
    
    resetTodayTotal();
    
  */  
   
    mainDataPrepare();

    mainDateGet();

    mainDateChangeHandle();
    
    



    mainWelcome();

    mainMmi();

  //  mainDateChangeHandle();

    //mainDataHanlde();
    
    //getchar(); 
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