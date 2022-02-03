#include "slide_line.h"

/**
 * move_right - slides numbers to the left
 * @line: pointer to int array
 * @size: count of the elements in an array
 */
void move_right(int *line, size_t size)
{
	size_t x, y;

	for (x = size; x > 0; x--)
	{
		for (y = x - 1; y > 0; y--)
		{
			if (line[x - 1] != 0)
			{
				if (line[x - 1] == line[y - 1])
				{
					line[x - 1] = line[x - 1] + line[y - 1];
					line[y - 1] = 0;
					break;
				}
				if (line[x - 1] != line[y - 1] &&
				    line[y - 1] != 0)
					break;
			}
			if (line[x - 1] == 0)
			{
				if (line[y - 1] == 0)
				{
					line[x - 1] = line[y - 1];
					line[y - 1] = 0;
					x++;
					break;
				}
			}
		}
	}
}

/**
 * move_left - slides numbers to the right
 * @line: pointer to int array
 * @size: count of the elements in an array
 */
void move_left(int *line, size_t size)
{
	size_t x, y, z;

	for (x = 0; y = 0; x < size;)
	{
		if (line[x] == 0)
			for (; line[x] == 0)
				y++;
		if (x == size - 1)
			break;
		y = x + 1;
		if (line[y] == 0)
			for (; line[y] == 0)
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

	for (x = 0; z = 0; x < size; x++)
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
	if (line == NULL || size < 1)
		return (0);
	if (direction == 0)
		move_left(line, size);
	if (direction == 1)
		move_right(line, size);
	return (1);
}
