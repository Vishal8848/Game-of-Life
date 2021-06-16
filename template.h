#ifndef TEMPLATE_H_INCLUDED
#define TEMPLATE_H_INCLUDED

#define MAXL 140    // Max Grid Length
#define MAXW 36     // Max Grid Width
#define INDL 5      // Left Indent
#define INDT 6      // Top Indent

COORD coord = {0, 0};

int startX = INDL + 1, startY = INDT + 1;

void gotoxy(int x, int y)   {
    coord.X = x, coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Frame(int Length = 1, int leftEnd = 201, int rightEnd = 187, int Middle = 205)   {
    for(int i = 0; i < Length; i++) {
        if(i == 0)  printf("%c", leftEnd);
        if(i == Length - 1) printf("%c", rightEnd);
        else printf("%c", Middle);
    }
}

void Grid(int Length = 1, int Width = 0, int X = coord.X, int Y = coord.Y)
{
    gotoxy(X, Y);   Frame(Length, 201, 187, 205);
    for(int i = 0; i < Width; i++) {
        gotoxy(X, Y + i + 1);             printf("%c", 186);
        gotoxy(X + Length, Y + i + 1);    printf("%c", 186);
    }
    gotoxy(X, Y + Width + 1);   Frame(Length, 200, 188);
}

void clearGrid(int Length = 1, int Width = 1, int X = coord.X, int Y = coord.Y)
{
    for(int i = X; i < Length + X - 1; i++)
    {
        for(int j = Y; j < Width + Y; j++)
        {
            gotoxy(i, j);   printf(" ");
        }
    }
}

#endif // TEMPLATE_H_INCLUDED
