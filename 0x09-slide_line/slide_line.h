#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

/* Libraries */
#include <stdlib.h>
#include <stdio.h>

/* Macros */
#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

/* Functions */
int slide_line(int *line, size_t size, int direction);

#endif
