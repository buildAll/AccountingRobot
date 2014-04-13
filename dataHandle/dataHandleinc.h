//
//  dataHandleinc.h
//  accounting
//
//  Created by bill on 4/11/14.
//  Copyright (c) 2014 buildAll. All rights reserved.
//

#ifndef dataHandleinc_h
#define dataHandleinc_h
#endif
//#include <limits.h>

#define CONSUMETODAY "/totalToday"
#define CONSUMEMONTH "/totalMonth"
#define CONSUMEYEAR  "/totalYear"
#define CONSUMEHISTORY "/totalHistory"
#define DATEDAY "/dateToday"
#define DATEMONTH "/dateMonth"
#define DATEYEAR "/dateYear"


//char* dataPathCrate(char * os);

char* dataPathCrate(char *type);
//void dataPathCrate(char* path,char* type);

float dataGet(char* path);

float dataCompute(float newConsume, float totalConsume);

void dataStore(char *path, float content);

char* dataUserName(void);

void dateGetPrevious(char *path,int type);

void dataReset(char* originalPath,char* objectPath);


void dataPathCreate(char* path,char*type);




/*More function will be added.....
 
 dataDelete
 dataReset

 
*/



