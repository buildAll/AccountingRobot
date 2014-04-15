//
//  dataHandleinc.h
//  accounting
//
//  Created by bill on 4/11/14.
//  Copyright (c) 2014 buildAll. All rights reserved.
//
// History:
// 2014-04-15: Add the pre-define to check the OS for the App data path.

#ifndef dataHandleinc_h
#define dataHandleinc_h
#endif
//#include <limits.h>


#ifdef _WIN64
  // const char* os = "Windoze64";
   #define APPDIRECTORY "\\AppData\\Roaming\\AccountingRobot"
#elif _WIN32
   //const char* os = "Windoze32";
   #define APPDIRECTORY "\\AppData\\Roaming\\AccountingRobot"
#elif __APPLE__
    #include "TargetConditionals.h"
    #if TARGET_IPHONE_SIMULATOR
         // iOS Simulator
    #elif TARGET_OS_IPHONE
        // iOS device
    #elif TARGET_OS_MAC
     //   const char* os = "MACOS";
      #define APPDIRECTORY  "/Library/Application Support/AccountingRobot"
    #else
        // Unsupported platform
    #endif
#elif __linux
    // linux
#elif __unix // all unices not caught above
    // Unix
#elif __posix
    // POSIX
#endif



#define CONSUMETODAY "/totalToday"
#define CONSUMEMONTH "/totalMonth"
#define CONSUMEYEAR  "/totalYear"
#define CONSUMEHISTORY "/totalHistory"
#define DATEDAY "/dateToday"
#define DATEMONTH "/dateMonth"
#define DATEYEAR "/dateYear"


//char* dataPathCrate(char * os);

//char* dataPathCrate(char *type);
//void dataPathCrate(char* path,char* type);

float dataGet(char* path);

float dataCompute(float newConsume, float totalConsume);

void dataStore(char *path, float content);

char* dataUserName(void);

void dateGetPrevious(char *path,int type);

void dataReset(char* originalPath,char* objectPath);


void dataPathCreate(char* path,char*type);

char* dataGetHome(void);




/*More function will be added.....
 
 dataDelete
 dataReset

 
*/



