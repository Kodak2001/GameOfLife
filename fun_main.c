#include "fun_main.h"
#include <stdio.h>
#include<stdlib.h>


void birth_death(int column, int row, int game_prev[row + 2][column + 2], int game_next[row + 2][column + 2])
{
    int i, j, m, n, alive;
    for (i = 1; i < row + 1; i++)
    {
        for (j = 1; j < column + 1; j++)
        {
            alive = 0;
            for (m = i - 1; m <= i + 1; m++)
            {
                for (n = j - 1; n <= j + 1; n++)
                {
                    if (game_prev[m][n] == 1) alive++;

                }
            }
            if (alive == 3 && game_prev[i][j] == 0) game_next[i][j] = 1;
            if (alive != 3 && alive != 4 && game_prev[i][j]) game_next[i][j] = 0;
        }
    }
}


void zapis(int column, int row, int game_1[row + 2][column + 2])
{
    int game_I[row + 2][column + 2];

    equal(column, row, game_1, game_I);
    int i, j, m;
    FILE* p;

    if ((p = fopen("stan.txt", "a")) == NULL)
    {
        printf("Nie ma takiego pliku\n");
        exit(1);
    }
    fprintf(p, "\n");
    for (i = 1; i < column + 1; i++)
    {
        for (j = 1; j < row + 1; j++)
        {
            fprintf(p, "%d ", game_I[i][j]);
        }
        fprintf(p, "\n");
    }
    fclose(p);

}

void equal(int column, int row, int copy_from[row + 2][column + 2], int copy_to[row + 2][column + 2])
{
    int i, j;
    for (i = 0; i < row + 2; i++)
    {
        for (j = 0; j < column + 2; j++)
        {
            copy_to[i][j] = copy_from[i][j];
        }
    }
}

void data_to_array(FILE* dane, int column, int row, int game_1[row + 2][column + 2], int game_2[row + 2][column + 2])
{
    int i, j;
    for (i = 0; i < column + 2; i++)
    {
        game_1[0][i] = 0;
        game_1[row + 1][i] = 0;
    }
    for (i = 1; i < row + 1; i++)
    {
        game_1[i][0] = 0;
        game_1[i][column + 1] = 0;
        for (j = 1; j < column + 1; j++)
        {
            fscanf(dane, "%d", &game_1[i][j]);
        }
    }
    equal(column, row, game_1, game_2);
}