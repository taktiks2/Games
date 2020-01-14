#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
using namespace std;

const int FIELD_HEIGHT = 22, FIELD_WIDTH = 12;
char field[FIELD_HEIGHT][FIELD_WIDTH];
char displayBuffer[FIELD_HEIGHT][FIELD_WIDTH];

enum {
	MINO_TYPE_I,
	MINO_TYPE_O,
	MINO_TYPE_S,
	MINO_TYPE_Z,
	MINO_TYPE_J,
	MINO_TYPE_L,
	MINO_TYPE_T,
	MINO_TYPE_MAX
};

enum {
	MINO_ANGLE_0,
	MINO_ANGLE_90,
	MINO_ANGLE_180,
	MINO_ANGLE_270,
	MINO_ANGLE_MAX
};

const int MINO_HEIGHT = 4, MINO_WIDTH = 4;

char minoShapes[MINO_TYPE_MAX][MINO_ANGLE_MAX][MINO_HEIGHT][MINO_WIDTH] = {
    { // MINO_TYPE_I
		{ // MINO_ANGLE_0
			0, 1, 0, 0,
			0, 1, 0, 0,
			0, 1, 0, 0,
			0, 1, 0, 0
		},
		{ // MINO_ANGLE_90
			0, 0, 0, 0,
			0, 0, 0, 0,
			1, 1, 1, 1,
			0, 0, 0, 0
		},
		{ // MINO_ANGLE_180
			0, 0, 1, 0,
			0, 0, 1, 0,
			0, 0, 1, 0,
			0, 0, 1, 0
		},
		{ // MINO_ANGLE_90
			0, 0, 0, 0,
			1, 1, 1, 1,
			0, 0, 0, 0,
			0, 0, 0, 0
		},
	},
    { // MINO_TYPE_O
		{ // MINO_ANGLE_0
			0, 0, 0, 0,
			0, 1, 1, 0,
			0, 1, 1, 0,
			0, 0, 0, 0
		},
		{ // MINO_ANGLE_90
			0, 0, 0, 0,
			0, 1, 1, 0,
			0, 1, 1, 0,
			0, 0, 0, 0
		},
		{ // MINO_ANGLE_180
			0, 0, 0, 0,
			0, 1, 1, 0,
			0, 1, 1, 0,
			0, 0, 0, 0
		},
		{ // MINO_ANGLE_90
			0, 0, 0, 0,
			0, 1, 1, 0,
			0, 1, 1, 0,
			0, 0, 0, 0
		},
	},
    { // MINO_TYPE_S
		{ // MINO_ANGLE_0
			0, 0, 0, 0,
			0, 1, 1, 0,
			1, 1, 0, 0,
			0, 0, 0, 0
		},
		{ // MINO_ANGLE_90
			0, 0, 0, 0,
			0, 0, 0, 0,
			1, 1, 1, 1,
			0, 0, 0, 0
		},
		{ // MINO_ANGLE_180
			0, 0, 1, 0,
			0, 0, 1, 0,
			0, 0, 1, 0,
			0, 0, 1, 0
		},
		{ // MINO_ANGLE_90
			0, 0, 0, 0,
			1, 1, 1, 1,
			0, 0, 0, 0,
			0, 0, 0, 0
		},
	},
    { // MINO_TYPE_I
		{ // MINO_ANGLE_0
			0, 1, 0, 0,
			0, 1, 0, 0,
			0, 1, 0, 0,
			0, 1, 0, 0
		},
		{ // MINO_ANGLE_90
			0, 0, 0, 0,
			0, 0, 0, 0,
			1, 1, 1, 1,
			0, 0, 0, 0
		},
		{ // MINO_ANGLE_180
			0, 0, 1, 0,
			0, 0, 1, 0,
			0, 0, 1, 0,
			0, 0, 1, 0
		},
		{ // MINO_ANGLE_90
			0, 0, 0, 0,
			1, 1, 1, 1,
			0, 0, 0, 0,
			0, 0, 0, 0
		},
	},
    { // MINO_TYPE_I
		{ // MINO_ANGLE_0
			0, 1, 0, 0,
			0, 1, 0, 0,
			0, 1, 0, 0,
			0, 1, 0, 0
		},
		{ // MINO_ANGLE_90
			0, 0, 0, 0,
			0, 0, 0, 0,
			1, 1, 1, 1,
			0, 0, 0, 0
		},
		{ // MINO_ANGLE_180
			0, 0, 1, 0,
			0, 0, 1, 0,
			0, 0, 1, 0,
			0, 0, 1, 0
		},
		{ // MINO_ANGLE_90
			0, 0, 0, 0,
			1, 1, 1, 1,
			0, 0, 0, 0,
			0, 0, 0, 0
		},
	},
    { // MINO_TYPE_I
		{ // MINO_ANGLE_0
			0, 1, 0, 0,
			0, 1, 0, 0,
			0, 1, 0, 0,
			0, 1, 0, 0
		},
		{ // MINO_ANGLE_90
			0, 0, 0, 0,
			0, 0, 0, 0,
			1, 1, 1, 1,
			0, 0, 0, 0
		},
		{ // MINO_ANGLE_180
			0, 0, 1, 0,
			0, 0, 1, 0,
			0, 0, 1, 0,
			0, 0, 1, 0
		},
		{ // MINO_ANGLE_90
			0, 0, 0, 0,
			1, 1, 1, 1,
			0, 0, 0, 0,
			0, 0, 0, 0
		},
	},
    { // MINO_TYPE_I
		{ // MINO_ANGLE_0
			0, 1, 0, 0,
			0, 1, 0, 0,
			0, 1, 0, 0,
			0, 1, 0, 0
		},
		{ // MINO_ANGLE_90
			0, 0, 0, 0,
			0, 0, 0, 0,
			1, 1, 1, 1,
			0, 0, 0, 0
		},
		{ // MINO_ANGLE_180
			0, 0, 1, 0,
			0, 0, 1, 0,
			0, 0, 1, 0,
			0, 0, 1, 0
		},
		{ // MINO_ANGLE_90
			0, 0, 0, 0,
			1, 1, 1, 1,
			0, 0, 0, 0,
			0, 0, 0, 0
		},
	},
};

