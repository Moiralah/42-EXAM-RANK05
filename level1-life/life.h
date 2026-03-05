#ifndef LIFE_H
# define LIFE_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_g
{
    char **b;
    int w;
    int h;
    int it;
    int d;
} t_g;

#endif