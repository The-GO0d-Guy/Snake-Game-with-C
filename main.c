/*
Notes :

char ch only takes in the input once . Rectify .
Go through the code thoroughly .
Add More features ( if possible ) .
Push on Github
:)

*/


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int width = 50, height = 20, gameOver;
int x, y, fruitX, fruitY, score, flag;
int tailX[100], tailY[100];
int CountTail = 0;

void setup()
{
    gameOver = 0;
    x = width / 2;
    y = height / 2;

label1:
    fruitX = rand() % 20;
    if (fruitX == 0)
    {
        goto label1;
    }

label2:
    fruitY = rand() % 20;
    if (fruitY == 0)
    {
        goto label2;
    }
}

void draw()
{
    int i, j;
    system("cls");
    printf("==================SCOREBOARD==========================\n");
    printf("             Your Score is : %d\n\n\n", score);
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
            {
                printf("*");
            }
            else
            {
                if (i == y && j == x)
                {
                    printf("O");
                }
                else if (i == fruitX && j == fruitY)
                {
                    printf("F");
                }
                else
                {
                    int yes = 0;
                    for (int k = 0; k < CountTail; k++)
                    {
                        if (j == tailX[k] && i == tailY[k])
                        {
                            yes = 1;
                            printf("o");
                        }
                    }
                    if (yes == 0)
                        printf(" ");
                }
            }
        }
        printf("\n");
    }
}

void input()
{
    if (kbhit())
    {
        switch (getch())
        {
        case 'a':
            flag = 1;
            break;
        case 's':
            flag = 2;
            break;
        case 'w':
            flag = 3;
            break;
        case 'z':
            flag = 4;
            break;

        case 'P':
            gameOver = 1;
            break;
        }
    }
}

void Move()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < CountTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (flag)
    {
    case 1:
        x--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y--;
        break;
    case 4:
        y++;
        break;
    default:
        break;
    }
    if (x < 0 || x > width || y > height || y < 0)
    {
        gameOver = 1;
    }
    if (x == fruitY && y == fruitX)
    {
    label3:
        fruitX = rand() % 20;
        if (fruitX == 0)
        {
            goto label3;
        }

    label4:
        fruitY = rand() % 20;
        if (fruitY == 0)
        {
            goto label4;
        }
        score += 10;
        CountTail++;
    }
}

int main()
{
label5:
    setup();
    while (!gameOver)
    {
        draw();
        input();
        Move();
        for (int i = 0; i < 1000; i++)
        {
            for (int j = 0; j < 1000; j++)
            {
            }
        }
        for (int l = 0; l < 1000; l++)
        {
            for (int z = 0; z < 100; z++)
            {
            }
        }
        for (int n = 0; n < 1000; n++)
        {
            for (int m = 0; m < 100; m++)
            {
            }
        }
    }
    printf("Your Final score is : %d\n", score);
    char ch;
    printf("Press Y to play again : ");
    scanf("%c", &ch);
    if (ch == 'y' || ch == 'Y')
        goto label5;
    return 0;
}