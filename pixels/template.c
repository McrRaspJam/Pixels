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
	
	screen_update();
	sleep(1);
	
	/* ------------------------------------ */

	screen_cleanup();

	return 0;
}
