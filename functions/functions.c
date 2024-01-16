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
                line[j] = '0'+(j%10);
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
    printf("*********Battleships Game*********\n\n");
    for(int i=0; i<DIMY; i++)
    {
        printf("|");
        for(int j=0; j<DIMX; j++)
            if(i==0 && j!=0)printf("\t%d%c", (j/10)%10,G[i][j]);
            else printf("\t %c", G[i][j]);
        printf("\t|\n\n");
    }
}

void locateShip(int* ord, int* abs, int* orient, int* len)
{
    *orient = rand()%2;

    if(*orient)
    {
        *abs = (rand()%(DIMX-1))+1;
        *ord = (rand()%(DIMY-*len))+1;
    }
    else
    {
        *abs = (rand()%(DIMX-*len))+1;
        *ord = (rand()%(DIMY-1))+1;
    }
}

int testShip(Grid G, int ord, int abs, int orient, int len)
{
    int placable = 1;

    if(orient)
    {
        int i = 0;
        while(placable && (i < len))
        {
            if(G[ord+i][abs] != '~')placable=0;
            else i++;
        }
    }
    else
    {
        int j = 0;
        while(placable && (j < len))
        {
            if(G[ord][abs+j] != '~')placable=0;
            else j++;
        }
    }

    return placable;
}

void placeShips(Grid G)
{
    int abs = -1;
    int ord = -1;
    int orient = -1;

    int len = PA;
    locateShip(&ord, &abs, &orient, &len);
    while(!testShip(G, ord, abs, orient, len))
    {
        locateShip(&ord, &abs, &orient, &len);
    }
    for(int i=0; i<len; i++)
    {
        if(orient)G[ord+i][abs]='P';
        else G[ord][abs+i]='P';
    }

    len = D;
    locateShip(&ord, &abs, &orient, &len);
    while(!testShip(G, ord, abs, orient, len))
    {
        locateShip(&ord, &abs, &orient, &len);
    }
    for(int i=0; i<len; i++)
    {
        if(orient)G[ord+i][abs]='D';
        else G[ord][abs+i]='D';
    }

    len = F;
    locateShip(&ord, &abs, &orient, &len);
    while(!testShip(G, ord, abs, orient, len))
    {
        locateShip(&ord, &abs, &orient, &len);
    }
    for(int i=0; i<len; i++)
    {
        if(orient)G[ord+i][abs]='F';
        else G[ord][abs+i]='F';
    }

    len = C;
    locateShip(&ord, &abs, &orient, &len);
    while(!testShip(G, ord, abs, orient, len))
    {
        locateShip(&ord, &abs, &orient, &len);
    }
    for(int i=0; i<len; i++)
    {
        if(orient)G[ord+i][abs]='C';
        else G[ord][abs+i]='C';
    }
}