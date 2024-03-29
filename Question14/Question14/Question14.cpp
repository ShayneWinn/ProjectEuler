// Question14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
	int MAX = 1000000;
	int MIN = 0;
	long long temp;
	int chainCount = 1;
	int longest = 1;
	long long myNum = 0;

	for (int i = MAX; i > MIN; --i)
	{
		temp = i;
		while (temp != 1)
		{
			if ((temp % 2) == 0)
			{
				temp = temp / 2;
			}
			else
			{
				temp = (temp * 3) + 1;
			}
			++chainCount;
		}

		if (longest < chainCount)
		{
			longest = chainCount;
			myNum = i;
		}
		chainCount = 1;
	}

	std::cout << "The number " << myNum << " has longest chain of " << longest << std::endl;
}