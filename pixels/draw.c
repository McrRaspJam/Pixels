/*
 * draw.c
 *
 * Functions for drawing shapes onto the canvas.
 */

#include <stdbool.h>
#include "SDL.h"
#include "canvas.h"


/* Draw a single pixel on the canvas */
void draw_pixel(int x, int y, Uint8 r, Uint8 g, Uint8 b)
{
	struct canvas_coordinate coord;
	coord.x = x;
	coord.y = y;

	if (coordinate_validate(&coord) == false)
		return;

	struct canvas_pixel *pixel = canvas_getpixel(coord);

	pixel->r = r;
	pixel->g = g;
	pixel->b = b;
}


/* Draw a rectangle of pixels on the canvas */
void draw_rectangle(int x1, int y1, int x2, int y2,  Uint8 r, Uint8 g, Uint8 b)
{
	int x, y;
	struct canvas_coordinate coord;
	struct canvas_pixel * pixel;

	for (y = y1; y < y2; y++)
		for (x = x1; x < x2; x++) {
			coord.x = x;
			coord.y = y;
			
			if (coordinate_validate(&coord) == false)
				continue;
			
			pixel = canvas_getpixel(coord);
		
			pixel->r = r;
			pixel->g = g;
			pixel->b = b;
		}
}


/* Draw over the whole canvas */
void clear(Uint8 r, Uint8 g, Uint8 b)
{
	Canvas *canvas = canvas_get();

	int x, y;
	struct canvas_coordinate coord;
	struct canvas_pixel * pixel;

	for (y = 0; y < canvas->size_y; y++)
		for (x = 0; x < canvas->size_x; x++) {
			coord.x = x;
			coord.y = y;
			
			pixel = canvas_getpixel(coord);
		
			pixel->r = r;
			pixel->g = g;
			pixel->b = b;
		}
}
