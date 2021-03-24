#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "gifenc.h"
#include "fun_main.h"


int main(int argc, char **argv)
{
    if(argv[1][0] == 'h')
    {
        printf("Zasady wywolania: ilosc_cykli, plik_dane, format_graficzny_p(ppm)/g(gif)/A(oba) \n");
        return 0;
    }
    FILE *dane = fopen(argv[2], "r");
    int column, row;
    fscanf(dane, "%d %d", &row, &column);
    int game_1[row+2][column+2], game_2[row+2][column+2];
    int n = atoi(argv[1]);
    data_to_array(dane, column, row, game_1, game_2);
        ge_GIF *gif = ge_new_gif(
            "gameoflife.gif",  
            column * 10, row * 10,           
            (uint8_t []) {  
                0xFF, 0xFF, 0xFF, 
                0x00, 0x00, 0x00, 

            },
            1,              
            0               
        );   
    for(; n > 0; n--)
    {
        birth_death(column, row, game_1, game_2);
        equal(column, row , game_2, game_1);
        zapis(column, row, game_1);
        if(argv[3][0]=='g'||argv[3][0]=='A')
        {
            gif_add_frame(gif, column, row, game_1);
            ge_add_frame(gif, 10);
        }
        if(argv[3][0]=='p'||argv[3][0]=='A')
            img_ppm(column, row, game_1, n);        
    }
    ge_close_gif(gif);
    return 0;

}
