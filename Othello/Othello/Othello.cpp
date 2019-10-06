#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

const int boardHight = 8, boardWidth = 8;

enum {
	colorNone = -1,
	colorBlack = 0,
	colorWhite = 1,
	colorMax
};

string colorNames[2] = { "Black", "White" };

int cells[boardHight][boardWidth];

int cursorX, cursorY;

int turn;

int main() {

	for (int y = 0; y < boardHight; y++) {

		for (int x = 0; x < boardWidth; x++) {

			cells[y][x] = turn;
		}
	}



	while (true) {

		system("cls");

		for (int y = 0; y < boardHight; y++) {

			for (int x = 0; x < boardWidth; x++) {

				if (x == cursorX && y == cursorY) {

					cout << "◎";

				}

				else {

					switch (cells[y][x]) {

					case colorNone: cout << "・"; break;

					case colorBlack: cout << "●"; break;

					case colorWhite: cout << "○"; break;

					}

				}

			}

			cout << "\n";

		}


		switch (_getch()) {

		case 'w': cursorY--; break;

		case 's': cursorY++; break;

		case 'a': cursorX--; break;

		case 'd': cursorX++; break;

		default:
			
			cells[cursorY][cursorX] = turn;
			
			break;

		}
		

	}

}