/*
OVERVIEW: You are given 2 bank statements that are ordered by date.
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int my_compare(char *a, char *b)
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		if (a[i] != b[i])
		{
			return 0;
		}
	}
	return 1;
}
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {

	if (A == NULL || B == NULL || ALen <= 0 || BLen <= 0)
	{
		return NULL;
	}
	else
	{
		int j = 0, k = 0, l = 0;
		struct transaction f[10];
		for (j = 0; j < ALen; j++)
		{
			for (k = 0; k < BLen; k++)
			{
				if (my_compare(A[j].date, B[k].date))
				{
					f[l] = A[j];
					l++;
					break;
				}
			}
		}
		return l?f:NULL;

	}
	return NULL;
	
}
