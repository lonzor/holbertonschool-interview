#include "sandpiles.h"

/**
 * grid_sum - sum of two grids
 * @grid1: first grid
 * @grid2: second grid
 * Return: void
 */
static void grid_sum(int grid1[3][3], int grid2[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++)
			grid1[x][y] = grid1[x][y] + grid2[x][y];
}

/**
 * print_grid - print a grid of 3x3
 * @grid: grid to be printed
 * Return: void
 */
static void print_grid(int grid[3][3])
{
	int x, y;

	printf("=\n");

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (y)
				printf(" ");
			printf("%d", grid[x][y]);
		}
		printf("\n");
	}
}

/**
 * check_valid - checks if sandpile is valid or not
 * @grid: grid being checked
 * Return: 0 if unstable and 1 if stable
 */
static int check_valid(int grid[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (grid[x][y] > 3)
				return (0);
		}
	}
	return (1);
}

/**
  * topple - does the "topple" process
  * @grid: grid where the toppling happens
  * Return: void
  */
static void topple(int grid[3][3])
{
	int i, j;
	int count = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			count++;
			if (grid[i][j] > 3)
			{
				grid[i][j] = grid[i][j] - 4;
				if ((i - 1 >= 0) && (i - 1 < 3))
					grid[i - 1][j] += 1;
				if ((i + 1 >= 0) && (i + 1 < 3))
					grid[i + 1][j] += 1;
				if ((j - 1 >= 0) && (j - 1 < 3))
					grid[i][j - 1] += 1;
				if ((j + 1 >= 0) && (j + 1 < 3))
					grid[i][j + 1] += 1;
			}
		}
	}
}

/**
 * sandpiles_sum - gets sum of two sandpiles
 * @grid1: sandpile 1 that is stable
 * @grid2: another sandpile that is stable
 * Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	grid_sum(grid1, grid2);

	while (!check_valid(grid1))
	{
		print_grid(grid1);
		topple(grid1);
	}
}
