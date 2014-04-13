#include "dataHandleinc.h"
#include "displayinc.h"
#include "mmiinc.h"
#include "dateCenterinc.h"


/*gloabl data*/
float totalToday;
float totalMonth;
float totalYear;
float totaHistory;

char* dataPathToday;
char* dataPathMonth;
char* dataPathYear;
char* dayPath;
char* monthPath;
char* yearPath;


//char path[1024] = {'\0'};




/*data*/

#if(0)
struct Expense
{
	/* data */
    char* dateExpense;   //the date of the expense be made
	float moneyExpense;    //how much for this expense
	char* gainExpense;   //what be gained from the expense
};

struct Expense firstEx;
#endif


/*function*/

void mainDataPrepare(void);

void mainWelcome(void);

void mainMmi(void);

void mainDataHanlde(void);

void mainDateGet(void);


