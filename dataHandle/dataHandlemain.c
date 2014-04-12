#include "dataHandleinc.h"


int main(int argc, char const *argv[])
{
	/* code */
	char dataPath[1024];

	float testDataCompute = 238.5;

	float testDataGet = 0;

	float total = 0;


	dataPath = dataPathCrate(TODAY);
    
    testDataGet = dataGet(dataPath);
    
    total =dataCompute(testDataGet, testDataCompute);

    dataStore(dataPath,total);


	getchar();
	return 0;
}