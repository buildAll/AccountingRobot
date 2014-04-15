//History:
//2014-04-15: Add menu display after the 


#include "accMaininc.h"


void mainDateGet()
{


    dateToday();

    dataPathCreate(dayPath,DATEDAY);
    dataPathCreate(monthPath,DATEMONTH);
    dataPathCreate(yearPath,DATEYEAR);
//    dayPath = dataPathCrate(DATEDAY)
    dateStroeCreate(dayPath,STOREDAY);
    dateGetPrevious(dayPath,STOREDAY);

 //   monthPath = dataPathCrate(DATEMONTH);
    dateStroeCreate(monthPath,STOREMONTH);
    dateGetPrevious(monthPath,STOREMONTH);

 //   yearPath = dataPathCrate(DATEYEAR);
    dateStroeCreate(yearPath,STOREYEAR);
    dateGetPrevious(yearPath,STOREYEAR);

    //printf("%d\n",oldDay);
    //printf("%d\n",oldMonth);
    //printf("%d\n",oldYear);


}

void mainDateChangeHandle()
{
    
    float reset = 0;

    if(dateCheckChange(oldDay,todayDay))
    {
        /*
              1. add totalToday to totalMonth;(totalMonth = totalToday + totalMonth)
              2. reset totalToday = 0;
        */
        /*
        dataReset(dataPathToday,dataPathMonth);
        totalMonth = dataGet(dataPathMonth);
        dataStore(dataPathYear, totalMonth);
        dataStore(dataPathHistory, totalMonth);
        */

        dataStore(dataPathToday,reset);    
        totalToday = dataGet(dataPathToday);
        dateUpdate(dayPath,todayDay);
            if(dateCheckChange(oldMonth,todayMonth))
            {
                /*
                      1. add totalMonth to totalYear;(totalYear = totalMonth + totalYear)
                      2. reset totalMonth = 0;
                       
               
                 dataReset(dataPathMonth,dataPathYear);  
                 totalYear = dataGet(dataPathYear);
                 dataStore(dataPathHistory, totalHistory);
                 */ 


                 dataStore(dataPathMonth,reset);  
                 
                    //dataPathMonth = dataPathCrate(CONSUMEMONTH);
                    totalMonth = dataGet(dataPathMonth);
                    //dataPathYear = dataPathCrate(CONSUMEYEAR);
                    dateUpdate(monthPath,todayMonth);
                   if(dateCheckChange(oldYear,todayYear))
                    {
                        /*
                              1. add totalYear to totalHistory;(totalYear = totalMonth + totalYear)
                              2. reset totalYear = 0;
                               
                        */

                          dataStore(dataPathYear,reset);  
                          totalYear = dataGet(dataPathYear);
                          dateUpdate(yearPath,todayYear);
                         //dataReset(dataPathYear,dataPathHistory);     
                    } 
            }

        
    }

   

   
    return;
}


void mainDataPrepare()
{
	
    dataPathCreate(dataPathToday,CONSUMETODAY);

    dataPathCreate(dataPathMonth,CONSUMEMONTH);

    dataPathCreate(dataPathYear,CONSUMEYEAR);

    dataPathCreate(dataPathHistory,CONSUMEHISTORY);


    //dataPathToday = dataPathCrate(CONSUMETODAY);
    totalToday = dataGet(dataPathToday);
    //dataPathMonth = dataPathCrate(CONSUMEMONTH);
    totalMonth = dataGet(dataPathMonth);
    //dataPathYear = dataPathCrate(CONSUMEYEAR);
    totalYear = dataGet(dataPathYear);

    totalHistory = dataGet(dataPathHistory);

   // dataPathCrate(path,CONSUMETODAY);
    //dataPathCrate(dataPathToday,TODAY);

   // printf("datapath is %s\n", dataPathToday);
    
    
    
   

    return;
}


void mainWelcome()
{
	displayBounderay(BOUNDERAYTPYE);
	displayWelcome();
	//displayExpense(TODAY,totalToday);
	displayExpense(MONTH,totalMonth);
    //displayExpense(YEAR,totalYear);
    //displayExpense(HISTORY,totalHistory);
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
       // dataPathToday = dataPathCrate(CONSUMETODAY);

        totalToday = dataCompute(mmiNewConsume, totalToday);
        dataStore(dataPathToday,totalToday); 

        totalMonth = dataCompute(mmiNewConsume,totalMonth);
        dataStore(dataPathMonth,totalMonth);

        totalYear = dataCompute(mmiNewConsume,totalYear);
        dataStore(dataPathYear,totalYear);

        totalHistory = dataCompute(mmiNewConsume,totalHistory);

        dataStore(dataPathHistory,totalHistory);     
    } 

    
        
        if (action !=0)
        {
            //printf("Please any key to continue...\n");
          //  getchar();
           // system("clear");
          displayMenu();
        }
        
    }while (action !=0);

    
    
    return;
}

void mainDataHanlde()
{

    //char * dataPathToday;

    

    return; 
}
    