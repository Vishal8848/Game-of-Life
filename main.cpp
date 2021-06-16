/**
 *  Author : Vishal Pranav
 *  Title  : John Conway's Game of Life
 */

#include <iostream>
#include <conio.h>
#include <windows.h>
#include "template.h"

using namespace std;

typedef int XY[2];

int gridMap[MAXL][MAXW];          // Current Generation   N
int gridMapBuffer[MAXL][MAXW];   // Next Generation      N + 1
int lifeCount = 0, Generation = 1;

void setGridMap()
{
    for(int i = 0; i < MAXL; i++)
        for(int j = 0; j < MAXW; j++)
            gridMap[i][j] = gridMapBuffer[i][j] = 0;
}

void fillGrid()
{
    lifeCount = 0;
    for(int i = 0; i < MAXL - 1; i++)
        for(int j = 0; j < MAXW; j++)
            if(gridMap[i][j])   {
                gotoxy(i + startX, j + startY);
                printf("%c", 178);
                lifeCount++;
            }
            else    {
                gotoxy(i + startX, j + startY);
                printf(" ");
            }
}

#include "patterns.h"

// The main Algorithm - Raw

void checkNeighbors()
{
    int liveNeighbor;

    for(int i = 1; i < MAXL + 1; i++)
        for(int j = 1; j < MAXW + 1; j++)
        {
            liveNeighbor = 0;
            if(gridMap[i-1][j-1])   ++liveNeighbor;     // Top Left
            if(gridMap[i][j-1])     ++liveNeighbor;     // Top
            if(gridMap[i+1][j-1])   ++liveNeighbor;     // Top Right
            if(gridMap[i-1][j])     ++liveNeighbor;     // Left
            if(gridMap[i+1][j])     ++liveNeighbor;     // Right
            if(gridMap[i-1][j+1])   ++liveNeighbor;     // Bottom Left
            if(gridMap[i][j+1])     ++liveNeighbor;     // Bottom
            if(gridMap[i+1][j+1])   ++liveNeighbor;     // Bottom Right

            if(gridMap[i][j])   {
                if(liveNeighbor == 2 || liveNeighbor == 3)
                    gridMapBuffer[i][j] = 1;
            }
            else if(!gridMap[i][j]) {
                if(liveNeighbor == 3)
                    gridMapBuffer[i][j] = 1;
            }
        }

    for(int i = 0; i < MAXL; i++)
        for(int j = 0; j < MAXW; j++)   {
            gridMap[i][j] = gridMapBuffer[i][j];
            gridMapBuffer[i][j] = 0;
        }
}

int main()
{
    // Stats
    gotoxy(6, 3);   printf("John Conway's Game of Life");
    gotoxy(6, 4);   printf("==========================");
    gotoxy(100, 3);  printf("ALIVE : ---");
    gotoxy(120, 3);  printf("GENERATION : ---");

    // Setting up Life Grid
    setGridMap();
    Grid(MAXL, MAXW, INDL, INDT);

    // Initiating the Grid with a Pattern
    domeLikeLifePattern();

    // Filling the Grid with the Initial Pattern
    fillGrid();
    gotoxy(108, 3);  printf("%3d", lifeCount);
    gotoxy(133, 3);  printf("%3d", Generation++);
    Sleep(2500);

    for(;;)     {       // The Real Game of Life in Execution
        Sleep(100);
        checkNeighbors();
        fillGrid();
        gotoxy(108, 3);  printf("%3d", lifeCount);
        gotoxy(133, 3);  printf("%3d", Generation++);
        if(Generation%2 == 0)   {
            gotoxy(108, 4);  printf("===");
            gotoxy(133, 4);  printf("===");
        }   else    {
            gotoxy(108, 4);  printf("   ");
            gotoxy(133, 4);  printf("   ");
        }

        if(lifeCount == 0)  break;
    }

    // Game stops when Life Count Reached 0

    gotoxy(65, 22); printf("! GAME OVER !");

    gotoxy(0, 0);
    getch();
    return 0;
}
