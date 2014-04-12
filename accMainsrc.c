    
#include "accMaininc.h"



void mainDataPrepare()
{
	char * dataPathToday;

	dataPathToday = dataPathCrate(CONSUMETODAY);
   // dataPathCrate(path,CONSUMETODAY);
    //dataPathCrate(dataPathToday,TODAY);

    printf("datapath is %s\n", dataPathToday);
    
    totalToday = dataGet(dataPathToday);
    
    return;
}


void mainWelcome()
{
	displayBounderay(BOUNDERAYTPYE);
	displayWelcome();
	displayExpense(TODAY,totalToday);
	displayExpense(MONTH,totalMonth);
	displayBounderay(BOUNDERAYTPYE);
	displayMenu();
	return;
}

void mainMmi()
{
	int  action = -1;

	do
    {
    //displayWelcome();

    action = mmiGetAction();
    
    mmiHandleAction(action);
        
        if (action !=0)
        {
            printf("Please any key to continue...\n");
          //  getchar();
           // system("clear");
        }
        
    }while (action !=0);
    
    return;
}
    