// This is a janken game!!
// Takeru Osoegawa
// 11/11/2019

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

const char ROCK = 1, PAPER = 2, SCISSORS = 3;

int main()
{	
	int playerHand, comHand;
	
	unsigned seed = time(0);
	srand(seed);

	system("cls");
	
	cout << "\n"
		<< " **********************************************************************\n"
		<< " *                                                                    *\n"
		<< " *                            JANKEN GAME                             *\n"
		<< " *                                                                    *\n"
		<< " *            This is a typical Rock-Paper-Scissors game.             *\n"
		<< " *               The game is called Janken in Japanese.               *\n"
		<< " *                                                                    *\n"
		<< " *      Rock <1> グー     Paper <2> パー     Scissors <3> チョキ      *\n"
		<< " *                                                                    *\n"
		<< " *                      Made by Takeru Osoegawa                       *\n"
		<< " *                                                                    *\n"
		<< " **********************************************************************\n";
	/*	
	system("pause");
	system("cls");*/

	cout << "\n"
		<< "Please enter a number of the hand which you want to show!: ";
	cin >> playerHand;
	cin.ignore(1024, '\n');

	switch (playerHand)
	{
		case ROCK : 

	return 0;
}


