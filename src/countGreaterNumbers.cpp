/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include<iostream>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int mycompare(char *a, char *b)
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
int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	if (Arr == NULL || len <= 0)
		return NULL;
	else
	{
		int j = 0, k = -1;
		for (j = 0; j < len; j++)
		{
			if (mycompare(Arr[j].date, date))
			{
				k = j;
			}
		}
		if (k != -1)
			return len - k - 1;
		else
			return 0;
	}
	
}
