//
//  displayinc.c
//  
//
//  Created by bill on 4/11/14.
//  Copyright (c) 2014 buildAll. All rights reserved.
// 
//  History:
//  2014-04-15: Add new marco WELCOME to the welcome screen.

//#ifndef accounting_displayinc_h
//#define accounting_displayinc_h
//#endif



//#include <stdlib.h>



#define WELCOME "HELLO, I am Accounting Robot."
#define BOUNDERAYTPYE "*********************************"
#define TODAY "today"
#define MONTH "this month"
#define YEAR "this year"
#define HISTORY "totally"




void displayWelcome(void);

void displayExpense(char* period,float consume);

void displayBounderay(char *displayBounderayType);

void displayMenu(void);


