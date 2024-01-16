#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define DIMX 20
#define DIMY 11
#define PA 5
#define D 4
#define F 3
#define C 2

typedef unsigned char index;
typedef char* Vect;
typedef Vect* Grid;


void clearTerminal();
Grid createGrid(void);
void dispGrid(Grid G);
void locateShip(index* ord, index* abs, index* orient, index* len);
int testShip(Grid G, index i, index j, index o, index len);
void placeShips(Grid G);