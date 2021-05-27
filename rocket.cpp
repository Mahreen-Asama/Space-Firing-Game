#include "rocket.h"
#include<windows.h> 

HANDLE consl = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CPo;

void rocket::maindraw()
{
	cout << "\n\n\t\t\t************************* SPACE FIRING GAME ***************************\n\n";
	cout << "\t\t\t\t\t\t\t  ^\n";
	cout << "\t\t\t\t\t\t\t  ^\n";
	cout << "\t\t\t\t\t\t\t/   \\" << endl;
	cout << "\t\t\t\t\t\t\t|   |\n";
	cout << "\t\t\t\t\t\t\t|   |\n";
	cout << "\t\t\t\t\t\t\t| R |\n";
	cout << "\t\t\t\t\t\t\t| O |\n";
	cout << "\t\t\t\t\t\t\t| C |\n";
	cout << "\t\t\t\t\t\t\t| K |\n";
	cout << "\t\t\t\t\t\t\t| E |\n";
	cout << "\t\t\t\t\t\t\t| T |\n";
	cout << "\t\t\t\t\t\t\t|   |\n";
	cout << "\t\t\t\t\t\t\t|   |\n";
	cout << "\t\t\t\t\t\t\t|   |\n";
	cout << "\t\t\t\t\t\t\t/   \\" << endl;
	cout << "\t\t\t\t\t\t       /     \\" << endl;
	cout << "\t\t\t\t\t\t      / START \\" << endl;
	cout << "\t\t\t\t\t\t     /_ _ _ _ _\\" << endl;
	cout << "\n\n\t\t\t***************************** LET'S PLAY *********************************\n\n";

}

void rocket::draw()
{
	int temp = y;
	CPo.X = x;
	for (int i = 0; i < 5; i++)
	{
		CPo.Y = temp;
		SetConsoleCursorPosition(consl, CPo);

		if (i == 0)cout << " ^\n";
		else if (i == 4)cout << "---\n";
		else cout << " |\n";
		temp++;
	}

}

void rocket::setxy(int a, int b)
{
	x = a, y = b;
}

void rocket::move(int a)						// player can move both horizontally and and vertically
{
	if (a == 77)					//right arrow key ASCII
	{
		if (x < 115) x++;
	}
	if (a == 75)					//left arrow key ASCII
	{
		if (x > 0) x--;
	}
	if (a == 72)					//up arrow key ASCII
	{
		if (y > 0) y--;
	}
	if (a == 80)					//down arrow key ASCII
	{
		y++;
	}

}
void rocket::fire(char c, int& sss, int& mss)				//starShip score, martianShip score
{
	if (c == 'f')				//trying to fire star_ship(small)
	{
		mss = 0;
		sss++;
	}
	if (c == 'F')				//fire martian_ship(large)
	{
		sss = 0;
		mss++;
	}
	if (ball != 0)							//if array 
	{
		f[ball - 1] = 0;						//decremet size of array from end
		ball--;
	}
}

int rocket::remainBall()
{
	return ball;
}
int rocket::getlives()
{
	return lives;
}

int rocket::getx()
{
	return x;
}
int rocket::gety()
{
	return y;
}

void rocket::setChances(int value)
{
	static int var = 2;
	ch1 = ch2;
	ch2++;
	if (value == 1)						//non_consective fires from ship, don't harm rocket
	{
		for (int i = 0; i < 3; i++) chances[i] = 1;
		var = 2;
	}
	else
	{
		chances[var--] = 0;
		if (var < 0)						//1 life ends, restart game
		{
			var = 2;
		}
	}
}

int& rocket::returnch2()
{
	return ch2;
}

int rocket::getChances(int j)
{
	return chances[j];
}


