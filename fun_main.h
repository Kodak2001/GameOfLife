#ifndef FUN_MAIN_H
#define FUN_MAIN_H

#include <stdio.h>

void birth_death(int column, int row, int game_prev[row + 2][column + 2],
	int game_next[row + 2][column + 2]);

void equal(int column, int row, int copy_from[row + 2][column + 2],
	int copy_to[row + 2][column + 2]);

void data_to_array(FILE* dane, int column, int row, int game_1[row + 2][column + 2],
	int game_2[row + 2][column + 2]);


#endif
