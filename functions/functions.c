#include "functions.h"

void clearTerminal(void)
{
    pid_t pid =fork();
    int status;

    if(pid != 0)waitpid(pid, &status, WUNTRACED);
    else execlp("clear", "clear", NULL);
}

Grid createGrid(void)
{
    Grid newGrid = (Grid) malloc((DIMY+1)*sizeof(Vect));
    for(int i=0; i<DIMY+1; i++)
    {
        Vect line = (Vect) malloc((DIMX+1)*sizeof(char));
        for(int j=0; j<DIMX+1; j++)
        {
            if(i==0 && j==0)line[j] = ' ';
            else if(i==0)
            {
                line[j] = '0'+((j-1)%10);
            }
            else if (j==0)line[j] = 'A'+(i-1);
            else line[j] = '~';
        }
        newGrid[i] = line;
    }
    return newGrid;
}

void dispGrid(Grid G)
{
    for(int i=0; i<DIMY; i++)
    {
        printf("|");
        for(int j=0; j<DIMX; j++)
            if(i==0 && j!=0)printf("\t%d%c", ((j-1)/10)%10,G[i][j]);
            else printf("\t %c", G[i][j]);
        printf("\t|\n\n");
    }
}