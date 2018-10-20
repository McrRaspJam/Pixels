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
	int width = 64;
	int height = 64;

	canvas_create(width, height);

	screen_setup(width, height);

	/* ----- Write your program below ----- */

	int frame = 0;
	bool ascending = true;

	bool exit = false;

	while (exit == false)
	{
		if (screen_closebuttonpressed())
			break;

		int x, y;
		
		for (y = 0; y < height; y++)
			for (x = 0; x < width; x++)
			{
				Uint8 r = 255 - ((255.0 / height) * y);
				Uint8 g = (255.0 / width) * x;
				Uint8 b = frame % 255;

				draw_pixel(x, y, r, g, b);
			}
		
		if (frame >= 254)
			ascending = false;
		else if (frame <= 0)
			ascending = true;

		if (ascending == true)
			frame++;
		else
			frame--;

		screen_update();
		usleep(16700);
	}
	
	/* ------------------------------------ */

	screen_cleanup();

	return 0;
}
