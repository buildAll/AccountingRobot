
#include <time.h>
#include <stdbool.h>

#define STOREDAY         0
#define	STOREMONTH       1 
#define STOREYEAR       2


int todayDay;
int todayMonth;
int todayYear;

int oldDay;
int oldMonth;
int oldYear;

void dateToday(void); 

void dateStroeCreate(char *path, int tpye);

void dateUpdate(char *path, int newDate);


int dataGetDate(char* path);

bool dateCheckChange(int newDate, int oldDate);