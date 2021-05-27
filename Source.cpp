//mahreen asama: bsef19m030
/*NOTE: Game works according to small console screen*/
/*NOTE: due to again and again 'CLS', system may work slowly, but, to check process properly, just remove
		if(_kbhit()) condition at line# 220....*/

#include<iostream>
using namespace std;
#include<windows.h>
#include<conio.h>
#include<stdio.h>
#include"fireBall.h"
#include"spaceShip.h"
#include"starShip.h"
#include"martianShip.h"
#include"rocket.h"

int rocket::ch1 = 0;
int rocket::ch2 = 0;
int rocket::ball = 100;
int spaceShip::score = 0;
int spaceShip::balls = 100;
int spaceShip::x = 0;
int spaceShip::y = 2;
int g = 1;
void restartGame(rocket& r, starShip& s, martianShip& m)		//friend fction of all classes
{
	r.lives--;
	for (int i = 0; i < 3; i++) r.chances[i] = 1;
	for (int i = 0; i < 100; i++) r.f[i] = 1;
	for (int i = 0; i < 100; i++) s.f[i] = 1;
}
void playAgain(rocket& r, starShip& s, martianShip& m)			//friend fction of all classes
{
	r.lives = 3; r.ball = 100;
	s.x = 0; s.y = 3;
	r.setxy(40, 23);
	s.score = 0; s.balls = 100;
	for (int i = 0; i < 3; i++) r.chances[i] = 1;
	for (int i = 0; i < 100; i++) r.f[i] = 1;
	for (int i = 0; i < 100; i++) s.f[i] = 1;
}

int main()														//main function
{
	/*code for first 2 welcome screens*/
	starShip ss; martianShip ms; rocket r1;
	r1.setxy(40, 20);
	r1.maindraw();
	char s;
	while (1)
	{
		cout << "Press 's' to start the game: "; cin >> s;
		if (s == 's' || s == 'S')
		{
			break;
		}
		else
		{
			cout << "wrong input! Enter correct letter\n";
			continue;
		}
	}
	system("CLS");
	cout << "RULES:\n\n";
	cout << "\t* There are 3 lives for player to win the game, and 3 chances in each life to survive.\n";
	cout << "\t* Pressing (lower)'f' continuously 3 times destroys star_sip.\n";
	cout << "\t* Pressing (upper)'F' continuously 5 times destroys martian_sip.\n";
	cout << "\t* 100 points made by player will result in his victory.\n";
	cout << "\nEnemy space_ships:\n\n";
	cout << "\t* STAR SHIP:\t\t\t\t\t\tGives 5 score\n";
	ss.maindraw();
	cout << "\n\n\n\t* MARTIAN SHIP:\t\t\t\t\t\tGives 10 score\n";
	ms.maindraw();
	cout << "ROCKET (player's weapon):\t\t\t\t\tWorks on pressing 'f' OR 'F'\n";
	r1.draw();
	while (1)
	{
		cout << "Press 'p' to play the game: "; cin >> s;
		if (s == 'p' || s == 'P')
		{
			break;
		}
		else
		{
			cout << "wrong input! Enter correct letter\n";
			continue;
		}
	}
	system("cls");

	/*3rd screen showing enemy spaceShips and user rocket*/
	/*if a ship is fired, 'fired' is written on screen, scores are incremented(shown on screen), and next ship, of same size apppers there in next iteration*/

	spaceShip* s1 = &ss;		//just to point someWhere...

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD CursorPosition;
	char r;
	do
	{
		r1.setxy(40, 23);
		int v = 0;
		while (1)
		{
			/*scores and lives of player shown on top of screen*/
			CursorPosition.X = 0;
			CursorPosition.Y = 0;
			SetConsoleCursorPosition(console, CursorPosition);

			cout << "*** SCORE: " << spaceShip::score << " ***\t";
			cout << "LIFE " << r1.getlives() << " CHANCES: ";
			for (int j = 0; j < 3; j++)
				cout << r1.getChances(j) << " ";
			if (r1.getChances(0) == 0)					//if last chance to survive in a life ends, then, rocket life ends
			{
				v = 1;
				restartGame(r1, ss, ms);
			}
			if (v == 1)
			{
				cout << "\tLIFE " << r1.getlives() + 1 << " of ROCKET ended\n";
			}

			/*restart Game situation, life ends if ball array of rocket empty, but generally this situation will not ocurr*/
			if (r1.remainBall() <= 0)
			{
				for (int i = 0; i < 11; i++) cout << "\t";
				cout << "\tLIFE " << r1.getlives() + 1 << " of rocket ENDED";
				restartGame(r1, ss, ms);
			}

			/*player winnig situation, final window*/
			if (spaceShip::score >= 100)
			{
				system("cls");
				for (int i = 0; i < 10; i++) cout << "\n";
				cout << "\t\t\t\t\t\t*** PLAYER WON ***\n";
				cout << "\t\t\t\t\t\tSCORE: " << spaceShip::score << "\n";
				break;
			}

			/*LOST game situation, current game ends*/
			if (r1.getlives() == 0 && spaceShip::score < 100)
			{
				system("cls");
				for (int i = 0; i < 10; i++) cout << "\n";
				cout << "\t\t\t\t\t\tALL LIVES ENDED\n\t\t\t\t\t\t*** GAME LOST ***, ";
				cout << "SCORE: " << spaceShip::score << "\n";
				break;
			}

			/*drawing of spaceShips on screen, two rows appearing*/
			s1->resetx();												//setting x,y to original values
			s1->setxy(s1->getx(), s1->gety());
			for (int k = 0; k < 4; k++)									//first row 
			{
				if (k == 1 || k == 3)
				{
					s1 = &ms;
				}
				else
				{
					s1 = &ss;

				}
				s1->draw(r1.getx(), r1.gety(), r1.returnch2());
			}
			s1->resetx();
			s1->setxy(s1->getx() + 9, s1->gety() + 4);
			for (int k = 0; k < 4; k++)									//second row
			{
				if (k == 2)
				{
					s1 = &ms;
				}
				else
				{
					s1 = &ss;
				}
				s1->draw(r1.getx(), r1.gety(), r1.returnch2());
			}
			s1->move();													//ships move downward

			/*firing of spaceShips and destroy of rocket->if ships hit rocket*/
			if (s1->gety() == 15)
			{
				int t1 = s1->fire();				//space ship fires, and one chance for player to survive in his present life, ENDS 
				if (t1 > 0)
				{
					if (rocket::ch1 == rocket::ch2 - 1)		//checking consectivity 
						r1.setChances(0);					//rocket effectcs if it not destroys anyShip
					else
						r1.setChances(1);
				}
			}

			/*draw player rocket and wait for user to fire/move rocket*/
			r1.draw();
			int a;
			//if (_kbhit())								//_kbhit() checks of any character
			//{
				a = _getch();
				if (a == 'f' || a == 'F')
					r1.fire(a, ss.gets(), ms.gets());
				else
					r1.move(a);
			//}
			system("cls");
			s1->resety();									//to move downward properly
			g++;
		}
		cout << "\t\t\t\t\t\tDo you want to play again?\n\t\t\t\t\t\tenter 'y' if yes, and 'n' if no:";  cin >> r;
		g = 1;
		playAgain(r1, ss, ms);								//if want to play again, same rules as before
		system("cls");

	} while (r == 'y');

	return 0;
}