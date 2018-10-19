#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include "SDL.h"

#include "pixels/canvas.h"
#include "pixels/screen.h"
#include "pixels/draw.h"


int main(int argc, char *argv[])
{
	int width = 128;
	int height = 128;

	int avalanche[128];
	int i;
	for (i = 0; i < 128; i++)
		avalanche[i] = 0;

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
		usleep(16777);
	}
	
	/* ------------------------------------ */

	screen_cleanup();

	return 0;
}
