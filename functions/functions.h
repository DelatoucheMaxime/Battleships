#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>

#define DIMX 20
#define DIMY 11
#define PA 5
#define D 4
#define F 3
#define C 2

typedef char* Vect;
typedef Vect* Grid;

/// @brief Cearing the terminal
void clearTerminal();

/// @brief Cearing the terminal
/// @return The initialized grid 
Grid createGrid(void);

/// @brief Cearing the terminal
/// @param G: the grid to display 
void dispGrid(Grid G);

/// @brief Cearing the terminal
/// @param ord: pointer to a y axis value
/// @param abs: pointer to a x axis value
/// @param orient: pointer to a ship orientation
/// @param len: pointer to the length of the ship
void locateShip(int* ord, int* abs, int* orient, int* len);

/// @brief Cearing the terminal
/// @param G: grid to check if it can be placed on
/// @param ord: pointer to a y axis value
/// @param abs: pointer to a x axis value
/// @param orient: pointer to a ship orientation
/// @param len: pointer to the length of the ship
/// @return 1 if it can be place, 0 otherway
int testShip(Grid G, int ord, int abs, int orient, int len);


void placeShips(Grid G);