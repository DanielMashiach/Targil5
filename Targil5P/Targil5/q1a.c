//ID: 211817184 Name: Daniel Mashiach
//This program reads lowercase alphabetic character sequences from a binary file,
//sorts them, and writes them to a new text file with a modified filename

#include "functions.h"

void main(int argc, char* argv[])
{
	int i, j;
	int currNum;
	char* str;
	char* newFile;
	char ch;
	int numOfStrings = atoi(argv[2]);

	FILE* f = fopen(argv[1], "rb");
	checkSuccessOfFileOpen(f);

	char** arrOfStrings = (char**)malloc(sizeof(char*) * numOfStrings);
	checkAllocation(arrOfStrings);


	for (i = 0; i < numOfStrings; i++)
	{
		j = 0;
		fread(&currNum, sizeof(int), 1, f);
		str = (char*)malloc(sizeof(char) * (currNum)); 
		checkAllocation(str);

		while(currNum != 0)
		{
			fread(&ch, sizeof(char), 1, f);
			if (ch >= 'a' && ch <= 'z')
			{
				str[j] = ch;
				j++;
			}
			currNum--;
		}	
		str[j] = '\0';
		str = (char*)realloc(str, sizeof(char) * (j+1));
		checkAllocation(str);
		arrOfStrings[i] = str;
	}

	arraySort(arrOfStrings, numOfStrings);



	fclose(f);

	newFile = (char*)malloc(sizeof(char) * (strlen(argv[1]) + 4));
	checkAllocation(newFile);

	newFileName(argv[1], strlen(argv[1]), newFile);

	f = fopen(newFile, "wt");
	checkSuccessOfFileOpen(f);


	for (i = 0; i < numOfStrings; i++)
	{
		fprintf(f, "%s\n", arrOfStrings[i]);
	}

	fclose(f);

	freeStrings(arrOfStrings, numOfStrings);
	free(arrOfStrings);
}


