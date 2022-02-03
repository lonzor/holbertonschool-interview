#include "slide_line.h"

/**
 * move_right - slides numbers to the right
 * @line: pointer to int array
 * @size: count of the elements in an array
 */
void move_right(int *line, size_t size)
{
	size_t x, y;
	size_t z = 0;
	size_t j = 0;

	for (x = size; x > 0; x--)
	{
		z = x - 1;
		for (y = z; y > 0; y--)
		{
			j = y - 1;
			if (line[z] != 0)
			{
				if (line[z] == line[j])
				{
					line[z] = line[z] + line[j];
					line[j] = 0;
					break;
				}
				if (line[z] != line[j] &&
				    line[j] != 0)
					break;
			}
			if (line[z] == 0)
			{
				if (line[j] != 0)
				{
					line[z] = line[j];
					line[j] = 0;
					x++;
					break;
				}
			}
		}
	}
}

/**
 * move_left - slides numbers to the left
 * @line: pointer to int array
 * @size: count of the elements in an array
 */
void move_left(int *line, size_t size)
{
	size_t x, y, z;

	for (x = 0, y = 0; x < size;)
	{
		if (line[x] == 0)
			while (line[x] == 0)
				x++;
		if (x == (size - 1))
			break;

		y = x + 1;
		if (line[y] == 0)
			while (line[y] == 0)
				y++;

		if (line[x] == line[y])
		{
			line[x] = line[x] + line[y];
			line[y] = 0;
			x = y + 1;
		}
		else
			x++;
		y = 0;
	}

	for (x = 0, z = 0; x < size; x++)
		if (line[x] != 0)
			line[z++] = line[x];
	while (z < size)
		line[z++] = 0;
}

/**
 * slide_line - merges an array of ints
 * @line: pointer to array element
 * @size: count of the elements in an array
 * @direction: the direction the function will slide
 * Return: 1 if success, and 0 if fail
 */
int slide_line(int *line, size_t size, int direction)
{
	if ((direction != SLIDE_LEFT) && (direction != SLIDE_RIGHT))
		return (0);

	if (direction == 0)
		move_left(line, size);
	if (direction == 1)
		move_right(line, size);
	return (1);
}
