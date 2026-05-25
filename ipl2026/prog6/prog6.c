#include <stdio.h>
#include <math.h>

#define ROWS 25
#define COLS 50

/* Structure for Circle */
typedef struct
{
    int centerX;
    int centerY;
    int radius;
} Circle;

/* Function Declarations */
void initializeBuffer(char buffer[ROWS][COLS]);
void drawCircle(char buffer[ROWS][COLS], Circle c);
void displayBuffer(char buffer[ROWS][COLS]);
int isCirclePoint(int x, int y, Circle c);

int main()
{
    char buffer[ROWS][COLS];

    Circle c;

    c.centerX = 25;
    c.centerY = 12;
    c.radius = 10;

    initializeBuffer(buffer);

    drawCircle(buffer, c);

    displayBuffer(buffer);

    return 0;
}


void initializeBuffer(char buffer[ROWS][COLS])
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            buffer[i][j] = ' ';
        }
    }
}


int isCirclePoint(int x, int y, Circle c)
{
    int value;

    value = (x - c.centerX) * (x - c.centerX) +
            (y - c.centerY) * (y - c.centerY);

    if(abs(value - (c.radius * c.radius)) <= c.radius)
    {
        return 1;
    }

    return 0;
}


void drawCircle(char buffer[ROWS][COLS], Circle c)
{
    int x, y;

    for(y = 0; y < ROWS; y++)
    {
        for(x = 0; x < COLS; x++)
        {
            if(isCirclePoint(x, y, c))
            {
                buffer[y][x] = '*';
            }
        }
    }
}


void displayBuffer(char buffer[ROWS][COLS])
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            printf("%c", buffer[i][j]);
        }

        printf("\n");
    }
}