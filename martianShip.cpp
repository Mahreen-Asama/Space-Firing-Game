#include "martianShip.h"

#include<windows.h> 
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);				//console,cursor position are objects...so keep thrie different names in different file
COORD CursorPosition;
#include"spaceShip.cpp"
void martianShip::maindraw()						//on screen#2
{

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) cout << "\t";
		if (i == 0)cout << "***       ***\n";
		if (i == 1)cout << "   \\     /\n";
		if (i == 2)cout << "    \\   /\n";
		if (i == 3)cout << "     ***\n";
	}
}
void martianShip::draw(int rx, int ry, int& ch2)		//overriden method
{													//ch2 from rocket class, checking consectivity of fires from ship	
	int temp = y;									//x,y of base class
	CursorPosition.X = x;
	for (int i = 0; i < 4; i++)
	{
		CursorPosition.Y = y;
		SetConsoleCursorPosition(console, CursorPosition);
		if ((this->scor == 5) && (rx >= this->x && rx < this->x + 30))
		{
			ch2 = 0;
			cout << "FIRED";
			score = score + 10;
			this->scor = 0;
			break;
		}
		else
		{
			if (i == 0)cout << "***       ***";
			if (i == 1)cout << "   \\     /";
			if (i == 2)cout << "    \\   /";
			if (i == 3)cout << "     ***";
			y++;
		}
	}
	x = x + 30;
	y = temp;
}
int martianShip::fire()
{
	if (balls != 0)
	{
		f[balls - 1] = 0;					//decremet size of array from end
		balls--;

	}
	return balls;
}
void martianShip::move()					// moves the ship vertically from top to down
{
	y++;
	if (y > 20) y = 2;
}
void martianShip::setScore()				//individual scores of ship
{
	this->scor++;
}
int& martianShip::gets()
{
	return scor;
}
void martianShip::setxy(int p, int q)		//set position on screen
{
	x = p, y = q;
}
int martianShip::getx()
{
	return x;
}
int martianShip::gety()
{
	return y;
}
void martianShip::resetx()					//to move downward properly
{
	x = 0;
}
void martianShip::resety()
{
	y = y - 4;								//reset & also move downward
}

