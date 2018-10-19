#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include "SDL.h"

#include "canvas.h"

Canvas canvas;

Canvas * canvas_get()
{
	return &canvas;
}


/* Return false if coordinate lies outside canvas */
bool coordinate_validate(Coordinate *coordinate)
{
	bool valid = true;

	if (coordinate->x < 0)
		valid = false;
	else if (coordinate->x >= canvas.size_x)
		valid = false;
	else if (coordinate->y < 0)
		valid = false;
	else if (coordinate->y >= canvas.size_y)
		valid = false;

	return valid;
}


/* Clip coordinate to canvas size */
void coordinate_bound(Coordinate *coordinate)
{
	if (coordinate->x < 0)
		coordinate->x = 0;
	else if (coordinate->x >= canvas.size_x)
		coordinate->x = canvas.size_x - 1;

	if (coordinate->y < 0)
		coordinate->y = 0;
	else if (coordinate->y >= canvas.size_y)
		coordinate->y = canvas.size_y - 1;
}


/* Return pointer to a canvas pixel */
struct canvas_pixel * canvas_getpixel(Coordinate coordinate)
{
	coordinate_bound(&coordinate);
	return canvas.pixels + ((coordinate.y * canvas.size_y) + coordinate.x);
}

/*
 * Allocate the canvas array to a given pixel value
 */
void canvas_create(int width, int height)
{
	if (canvas.allocated == true) {
		free(canvas.pixels);
		canvas.allocated = false;
	}

	struct canvas_pixel defaultpixel;
	defaultpixel.r = 0x00;
	defaultpixel.g = 0x00;
	defaultpixel.b = 0x00;

	canvas.size_x = width;
	canvas.size_y = height;
	
	canvas.pixels = (struct canvas_pixel *) malloc((width * height) * sizeof(struct canvas_pixel));
	canvas.allocated = true;

	int i;
	int j;
	for (j = 0; j < height; j++)
		for (i = 0; i < width; i++)
			*(canvas.pixels + ((j * width) + i)) = defaultpixel;
}
