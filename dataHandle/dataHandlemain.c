#include "dataHandleinc.h"


int main(int argc, char const *argv[])
{
	/* code */
	char * dataPath;

	dataPath = dataPathCrate(TODAY);

	dataGet(dataPath);
	getchar();
	return 0;
}