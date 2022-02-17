#include "menger.h"

/**
 * menger - 2D menger sponge
 * @level: level of the menger sponge
 */

void menger(int level)
{
	int size, row, column;
	char character;

	size = pow(3, level);

	for (row = 0; row < size; row++)
	{
		for (column = 0; column < size; column++)
		{
			character = get_symbols(row, column);
			printf("%c", character);
		}
		printf("\n");
	}
}
/**
 * get_symbols - get the character/symbol
 * @row: the row of the sponge
 * @column: the columns of the sponge
 * Return: a hastag
 */
char get_symbols(int row, int column)
{
	while (row || column)
	{
		if (row % 3 == 1 && column % 3 == 1)
			return (' ');
		row /= 3;
		column /= 3;
	}
	return ('#');
}
