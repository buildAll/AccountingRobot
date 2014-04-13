
#include "accMaininc.h"


void mainDateGet()
{
    dateToday();

    dayPath = dataPathCrate(DATEDAY);
    dateStroeCreate(dayPath,STOREDAY);
    monthPath = dataPathCrate(DATEMONTH);
    dateStroeCreate(monthPath,STOREMONTH);
    yearPath = dataPathCrate(DATEYEAR);
    dateStroeCreate(yearPath,STOREYEAR);
}


void mainDataPrepare()
{
	

	dataPathToday = dataPathCrate(CONSUMETODAY);
    totalToday = dataGet(dataPathToday);
    dataPathMonth = dataPathCrate(CONSUMEMONTH);
    totalMonth = dataGet(dataPathMonth);
    dataPathYear = dataPathCrate(CONSUMEYEAR);
    totalYear = dataGet(dataPathYear);

   // dataPathCrate(path,CONSUMETODAY);
    //dataPathCrate(dataPathToday,TODAY);

   // printf("datapath is %s\n", dataPathToday);
    
    
    
   

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

    //char * dataPathToday;
    
    mmiNewConsume = 0;



	do
    {
    //displayWelcome();

    action = mmiGetAction();
    
    mmiHandleAction(action);

    if(mmiNewConsume > 0)
    {
        dataPathToday = dataPathCrate(CONSUMETODAY);

        totalToday = dataCompute(mmiNewConsume, totalToday);

        dataStore(dataPathToday,totalToday);    
    } 

    
        
        if (action !=0)
        {
            printf("Please any key to continue...\n");
          //  getchar();
           // system("clear");
        }
        
    }while (action !=0);
    
    return;
}

void mainDataHanlde()
{

    //char * dataPathToday;

    

    return; 
}
    