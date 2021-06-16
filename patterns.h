#ifndef PATTERNS_H_INCLUDED
#define PATTERNS_H_INCLUDED

void stepDownLifePattern()  // Life Pattern 1
{
    for(int i = 0; i < MAXL; i++)
        for(int j = 0; j < MAXW; j++)
            if(i == j)
                gridMap[i][j] = 1;
}

void jammedUpLifePattern()  // Life Pattern 2
{
    for(int i = 50, j = 52; i > 40 && j < 60; i--, j++)
        for(int k = 6; k < 16; k++) {
            gridMap[i-1][k] = 1;
            gridMap[i][k] = 1;
            gridMap[j][k] = 1;
            gridMap[j+1][k] = 1;
        }
}

void domeLikeLifePattern()  // Life Pattern 3
{
    gridMap[65][7] = 1;
    gridMap[67][7] = 1;

    for(int i = 65, j = 67, k = 7; i > 52 && j < 82 && k < 22; i--, j++, k++)
        gridMap[i-1][k] = gridMap[i][k] = gridMap[j][k] = gridMap[j+1][k] = 1;
}

#endif // PATTERNS_H_INCLUDED
