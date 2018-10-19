#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "SDL.h"

#include "pixels/canvas.h"
#include "pixels/screen.h"
#include "pixels/draw.h"


int main(int argc, char *argv[])
{
	int width = 256;
	int height = 256;

	canvas_create(width, height);

	screen_setup(width, height);

	/* ----- Write your program below ----- */

	int x, y;
	
	for (y = 0; y < height; y++)
		for (x = 0; x < width; x++)
		{
			Uint8 r = 255 - ((255.0 / height) * y);
			Uint8 g = (255.0 / width) * x;
			Uint8 b = (255.0 / height) * y;

			draw_pixel(x, y, r, g, b);
		}

	screen_update();
	sleep(1);
	
	/* ------------------------------------ */

	screen_cleanup();

	return 0;
}
