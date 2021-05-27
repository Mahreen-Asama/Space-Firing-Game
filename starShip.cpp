#include "starShip.h"
#include<windows.h> 
HANDLE consol = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CP;

void starShip::maindraw()								//screen#2			
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++) cout << "\t";
		if (i == 0)cout << "  \\     / " << endl;
		if (i == 1) cout << "   ***** \n";
	}
}

void starShip::draw(int rx, int ry, int& ch2)				//overriden method
{														//ch2 from rocket class, checking consectivity of fires from ship							
	int temp = y;
	CP.X = x;											//x,y of base-class
	for (int i = 0; i < 2; i++)
	{
		CP.Y = y;
		SetConsoleCursorPosition(consol, CP);
		if ((this->scor == 3) && (rx >= this->x && rx < this->x + 30))
		{
			ch2 = 0;
			cout << "fired";
			score = score + 5;
			this->scor = 0;
			break;
		}
		else
		{
			if (i == 0)cout << "  \\     / ";
			if (i == 1) cout << "   *****";
			y++;
		}
	}
	x = x + 30;
	y = temp;
}

void starShip::setScore()			//individual scores of starShip=5
{
	this->scor++;
}

int& starShip::gets()				//getting individual scores
{
	return scor;
}

int starShip::fire()
{
	if (balls != 0)
	{
		f[balls - 1] = 0;			//decremet size of array from end
		balls--;

	}
	return balls;
}

void starShip::move()				// moves the ship vertically from top to down
{
	y++;
	if (y > 20) y = 2;
}
void starShip::setxy(int p, int q)
{
	x = p, y = q;
}

int starShip::getx()
{
	return x;
}
int starShip::gety()
{
	return y;
}
void starShip::resetx()				//to move downward properly 
{
	x = 0;
}
void starShip::resety()
{
	y = y - 4;						//reset & also move downward
}


