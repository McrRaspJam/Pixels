/* canvas.c -- The Canvas
 *
 * The Canvas is an SDL surface which is used as the "virtual image" for user
 * progams. It is scaled up to fit the window.
 *
 * Draw functions create pixels on the Canvas, and Screen updates blit the
 * surface to the window
 */

#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include "SDL.h"

#include "canvas.h"

SDL_Surface * canvas;


/* Initialise and allocate the Canvas */
void canvas_create(int width, int height)
{
	if (canvas != NULL)
		canvas_cleanup();

	canvas = SDL_CreateRGBSurface(0,
			width,
			height,
			32,
			0xff000000,
			0x00ff0000,
			0x0000ff00,
			0x000000ff);
}


/* Variable accessor */
SDL_Surface * canvas_get()
{
	return canvas;
}


/* Free the Canvas */
void canvas_cleanup()
{
	SDL_FreeSurface(canvas);
}
