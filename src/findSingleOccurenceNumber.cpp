/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/

#include<iostream>
int findSingleOccurenceNumber(int *A, int len) {
	if (len <= 0 || A == NULL)
		return -1;
	else{
		int i = 0, j = 0;
		for (i = 0; i < len - 1; i++)
		{
			for (j = 0; j < len - i - 1; j++)
			{
				if (A[j]>A[j + 1])
				{
					A[j] = A[j] + A[j + 1];
					A[j + 1] = A[j] - A[j + 1];
					A[j] = A[j] - A[j + 1];
				}
			}
		}
		for (i = 0; i < len - 1; i = i + 3)
		{
			if (A[i] != A[i + 1])
				return A[i];
		}
		return A[i];
	}

}

