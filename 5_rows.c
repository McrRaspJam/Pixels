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
	int width = 32;
	int height = 32;

	canvas_create(width, height);

	screen_setup(width, height);

	/* ----- Write your program below ----- */

	bool loop = true;
	int frame = 0;

	while (loop == true)
	{
		if (screen_closebuttonpressed() == true)
			loop = false;

		clear(0, 0, 0);

		int x, y;
		int pixels_drawn = 0;
	
		for (y = 0; y < height; y++)
			for (x = 0; x < width; x++)
			{
				Uint8 r = 255 - ((255 / height) * y);
				Uint8 g = (255 / width) * x;
				Uint8 b = (255 / height) * y;

				int limit = (frame % (width * height)) + 1;

				if (pixels_drawn < limit)
				{
					draw_pixel(x, y, r, g, b);
					pixels_drawn++;
				}
				else
					break;
			}
	
		screen_update();
		usleep(15000);

		frame++;
	}
	
	/* ------------------------------------ */

	screen_cleanup();

	return 0;
}
