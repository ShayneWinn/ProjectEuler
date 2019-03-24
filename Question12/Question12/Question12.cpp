// Question12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

//Returns Factors of n
std::vector<int> Factors(long int _n)
{
	std::vector<int> _factors;

	_factors.push_back(1);

	for (int i = 2; i < sqrt(_n); i++)
	{
		if (_n % i == 0)
		{
			_factors.push_back(i);
			_factors.push_back(_n / i);
		}
	}

	if (sqrt(_n) - int(sqrt(_n)) == 0)
	{
		_factors.push_back(sqrt(_n));
	}

	_factors.push_back(_n);

	return _factors;
}


void WriteAnswer(std::string _answer)
{
	std::cout << "\n\n";

	std::cout << "+";
	for (int i = 0; i < _answer.length() + 2; i++)
		std::cout << "-";
	std::cout << "+\n";

	std::cout << "| " + _answer + " |\n";

	std::cout << "+";
	for (int i = 0; i < _answer.length() + 2; i++)
		std::cout << "-";
	std::cout << "+\n";
}


void PrintFactors(long _n)
{
	std::vector<int> _factors;
	int _numFactors;

	_factors = Factors(_n);
	_numFactors = _factors.size();

	std::cout << "\n\n";
	for (int i = 0; i < _numFactors; i++)
	{
		std::cout << std::to_string(_factors[i]) + ", ";
	}

	std::cout << "\nTOTAL FACTORS: " + std::to_string(_numFactors);

	std::cout << "\n\n";
}


int main()
{
	std::cout << "Project Euler Question 12\n\n";

	long int _currentTri = 1;
	long int _currentNat = 1;

	std::vector<int> _factors;
	int _numFactors;

	while (1)
	{
		//count factors of Tri

		_factors = Factors(_currentTri);
		_numFactors = _factors.size();

		//See if over 500, if so, break
		if (_numFactors > 500)
		{
			break;
		}
		//If not, increase nat and add it to tri
		else
		{
			_currentNat++;
			_currentTri += _currentNat;

			if (_currentNat % 1000 == 0)
				std::cout << ".";

		}

		//Repeate
	}

	PrintFactors(_currentTri);
	WriteAnswer(std::to_string(_currentTri));

}