#pragma once
#include"spaceShip.h"
#include"fireBall.h"

class starShip :public spaceShip
{
	friend void restartGame(rocket&, starShip&, martianShip&);
	friend void playAgain(rocket&, starShip&, martianShip&);
private:
	int scor;
public:
	starShip()
	{
		scor = 0;
		for (int i = 0; i < 50; i++)
			f[i] = 1;
	}
	void maindraw();
	void draw(int, int, int&);		//overriden method
	void setScore();				//individual scores=5
	int& gets();
	int fire();						//returns remainig balls
	int getx();
	int gety();
	void move();					//move ship downward
	void setxy(int, int);
	void resetx();
	void resety();
};

