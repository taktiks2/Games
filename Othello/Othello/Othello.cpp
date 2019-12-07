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

enum {
	dirUp,
	dirUpLeft,
	dirLeft,
	dirDownLeft,
	dirDown,
	dirDownRight,
	dirRight,
	dirUpRight,
	dirMax
};

int directions[][2]{

	{0,-1},//dirUp
	{-1,-1},//dirUpLeft
	{-1,0},//dirLeft
	{-1,1},//dirDownLeft
	{0,1},//dirDown
	{1,1},//dirDownRight
	{1,0},//dirRight
	{1,-1}//dirUpRight

};

string colorNames[2] = { "Black", "White" };

int cells[boardHight][boardWidth];

int cursorX, cursorY;

int turn;

bool cantPut = false;

bool checkCanPut(int _color, int _x, int _y) {
	
	if (cells[_y][_x] != colorNone) {

		return false;

	}

	for (int i = 0; i < dirMax; i++) {

		int x = _x, y = _y;

	}

	return true;

}

int main() {

	for (int y = 0; y < boardHight; y++) {

		for (int x = 0; x < boardWidth; x++) {

			cells[y][x] = colorNone;

			cells[3][3] = cells[4][4] = colorWhite;

			cells[4][3] = cells[3][4] = colorBlack;

		}

	} 

	while (true) {

		system("cls");

		for (int y = 0; y < boardHight; y++) {

			for (int x = 0; x < boardWidth; x++) {

				if (cursorY == y && cursorX == x) {

					cout << "◎";
				}

				else {

					switch (cells[y][x]) {

					case colorNone: cout << "・"; break;

					case colorBlack: cout << "○"; break;

					case colorWhite: cout << "●"; break;

					}

				}


			}

			cout << "\n";

		}

		if (cantPut) {

			cout << "Can't put!\n";
		}

		else {

			cout << colorNames[turn] << " turn.\n";

		}

		cantPut = false;

		switch (_getch()) {

		case 'w': cursorY--; break;

		case 's': cursorY++; break;

		case 'a': cursorX--; break;

		case 'd': cursorX++; break;

		default:

			if (!checkCanPut(turn, cursorX, cursorY)) {

				cantPut = true;

				break; 

			}
			
			cells[cursorY][cursorX] = turn;

			turn ^= 1;

		}

	}
}