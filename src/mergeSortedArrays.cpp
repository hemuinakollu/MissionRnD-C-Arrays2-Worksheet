/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int date_compare(char a[], char b[])
{
	int sum1 = 0, sum2 = 0;
	for (int i = 5; i < 10; i++)
	{
		sum1 = sum1 * 10;
		sum1 = sum1 + (int)a[i];
		sum2 = sum2 * 10;
		sum2 = sum2 + (int)b[i];
	}
	if (sum1 < sum2)
		return 1;
	else if (sum1 > sum2)
		return 2;
	else
		return 3;

}
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL || ALen <= 0 || BLen <= 0)
	{
		return NULL;
	}
	else
	{
		struct transaction final1[20];
		int i = 0, j = 0, k = 0,c=0;
		while (i < ALen && j < BLen)
		{
			c=date_compare(A[i].date, B[j].date);
			if (c == 1)
			{
				final1[k] = A[i];
				k++;
				i++;
			}
			else if (c == 2)
			{
				final1[k] = B[j];
				k++;
				j++;
			}
			else
			{
				final1[k] = A[i];
				k++;
				final1[k] = B[j];
				k++;
				i++;
				j++;
			}
		}
		while (i<ALen)
		{
			final1[k] = A[i];
			k++;
			i++;
		}
		while (j < BLen)
		{
			final1[k] = B[j];
			k++;
			j++;
		}
		return final1;
	}
	


}