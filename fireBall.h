#pragma once

class spaceShip;
class starShip;
class martianShip;
class rocket;

class fireBall
{
private:
	int no_of_balls;
public:
	fireBall()
	{
		no_of_balls = 0;
	}
	fireBall(int b)
	{
		no_of_balls = b;
	}
};
