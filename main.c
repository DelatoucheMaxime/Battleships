#include "functions/functions.c"

int main(void)
{
    clearTerminal();

    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    srand((time_t)ts.tv_nsec);

    printf("*********Battleships Game*********\n\n");

    Grid grid = createGrid();

    clearTerminal();
    dispGrid(grid);

    placeShips(grid);

    sleep(2);

    clearTerminal();
    dispGrid(grid);

    return EXIT_SUCCESS;
}