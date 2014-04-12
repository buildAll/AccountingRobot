//
//  displayinc.c
//  
//
//  Created by bill on 4/11/14.
//  Copyright (c) 2014 buildAll. All rights reserved.
//

#ifndef accounting_displayinc_h
#define accounting_displayinc_h
#endif



//#include <stdlib.h>



#if(1)
#define BOUNDERAYTPYE "*********************************"
#define TODAY "today"
#define MONTH "this month"
#define YEAR "this year"
#endif



void displayWelcome(void);

void displayExpense(char* period,float consume);

void displayBounderay(char *displayBounderayType);

void displayMenu(void);


