#ifndef LIF_H
# define LIF_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_game
{
    char **board;
    int draw;
    int it;
    int w;
    int h;
    int i;
    int j;

}               t_g;


#endif