//
//  displaymain.c
//  
//
//  Created by bill on 4/11/14.
//  Copyright (c) 2014 buildAll. All rights reserved.
//

#include "displayinc.h"
void main(void)
{
	displayBounderay(BOUNDERAYTPYE);
	displayWelcome();
	displayExpense(TODAY,11);
	displayExpense(MONTH,12);
	displayBounderay(BOUNDERAYTPYE);
	displayMenu();
    
	getchar();

	return;
}