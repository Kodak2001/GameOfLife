#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int game_1[7][7] = {{0,0,0,0,0,0,0},
{0,0,0,0,0,0,0},
{0,0,0,0,0,0,0},
{0,0,0,0,0,0,0},
{0,0,0,0,0,0,0},
{0,0,0,0,0,0,0},
{0,0,0,0,0,0,0}

};
int game_2[7][7] = {{0,0,0,0,0,0,0},
{0,0,0,1,0,0,0},
{0,0,1,0,0,0,0},
{0,0,1,0,1,0,0},
{0,1,1,1,0,0,0},
{0,0,0,0,1,0,0},
{0,0,0,0,0,0,0}

};

void birth_death(int column, int row, int game_prev[7][7], int game_next[7][7])
{
    int i, j, m, n, alive;
    for(i = 1; i < column+1;i++)
    {
        for(j = 1; j < row+1; j++)
        {   
            alive = 0;
            for(m = i-1; m <= i+1; m++)
            {
                for(n = j-1; n <= j+1; n++)
                {
                    if(game_prev[m][n] == 1) alive++;
                    
                }
            }
            if(alive == 3 && game_prev[i][j] == 0) game_next[i][j] = 1;
            if(alive != 3 && alive != 4 && game_prev[i][j]) game_next[i][j] = 0;        
        }
    }
}

void equal(int column, int row, int copy_from[7][7], int copy_to[7][7])
{
    int i, j;
    for(i = 1; i < column+1; i++)
    {
        for(j = 1; j < row+1; j++)
        {
            copy_to[i][j] = copy_from[i][j];
        }
    }
}

int main()
{
    int column = 5, row = 5, i, j,m;

    for(m = 0; m < 10; m++)
    {
        birth_death(column,row, game_1, game_2);
        equal(column, row, game_2, game_1);
            printf("\n");
    for(i = 1; i < column+1; i++)
        {
        for(j = 1; j < row+1;j++)
        {
            printf("%d ",game_2[i][j]);
        }
        printf("\n");
        }
    }    
    return 0;

}