// Question15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

const int WIDTH = 20;
const int HEIGHT = 20;

int grid[WIDTH + 1][HEIGHT + 1];

vector<pair<int, int>> queue;


int main()
{
	std::cout << "Project Euler Question 15\n" <<
				 "=========================\n\n";
	//add 0, 0 to queue
	queue.push_back(make_pair(0, 0));

	//for each value in queue
		//if value is destination
			//stop loop and print value

		//if you can go right
			//take ways to get to current position, add it to the right spot.
			//add that position to end of queue, if not already there

		//if you can go down
			//take ways to get to current position, add it to the down spot.
			//add that position to end of queue, if not already there

		//remove currnet cheking from queue
}