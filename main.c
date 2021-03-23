#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "gifenc.h"
#include "fun_main.h"
/*
void zapis(int column, int row, int game_1[row+2][column+2])
{
	int game_I[row+2][column+2];

	equal(column, row, game_1, game_I);
	int i,j,m;
	FILE *p;
	
	if((p = fopen("stan.txt", "a"))==NULL)
	{
		printf("Nie ma takiego pliku\n");
		exit(1);
	}
	fprintf(p,"\n");
	for(i = 1; i < column+1; i++)
	{
	for(j = 1; j < row+1;j++)
	{
	fprintf(p,"%d ",game_I[i][j]);
	}
	fprintf(p, "\n");
	}
   fclose(p);
   
}
*/
void gif_add_frame(ge_GIF *gif, int column, int row, int game[row+2][column+2])
{
    int i, j, k, l, pixel = 0;
    for(i = 1; i < row + 1; i++)
        {
            for(k = 0; k < 10; k++)
            {
                for(j = 1; j < column + 1; j++)
                {
                    for(l = 0; l < 10; l++)
                    {
                        gif->frame[pixel] = game[i][j];
                       //printf("%d",game_1[i][j]);//
                        pixel++;
                    }
                }
            }
        }
        ge_add_frame(gif, 30);
}

int main(int argc, char **argv)
{
    FILE *dane = fopen("dane.txt", "r");
    int column, row;
    fscanf(dane, "%d %d", &row, &column);
    int game_1[row+2][column+2], game_2[row+2][column+2];
    int n = atoi(argv[1]);
    data_to_array(dane, column, row, game_1, game_2);
    ge_GIF *gif = ge_new_gif(
        "gameoflife.gif",  
        column * 10, row * 10,           
        (uint8_t []) {  
            0x00, 0x00, 0x00, 
            0xFF, 0xFF, 0xFF, 

        },
        1,              
        0               
    );   

    for(; n > 0; n--)
    {
        birth_death(column, row, game_1, game_2);
        equal(column, row , game_2, game_1);
        zapis(column, row, game_1);
        gif_add_frame(gif, column, row, game_1);
        ge_add_frame(gif, 10);        
    }
    ge_close_gif(gif);
    return 0;

}