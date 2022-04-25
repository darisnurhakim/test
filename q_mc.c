//q_mc.cpp linked with 3_var
//having the implementaion of the functions in header file q_mc.h 

#include <string.h>
#include "q_mc.h"

int mycomp(const void *p1, const void *p2)
{
	const int *ptr1 = (const int *)p1;
	const int *ptr2 = (const int *)p2;

	if (*ptr1 < *ptr2)
		return -1;
	else if (*ptr1 == *ptr2)
		return 0;
	else
		return 1;
}
char *ConvertToBinary(int num, char *bin)
{
	int i;
	int mask = 1;
	int size = BINSIZE;

	for (i = size - 1; i >= 0; i--, num >>= 1)
		bin[i] = (mask & num) + '0';

	bin[size] = '\0';
	
	return bin;
}
int CompareTerms(const char *ar1, const char *ar2, int size)
{
	int i;
	int count = 0;
	int temp;
	for (i = 0; i < size; i++)
	{
		if (ar1[i] != ar2[i])
		{
			temp = i;
			count++;
		}
		else
			continue;
	}

	return (count == 1) ? temp : -1;
}
int EatReapetedTerms(char list[MAX_IMP][ROWSIZE], char new_list[MAX_IMP][ROWSIZE], int row)
{
	char list2[MAX_IMP][ROWSIZE] = {""};
	int top, seek, i, k = 0, j = 0;

	for (top = 0, i = 0; top < row-1; top++, i++)
	{
		for (seek = top + 1; seek < row; seek++)
		{
			if (strcmp(list[top], list[seek]) == 0)
				strcpy(list[seek], "");
		}
	}

	for (j = 0; j < row; j++)
	{
		if (strcmp(list[j], "") == 0)
			continue;
		else
			strcpy(new_list[k++], list[j]);
	}

	return k;	
}
