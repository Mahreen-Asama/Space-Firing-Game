#pragma once
#include"fireBall.h"
#include<iostream>
using namespace std;

class rocket
{
	friend void restartGame(rocket&, starShip&, martianShip&);
	friend void playAgain(rocket&, starShip&, martianShip&);
private:
	int chances[3];						//chances to survive of player in consective 3 fires from ship 
	int lives;
	int x, y;							//rocket location x,y
	fireBall f[100];					//100 are present to fire, if player wastes balls, then it's life may lost 
	static int ball;					//check remaining balls
public:
	static int ch1, ch2;
	rocket()
	{
		x = 0, y = 0;
		lives = 3;						//three lives of player, in each life 3 chances to survive...
		for (int i = 0; i < 100; i++)
			f[i] = 1;
		for (int i = 0; i < 3; i++)
			chances[i] = 1;
	}
	void maindraw();							//big rocket,1st screen
	void setxy(int, int);
	void draw();
	void move(int);								//4 sides movement of rocket
	void fire(char, int&, int&);					//keeps check of remaining fire_balls
	int remainBall();
	int getx();
	int gety();
	int getlives();
	void setChances(int);
	int getChances(int);
	int& returnch2();
};

