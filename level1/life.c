#include "life.h"

// -------------------- Init game --------------------

int init_game(t_game *game, char **av)
{
	// init t_game
	game->width = atoi(av[1]);
	game->height = atoi(av[2]);
	game->iterations = atoi(av[3]);
	game->alive = 'O';
	game->dead = ' ';
	game->i = 0;
	game->j = 0;
	game->draw = 0;

	// Allocate board
	game->board = malloc(game->height * sizeof(char *));
	if (!game->board)
		return -1;

	// alloc each broad row
	int i = 0;
	while (i < game->height)
	{
		// alloc every row
		game->board[i] = malloc(game->width * sizeof(char));
		if (!game->board[i])
			return (free_board(game), -1);

		// set all cells to dead
		int j = 0;
		while (j < game->width)
		{
			game->board[i][j] = game->dead;
			j++;
		}
		i++;
	}
	return 0;
}

// -------------------- Parse --------------------

void parse(t_game *game)
{
	// declare var
	char c;

	// read
	while (read(STDIN_FILENO, &c, 1) == 1)
	{
		// navigate based on the key input wsad
		if (c == 'w' && game->i > 0)
			game->i--;
		else if (c == 's' && game->i < game->height - 1)
			game->i++;
		else if (c == 'a' && game->j > 0)
			game->j--;
		else if (c == 'd' && game->j < game->width - 1)
			game->j++;
		else if (c == 'x')
			game->draw = !game->draw;

		// set alive
		if (game->draw && (c == 'x' || c == 'w' || c == 'a' || c == 's' || c == 'd'))
			game->board[game->i][game->j] = game->alive;
	}
}
// -------------------- Count neighbors --------------------

int count_neighbors(t_game *g, int r, int c)
{
	int n = 0;

	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if ((i || j) &&
				r + i >= 0 && r + i < g->height &&
				c + j >= 0 && c + j < g->width &&
				g->board[r + i][c + j] == g->alive)
				n++;

	return n;
}
// -------------------- Executing --------------------

int execute(t_game *game)
{
	// prepare temp
	char **temp = malloc(game->height * sizeof(char *));
	if (!temp)
		return -1;

	int i = 0;
	while (i < game->height)
	{
		temp[i] = malloc(game->width * sizeof(char));
		if (!temp[i])
			return -1;
		i++;
	}

	// apply game rules
	i = 0;
	while (i < game->height)
	{
		int j = 0;
		while (j < game->width)
		{
			// get count
			int n = count_neighbors(game, i, j);

			// check alive and set temp
			if (game->board[i][j] == game->alive)
				temp[i][j] = (n == 2 || n == 3) ? game->alive : game->dead;
			else
				temp[i][j] = (n == 3) ? game->alive : game->dead;
			j++;
		}
		i++;
	}

	// free board and reset it to temp
	free_board(game);
	game->board = temp;
	return 0;
}

// -------------------- Print & Free --------------------
void print_board(t_game *game)
{
	int i = 0;
	while (i < game->height)
	{
		int j = 0;
		while (j < game->width)
		{
			putchar(game->board[i][j]);
			j++;
		}
		putchar('\n');
		i++;
	}
}

void free_board(t_game *game)
{
	if (game->board)
	{
		int i = 0;
		while (i < game->height)
		{
			if (game->board[i])
				free(game->board[i]);
			i++;
		}
		free(game->board);
	}
}

// -------------------- Main --------------------
int main(int argc, char **av)
{
	if (argc != 4)
		return 1;

	t_game game;
	if (init_game(&game, av) == -1)
		return 1;

	parse(&game);

	int iter = 0;
	while (iter < game.iterations)
	{
		if (execute(&game) == -1)
		{
			free_board(&game);
			return 1;
		}
		iter++;
	}

	print_board(&game);
	free_board(&game);
	return 0;
}
