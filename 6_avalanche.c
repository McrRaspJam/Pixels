#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include "SDL.h"

#include "canvas/canvas.h"
#include "canvas/screen.h"
#include "canvas/draw.h"


int main(int argc, char *argv[])
{
	int width = 16;
	int height = 16;

	int avalanche[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	srand(time(NULL));

	canvas_create(width, height);

	screen_setup(width, height);

	/* ----- Write your program below ----- */

	bool loop = true;

	while (loop == true)
	{
		if (screen_closebuttonpressed() == true)
			loop = false;

		clear(0, 0, 0);

		int x, y;
	
		for (x = 0; x < height; x++)
		{
			//Lower the "avalanche" by a random amount in each column
			int random = (rand() % 2) + 1;
			avalanche[x] = avalanche[x] + random;
			
			for (y = 0; y < height; y++)
			{
				Uint8 r = 255;
				Uint8 g = 255;
				Uint8 b = 255;

				if (y < avalanche[x])
					draw_pixel(x, y, r, g, b);
				else
					break;
			}
		}

		screen_update();
		usleep(41666);
	}
	
	/* ------------------------------------ */

	screen_cleanup();

	return 0;
}