int minoY = 0, minoX = 5;
int minoType = 0, minoAngle = 0;

void display();
bool isHit(int tempY, int tempX, int tempType, int tempAngle); 

int main(){
	// Inisialize field
	memset(field, 0, sizeof(field));

	// Make wall
	for (int axisY = 0; axisY < FIELD_HEIGHT; axisY++) {
		field[axisY][0] = field[axisY][FIELD_WIDTH - 1] = 1;
	}
	for (int axisX = 0; axisX < FIELD_WIDTH; axisX++) {
		field[FIELD_HEIGHT - 1][axisX] = 1;
	}

	time_t t = time(NULL);
	
	while (true) {
		if (_kbhit()) {
			switch (_getch()) {
				case 's': if (!isHit(minoY + 1, minoX, minoType, minoAngle)) {
							  minoY++;
						  }
						  break;
				case 'a': if (!isHit(minoY, minoX - 1, minoType, minoAngle)) {
							  minoX--;
						  }
						  break;
				case 'd': if (!isHit(minoY, minoX + 1, minoType, minoAngle)) {
							  minoX++;
						  }
						  break;
				case ' ': if (!isHit(minoY, minoX, minoType, (minoAngle + 1) % MINO_ANGLE_MAX)) {
							  minoAngle = (minoAngle + 1) % MINO_ANGLE_MAX;
						  }
						  break;
			}
			display();
		}

		if (t != time(NULL)) {
			t = time(NULL);

			if (isHit(minoY + 1, minoX, minoType, minoAngle)) {
				for (int axisY = 0; axisY < MINO_HEIGHT; axisY++) {
					for (int axisX = 0; axisX < MINO_WIDTH; axisX++) {
						field[minoY + axisY][minoX + axisX] |= minoShapes[minoType][minoAngle][axisY][axisX];
					}
				}
				minoY = 0;
				minoX = 5;
				minoType = rand() % MINO_TYPE_MAX;
				minoAngle = rand() % MINO_ANGLE_MAX;
			} else {
				minoY++;
			}
			display();
		}
	}
	_getch();
	return 0;
}

void display() {
	// Draw field
	memcpy(displayBuffer, field, sizeof(field));

	for (int axisY = 0; axisY < MINO_HEIGHT; axisY++) {
		for (int axisX = 0; axisX < MINO_WIDTH; axisX++) {
			displayBuffer[minoY + axisY][minoX + axisX]	|= minoShapes[minoType][minoAngle][axisY][axisX];
		}
	}
	system("cls");
	for (int axisY = 0; axisY < FIELD_HEIGHT; axisY++) {
		for (int axisX = 0; axisX < FIELD_WIDTH; axisX++) {
			printf(displayBuffer[axisY][axisX] ? "[]" : "  ");
		}
		printf("\n");
	}
}

bool isHit(int tempY, int tempX, int tempType, int tempAngle) {
	for (int axisY = 0; axisY < MINO_HEIGHT; axisY++) {
		for (int axisX = 0; axisX < MINO_WIDTH; axisX++) {
			if (minoShapes[tempType][tempAngle][axisY][axisX]
					&& field[tempY + axisY][tempX + axisX]) {
				return true;
			}
		}
	}
	return false;
}
