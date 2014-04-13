#include "dataHandleinc.h"
#include "displayinc.h"
#include "mmiinc.h"
#include "dateCenterinc.h"


/*gloabl data*/
float totalToday;
float totalMonth;
float totalYear;
float totalHistory;

char dataPathToday[1024];
char dataPathMonth[1024];
char dataPathYear[1024];
char dataPathHistory[1024];

char dayPath[1024];
char monthPath[1024];
char yearPath[1024];
char historyPath[1024];


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

void mainDateChangeHandle(void);


