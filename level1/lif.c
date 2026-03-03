#include "lif.h"

void free2d(char **str)
{
    int i = 0;
    while(str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
    str = NULL;
}

void draw2d(char **str)
{
    int i = 0;
    while(str[i])
    {
        int j = 0;
        while(str[i][j])
        {
            putchar(str[i][j]);
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

    g->board = malloc((g->h + 1) * (sizeof(char*)));
    if(!g->board)
        return 1;
    int i = 0;
    while(i < g->h)
    {
        g->board[i] = malloc((g->w + 1) * (sizeof(char)));
        if(!g->board[i])
        {
            free2d(g->board);
            return 1;
        }

        int j = 0;
        while(j < g->w)
        {
            g->board[i][j] = ' ';
            j++;
        }
        i++;
    }
}

void parse(t_g *g)
{
    char c;

    while(read(STDIN_FILENO, &c, 1) == 1)
    {
        if (c == 'w' && g->i > 0)
            g->i--;
        if (c == 's' && g->i < g->h - 1)
            g->i++;
        if (c == 'a' && g->j > 0)
            g->j--;
        if (c == 'd' && g->j < g->w - 1)
            g->j++;
        if (c == 'x')
            g->draw = !g->draw;
        if(g->draw)
            g->board[g->i][g->j] = '0';
    }
}

int count(t_g *g, int i, int j)
{
    int n = 0;
    for(int x = -1; x <= 1; x++)
        for(int y = -1; y <= 1; y++)
            if((x || y) &&
                (x + i) >= 0 && (x+i) < g->h &&
                (y + j) >= 0 && (y+j) < g->w &&
                g->board[i+x][y+j] == '0')
                n++;
    return n;
}

int execute(t_g *g)
{
    char **temp = malloc((g->h + 1) * (sizeof(char*)));
    if(!temp)
        return 1;
    int i = 0;
    while(i < g->h)
    {
        temp[i] = malloc((g->w + 1) * (sizeof(char)));
        if(!temp[i])
        {
            free2d(temp);
            return 1;
        }
        i++;
    }

    i = 0;
    while (i < g->h)
    {
        int j = 0;
        while(j < g->w)
        {
            int n = count(g, i, j);
            if(g->board[i][j] == '0')
                temp[i][j] = (n == 2 || n == 3) ? '0' : ' ';
            else
                temp[i][j] = (n == 3) ? '0' : ' ';
            j++;
        }
        i++;
    }
    free2d(g->board);
    g->board = temp;
}

int main(int ac, char **av)
{
    t_g g;

    g = (t_g){0};
    if(init(&g, av) == 1)
        return(1);
    parse(&g);

    int iter = 0;
    while(iter < g.it)
    {
        if(execute(&g) == 1)
        {
            free2d(g.board);
            return(1);
        }
        iter++;
    }
    draw2d(g.board);
    free2d(g.board);
    return 0;
}
