
#include "functions.h"

void arraySort(char** arr, int size) //Sorts an array of strings in lexicographical order using bubble sort.
{
	int i, j;
	for (i = 1; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (strcmp(arr[j], arr[j+1]) > 0)
			{
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}

void swap(char** str1, char** str2) //Swaps two pointers of strings
{
	char* temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

void newFileName(char* str, int size1, char* newStr) //Constructs a new filename based on an input filename
{
	strcpy(newStr, str);
	newStr[size1 - 4] = '\0';
	strcat(newStr, ".srt.txt");
}

void freeStrings(char** arrOfStrings, int size) //Free the strings in the array one by one
{
	int i;
	for (i = 0; i < size; i++)
	{
		free(arrOfStrings[i]);
	}
}

void checkSuccessOfFileOpen(FILE* fp) // Checks if the file opened successfully
{
	if (fp == NULL)
	{
		printf("Failed to open file!");
		exit(1);
	}
}


void checkAllocation(void* ptr) // Checks if the memory allocated successfully
{
	if (ptr == NULL) {
		printf("Allocation error\n");
		exit(-1);
	}
}

