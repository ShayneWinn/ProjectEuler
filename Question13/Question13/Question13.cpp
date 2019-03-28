// Question13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>>

using namespace std;
vector<string> NUMBERS
{
	"149",
	"826",
	"453",
	"823",
	"836",
	"139",
	"999",
	"472",
	"183",
	"423",
	"759"
};


int main()
{
	std::cout << "Project Euler Question 13";
	cout << "\n\n";

	vector<int> _answer;

	int _rem = 0;
	int _tempsum;

	string _tempstr;

	//Loops
	for (int i = NUMBERS[0].length() - 1; i >= 0; i--)
	{
		//Every new column
		_tempsum = _rem;

		for (int j = 0; j < NUMBERS.size(); j++)
		{
			//Every Number down list
			_tempsum += NUMBERS[j][i];
			
			cout << NUMBERS[j][i] << " + ";
		}
			cout << " = " << _tempsum;

		//Add last digit to beggining of _answer
		_tempstr = to_string(_tempsum);
			cout << " = " << _tempstr.back();
		_answer.push_back(_tempstr.back());

		//Remove last didgit
		_tempstr.erase(_tempstr.size() - 1);

		//Set _rem as what's left
		_rem = stoi(_tempstr);
			cout << " + " << _tempstr;
			cout << "\n\n";
	}

	for (int i = _answer.size() - 1; i >= 0; i--)
	{
		cout << _answer[i];
	}

	cout << "\n\n";

}
