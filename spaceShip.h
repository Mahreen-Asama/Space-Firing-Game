#pragma once
#include"fireBall.h"
#include<iostream>
using namespace std;
class spaceShip
{
protected:
	static int x, y;					//location of spaceship on screen, static members not copy for derive class  
	fireBall f[100];
	static int balls;
public:
	static int score;					//final scores of player
	spaceShip()
	{
		x = 0, y = 2;
	}
	spaceShip(int a, int b)
	{
		x = a, y = b;
	}

	virtual void draw(int, int, int&) = 0;
	virtual int fire() = 0;					//fire from enemy at random intervals
	virtual void setxy(int p, int q) = 0;
	virtual int getx() = 0;
	virtual int gety() = 0;
	virtual void resetx() = 0;
	virtual void resety() = 0;
	virtual void move() = 0;
	~spaceShip()
	{

	}
};

