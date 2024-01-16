#include "functions/functions.c"

int main(void)
{
    clearTerminal();

    printf("*********Battleships Game*********\n\n");

    Grid grid = createGrid();

    dispGrid(grid);
    
    return EXIT_SUCCESS;
}