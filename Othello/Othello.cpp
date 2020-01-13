// This is a typical othello game
// Takeru Osoegawa
// 12/7/2019
// ver.1.0

#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

// Define board size
const int BOARD_WIDTH = 5, BOARD_HEIGHT = 5;
// Define cursor coodinates
int cursorX, cursorY;
// Define turn
int turn;
// Define board
int cells[BOARD_HEIGHT][BOARD_WIDTH];

enum {
	COLOR_NONE = -1,
	COLOR_BLACK = 0,
	COLOR_WHITE = 1,
	COLOR_MAX
};

string colorNames[2] = { "Black", "White" };

enum {
	DIRECTION_UP,
	DIRECTION_UP_LEFT,
	DIRECTION_LEFT,
	DIRECTION_DOWN_LEFT,
	DIRECTION_DOWN,
	DIRECTION_DOWN_RIGHT,
	DIRECTION_RIGHT,
	DIRECTION_UP_RIGHT,
	DIRECTION_MAX
};

int directions[][2] = {
	{0, -1}, // DIRECTION_UP
	{-1, -1}, // DIRECTION_UP_LEFT
	{-1, 0}, // DIRECTION_LEFT
	{-1, 1}, // DIRECTION_DOWN_LEFT
	{0, 1}, // DIRECTION_DOWN
	{1, 1}, // DIRECTION_DOWN_RIGHT
	{1, 0}, // DIRECTION_RIGHT
	{1, -1}, // DIRECTION_UP_RIGHT
};

bool checkCanPut(int turn, int x, int y, bool turnover = false);
bool checkCanPutAll(int turn);
void drawBoard();

int main() {
	for (int y = 0; y < BOARD_HEIGHT; y++) {
		for (int x = 0; x < BOARD_WIDTH; x++)
			cells[y][x] = COLOR_NONE;
	}
	cells[3][3] = cells[4][4] = COLOR_WHITE;
	cells[4][3] = cells[3][4] = COLOR_BLACK;

	bool cantPut = false;

	while (true) {
		drawBoard();
		
		if (cantPut)
			cout << "Can't put!\n";
		else
			cout << colorNames[turn] << " turn.\n";

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
			checkCanPut(turn, cursorX, cursorY, true);

			cells[cursorY][cursorX] = turn;
			turn ^= 1;

			if (!checkCanPutAll(turn))
				turn ^= 1;

			break;
		}
		if (!checkCanPutAll(COLOR_BLACK) && !checkCanPutAll(COLOR_WHITE)) {
			drawBoard();

			int count[COLOR_MAX] = {};

			for (int y = 0; y < BOARD_HEIGHT; y++)
				for (int x = 0; x < BOARD_WIDTH; x++)
					if (cells[y][x] != COLOR_NONE)
						count[cells[y][x]]++;

			drawBoard();
			for (int i = 0; i < COLOR_MAX; i++)
				cout << colorNames[i] << " : " << count[i] << endl;

			if (count[COLOR_BLACK] == count[COLOR_WHITE])
				cout << "Draw!\n";

			else {
				if (count[COLOR_BLACK] > count[COLOR_WHITE])
					cout << colorNames[COLOR_BLACK];
				else
					cout << colorNames[COLOR_WHITE];
				cout << " Won!\n";
			}
			_getch();
			break;
		}
	}
	return 0;
}

bool checkCanPut(int turn, int x, int y, bool turnover) {
	if (cells[y][x] != COLOR_NONE)
		return false;

	for (int i = 0; i < DIRECTION_MAX; i++) {
		int tempX = x, tempY = y;

		tempX += directions[i][0];
		tempY += directions[i][1];

		if (cells[tempY][tempX] != (turn ^ 1))
			continue;

		while (true) {
			tempX += directions[i][0];
			tempY += directions[i][1];

			if ((tempX < 0) || (tempX >= BOARD_WIDTH) || (tempY < 0) || (tempY >= BOARD_HEIGHT))
				break;
			if (cells[tempY][tempX] == COLOR_NONE)
				break;
			if (cells[tempY][tempX] == turn) {
				if (!turnover)
					return true;

				int tempX2 = x, tempY2 = y;

				while (true) {
					cells[tempY2][tempX2] = turn;

					tempX2 += directions[i][0];
					tempY2 += directions[i][1];

					if ((tempX2 == tempX) && (tempY2 == tempY))
						break;
				}
			}
		}
	}
	return false;
}

bool checkCanPutAll(int turn) {
	for (int y = 0; y < BOARD_HEIGHT; y++)
		for (int x = 0; x < BOARD_WIDTH; x++)
			if (checkCanPut(turn, x, y))
				return true;

	return false;
}

void drawBoard() {
	system("cls");

	for (int y = 0; y < BOARD_HEIGHT; y++) {
		for (int x = 0; x < BOARD_WIDTH; x++) {
			if (x == cursorX && y == cursorY)
				cout << " @";

			else
				switch (cells[y][x]) {
				case COLOR_NONE:  cout << " *"; break;
				case COLOR_BLACK: cout << " X"; break;
				case COLOR_WHITE: cout << " O"; break;
				}
		}
		cout << endl;
	}
}