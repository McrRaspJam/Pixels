#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "SDL.h"

#include "canvas/canvas.h"
#include "canvas/screen.h"
#include "canvas/draw.h"


int main(int argc, char *argv[])
{
	int width = 8;
	int height = 8;

	canvas_create(width, height);

	screen_setup(width, height);

	/* ----- Write your program below ----- */

	int x, y;
	
	for (y = 1; y < 7; y++)
		for (x = 1; x < 7; x++)
		{
			Uint8 r = 255;
			Uint8 g = 128;
			Uint8 b = 0;

			draw_pixel(x, y, r, g, b);
		}

	screen_update();
	sleep(1);
	
	/* ------------------------------------ */

	screen_cleanup();

	return 0;
}
