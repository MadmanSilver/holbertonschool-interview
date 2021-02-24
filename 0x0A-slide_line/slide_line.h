#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stdlib.h>

int slide_line(int *line, size_t size, int direction);
void right(int *line, size_t size);
void left(int *line, size_t size);

#define SLIDE_LEFT 1
#define SLIDE_RIGHT 0

#endif
