
#ifndef LIFE_H
# define LIFE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_game
{
	int width;
    int height;
    int iterations;
    char alive;
    char dead;
    int i;
    int j;
    int draw;
	char **board;
}			 t_game;

void print_board(t_game* game);
void free_board(t_game* game);

#endif
