#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void checkAllocation(void* ptr);

void arraySort(char** arr, int size);

void swap(char** str1, char** str2); 

void newFileName(char* str, int size1, char* newStr);

void freeStrings(char** arrOfStrings, int size);

void checkSuccessOfFileOpen(FILE* fp);
