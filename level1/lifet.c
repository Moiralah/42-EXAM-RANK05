#include "lifet.h"

void free_2d(char **ar)
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

void draw_2d(char **ar)
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

int init(t_g *game, char **av)
{
    game->width = atoi(av[1]);
    game->height = atoi(av[2]);
    game->it = atoi(av[3]);

    game->board = malloc((game->height + 1) * sizeof(char *));
    if(!game->board)
        return 1;
    
    int i = 0;
    while (i < game->height)
    {
        game->board[i] = malloc((game->width + 1) * sizeof(char));
        if(!game->board[i])
            return 1;
        int j = 0;
        while (j < game->width)
        {
            
            game->board[i][j] = ' ';
            j++;
        }
        i++;
    }
    return 0;
}

void parse(t_g *game)
{
    char c;

    while(read(0, &c, 1) == 1)
    {
        if(c == 'w' && game->i > 0)
            game-> i--;
        else if(c == 's' && game->i < game->height -1 )
            game-> i++;
        else if(c == 'a' && game->j > 0)
            game-> j--;
        else if(c == 'd' && game->j < game->width -1 )
            game-> j++;
        else if (c == 'x')
            game->draw = !game->draw;
        if(game->draw)
            game->board[game->i][game->j] = '0';
    }
}

int count_neighbour(t_g *game, int i, int j)
{
    int n = 0;
    for (int x = -1; x <= 1; x++)
        for(int y = -1; y <= 1; y++)
            if((x || y) &&
                i + x >= 0 && i + x < game->height &&
                j + y >= 0 && j + y < game->width &&
                game->board[i + x][j + y] == '0')
                n++;
    return n;
}

int execute(t_g *game)
{
    char** temp = malloc((game->height + 1) * sizeof(char *));
    if(!temp)
        return 1;
    int i = 0;
    while(i < game->height)
    {
        temp[i] = malloc((game->width + 1) * sizeof(char));
        if(!temp[i])
            return(1);
        i++;
    }

    i = 0;
    while(i < game->height)
    {
        int j = 0;
        while(j < game->width)
        {
            int n = count_neighbour(game, i, j);
            if(game->board[i][j] == '0')
                temp[i][j] = (n == 2 || n == 3) ? '0' : ' ';
            else
                temp[i][j] = (n == 3) ? '0' : ' ';
            j++;
        }
        i++;
    }
    free_2d(game->board);
    game->board = temp;
    return 0;
}

int main(int ac, char **av)
{
    t_g game;

    if (ac != 4)
        return(1);
    
    game = (t_g){0};
    if (init(&game, av) == 1)
        return 1;

    parse(&game);
    
    int iter = 0;
    while (iter < game.it)
    {
        if(execute(&game) == 1)
        {
            free_2d(game.board);
            return 1;
        }
        iter++;
    }
    draw_2d(game.board);
    free_2d(game.board);
    return 0;
}