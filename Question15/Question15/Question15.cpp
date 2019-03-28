// Question15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <queue>


struct vector2D
{
	int x, y;

	vector2D(int _x, int _y)
	{
		this->x = _x;
		this->y = _y;
	}
};


const int WIDTH = 2;
const int HEIGHT = 2;

int grid[WIDTH + 1][HEIGHT + 1];

std::vector<vector2D> queue;


void AddToQueue(vector2D _vector)
{
	bool willAdd = true;
	for (int i = 0; i < queue.size(); i++)
	{
		if (_vector.x == queue[i].x && _vector.y == queue[i].y)
		{
			willAdd = false;
		}
	}

	if (willAdd)
		queue.push_back(_vector);
}


void RunQuestion()
{
	std::cout << "Project Euler Question 15\n" <<
		"=========================\n\n";
	//set 0, 0 to 1
	grid[0][0] = 1;
	//add 0, 0 to queue
	queue.push_back(vector2D(0, 0));


	int _x, _y;
	//for each value in queue
	while (queue.size() > 0)
	{
		_x = queue.front().x;
		_y = queue.front().y;
		//if location is destination
		if (_x == WIDTH + 1 && _y == HEIGHT + 1)
		{
			//stop loop and print value
			std::cout << grid[_x][_y];
			break;
		}

		try
		{
			//take ways to get to current position, add it to the right spot.
			grid[_x + 1][_y] += grid[_x][_y];
			//add that position to end of queue, if not already there
			AddToQueue(vector2D(_x + 1, _y));
		}
		catch (const std::exception e) {};

		//if you can go right
		try
		{
			//take ways to get to current position, add it to the right spot.
			grid[_x][_y + 1] += grid[_x][_y];
			//add that position to end of queue, if not already there
			AddToQueue(vector2D(_x, _y + 1));
		}
		catch (const std::exception e) {};

		//remove currnet cheking from queue
		queue.erase(queue.begin());
	}
}


int main()
{
	AddToQueue(vector2D(0, 0));
	for (int i = 0; i < queue.size(); i++)
	{
		std::cout << "(" << queue[i].x << ", " << queue[i].y << "), ";
	}
	std::cout << "\n";

	AddToQueue(vector2D(1, 2));

	AddToQueue(vector2D(2, 2));

	for (int i = 0; i < queue.size(); i++)
	{
		std::cout << "(" << queue[i].x << ", " << queue[i].y << "), ";
	}
	std::cout << "\n";

	AddToQueue(vector2D(0, 0));

	AddToQueue(vector2D(2, 2));

	AddToQueue(vector2D(3, 3));

	for (int i = 0; i < queue.size(); i++)
	{
		std::cout << "(" << queue[i].x << ", " << queue[i].y << "), ";
	}
	std::cout << "\n";
}