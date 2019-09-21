// Prob40_ChampernownesConstant.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>


int getdigitcount(unsigned long long n)
{
	if (n >= 1000000)
	{
		return 7;
	}
	else if (n >= 100000)
	{
		return 6;
	}
	else if (n >= 10000)
	{
		return 5;
	}
	else if (n >= 1000)
	{
		return 4;
	}
	else if (n >= 100)
	{
		return 3;
	}
	else if (n >= 10)
	{
		return 2;
	}
	else
		return 1;
}

int getnthdigit(unsigned long long x, int n)
{
	int i,temp = 0,digits;
	digits = getdigitcount(x);
	for (i = 0; i < digits - n + 1; i++)
	{
		temp = x % 10;
		x = x / 10;
	}
	return temp;
}

int main()
{
	unsigned long long int n = 1, product = 1, totaldigitcount = 0, targetcount = 1, digitcount, x;
	while (targetcount <= 1000000)
	{
		digitcount = getdigitcount(n);
		totaldigitcount += digitcount;
		if (totaldigitcount >= targetcount)
		{
			//disregard one
			if (n != 1)
			{
				//x = getnthdigit(n, digitcount - (totaldigitcount - targetcount));
				//printf("*----> %d", x);
				product *= getnthdigit(n, digitcount - (totaldigitcount - targetcount));
			}
			targetcount *= 10;
		}
		
		n++;
	}
	printf("\n\n%d", product);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
