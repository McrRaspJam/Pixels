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

	bool loop = true;
	int frame = 0;

	while (loop == true)
	{
		if (screen_closebuttonpressed() == true)
			loop = false;
		else if (frame > 1000)
			loop = false;

		int x, y;
		for(y = 0; y < height; y++)
			for(x= 0; x < width; x++) {
				Uint8 r = (255 / (float)width) * x;
				Uint8 g = (255 / (float)height) * y;
				Uint8 b = (Uint8) frame % 255;
			
				draw_pixel(x, y, r, g, b);
			}
		
		screen_update(canvas_get(), frame);
	
	frame = frame + 1;
	}

	screen_cleanup();

	return 0;
}
