// Printing brackets in Matrix Chain Multiplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

void printParanthesis(int i, int j, int n,
	int *bracket, char &name)
{
	if (i == j)
	{
		cout << name++;
		return;
	}

	cout << "(";

	printParanthesis(i, *((bracket + i * n) + j),
		n, bracket, name);

	printParanthesis(*((bracket + i * n) + j) + 1, j,
		n, bracket, name);

	cout << ")";

}

void matrixChainOrder(int p[], int n)
{
	int m[n][n];

	int bracket[n][n];

	for (int i = 1; i < n; i++)
		m[i][i] = 0;

	for (int L = 2; L < n; L++)
	{
		for (int i = 1; i < n - L + 1; i++)
		{
			int j = i + L - 1;
			m[i][j] = INT_MAX;
			for (int k = i; k <= j - 1; k++)
			{
				int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j])
				{
					m[i][j] = q;

					bracket[i][j] = k;
				}
			}
		}
	}
	char name = 'A';

	cout << "Optimal Parenthesization is : ";
	printParanthesis(1, n - 1, n, (int *)bracket, name);
	cout << "nOptimal Cost is : " << m[1][n - 1];
}



int main()
{
	int arr[] = { 40, 20, 30, 10, 30 };
	int n = sizeof(arr) / sizeof(arr[0]);
	matrixChainOrder(arr, n);

    return 0;
}

