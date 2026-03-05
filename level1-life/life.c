#include "life.h"

void free2d(char **ar)
{
    int i = 0;
    while(ar[i])
    {
        free(ar[i]);
        i++;
    }
    free(ar);
    ar = NULL;
}

void draw2d(char **ar)
{
    int i = 0;
    while(ar[i])
    {
        int j = 0;
        while(ar[i][j])
        {
            putchar(ar[i][j]);
            j++;
        }
        putchar('\n');
        i++;
    }
}

int init(t_g *g, char **av)
{
    g->w = atoi(av[1]);
    g->h = atoi(av[2]);
    g->it = atoi(av[3]);
    g->d = 0;

    g->b = malloc((g->h + 1) * sizeof(char *));
    if(!g->b)
        return 1;
    int i = 0;
    while(i < g->h)
    {
        g->b[i] = malloc((g->w + 1) * sizeof(char));
        if(!g->b[i])
            return 1;
        int j = 0;
        while (j < g->w)
        {
            g->b[i][j] = ' ';
            j++;
        }
        i++;
    }
}

int count(int i, int j, t_g *g)
{
    int n = 0;
    for(int x = -1; x <= 1; x++)
        for(int y = -1; y <= 1; y++)
            if( (x || y) &&
                (x+i) >= 0 && x+i < g->h &&
                (y+j) >= 0 && y+j < g->w &&
                g->b[x+i][y+j] == '0'
                )
                n++;
    return n;
}

int execute(t_g *g)
{
    char **temp = malloc((g->h + 1) * sizeof(char *));
    if(!temp)
        return 1;
    int i = 0;
    while(i < g->h)
    {
        temp[i] = malloc((g->w + 1) * sizeof(char));
        if(!temp[i])
            return 1;
        i++;
    }

    i = 0;
    while (i < g->h)
    {
        int j = 0;
        while(j < g->w)
        {
            int n = count(i, j, g);
            if (g->b[i][j] == '0')
                temp[i][j] = (n == 2 || n == 3) ? '0': ' ';
            else
                temp[i][j] = (n == 3) ? '0': ' ';
            j++;
        }
        i++;
    }
    free2d(g->b);
    g->b = temp;
    return 0;
}

void parse(t_g *g)
{
    char c;
    int i = 0;
    int j = 0;

    while(read(STDIN_FILENO, &c, 1) == 1)
    {
        if (c == 'w' && i > 0)
            i--;
        if (c == 's' && i < g->h - 1)
            i++;
        if (c == 'a' && j > 0)
            j--;
        if (c == 'd' && j < g->w - 1)
            j++;
        if (c == 'x')
            g->d = !g->d;
        if (g->d)
            g->b[i][j] = '0';
    }
}

int main(int ac, char **av)
{
    if (ac != 4)
        return(1);

    t_g g;
    if (init(&g, av) == 1)
        return(1);
    parse(&g);

    int i = 0;
    while(i < g.it)
    {
        if(execute(&g) == 1)
            return(free2d(g.b), 1);
        i++;
    } 
    draw2d(g.b);
    free2d(g.b);
    return 0;
}