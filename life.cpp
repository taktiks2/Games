#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

const int FIELD_HEIGHT = 24, FIELD_WIDTH = 24;
int cursorY, cursorX;
int cells[2][FIELD_HEIGHT][FIELD_WIDTH];
int currentLayer;

int getAdjacentLivesCount(int x, int y);

int main() {
  while (true) {
    system("cls");

    for (int y = 0; y < FIELD_HEIGHT; y++) {
      for (int x = 0; x < FIELD_WIDTH; x++) {
        if (x == cursorX && y == cursorY) {
          printf(" @");
        } else {
          printf(" %s", cells[currentLayer][y][x] ? "O" : "*");
        }
        // Check behaver of getAdjacentLivesCount
        // if (x == cursorX && y == cursorY) {
        //  printf(" @");
        //} else {
        //  printf(" %d", getAdjacentLivesCount(x, y));
        //}
      }
      printf("\n");
    }
    switch (_getch()) {
    case 'w':
      cursorY--;
      break;
    case 's':
      cursorY++;
      break;
    case 'a':
      cursorX--;
      break;
    case 'd':
      cursorX++;
      break;
    case ' ':
      cells[currentLayer][cursorY][cursorX] ^= 1;
      break;
    case '\r':
      for (int y = 0; y < FIELD_HEIGHT; y++) {
        for (int x = 0; x < FIELD_WIDTH; x++) {
          int cellsSitu = getAdjacentLivesCount(x, y);
          int nextGen = cells[currentLayer][y][x];
          if (cells[currentLayer][y][x]) {
            if (cellsSitu <= 1 || 4 <= cellsSitu) {
              nextGen = 0;
            }
          } else {
            if (cellsSitu == 3) {
              nextGen = 1;
            }
          }
          cells[currentLayer ^ 1][y][x] = nextGen;
        }
      }
      currentLayer ^= 1;
      break;
    case 0x1b: // 0x1b == escape key
      for (int y = 0; y < FIELD_HEIGHT; y++) {
        for (int x = 0; x < FIELD_WIDTH; x++) {
          cells[currentLayer][y][x] = 0;
        }
      }
      break;
    case 'q':
      return 0;
    }
  }
  return 0;
}

int getAdjacentLivesCount(int originX, int originY) {
  int count = 0;
  for (int relativeY = -1; relativeY <= 1; relativeY++) {
    for (int relativeX = -1; relativeX <= 1; relativeX++) {
      if (relativeY == 0 && relativeX == 0) {
        continue;
      }
      int absoluteY = (FIELD_HEIGHT + originY + relativeY) % FIELD_HEIGHT;
      int absoluteX = (FIELD_WIDTH + originX + relativeX) % FIELD_WIDTH;
      count += cells[currentLayer][absoluteY][absoluteX];
    }
  }
  return count;
}
