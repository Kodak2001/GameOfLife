#include "zapis.h"
#include <stdio.h>


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