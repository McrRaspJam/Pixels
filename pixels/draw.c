/*
 * draw.c
 *
 * Functions for drawing shapes onto the canvas.
 */

#include <stdbool.h>
#include "SDL.h"

#include "canvas.h"
#include "screen.h"


/* Draw a single pixel on the canvas */
void draw_pixel(int x, int y, Uint8 r, Uint8 g, Uint8 b)
{
	SDL_Renderer * renderer = screen_getrenderer();

	SDL_SetRenderDrawColor(renderer, r, g, b, 0xFF);
	SDL_RenderDrawPoint(renderer, x, y);
}


/* Draw a rectangle of pixels on the canvas */
void draw_rectangle(int x1, int y1, int x2, int y2,  Uint8 r, Uint8 g, Uint8 b)
{
	SDL_Rect rect;

	if (x2 > x1) {
		rect.x = x1;
		rect.w = x2 - x1;
	} else {
		rect.x = x2;
		rect.w = x1 - x2;
	}

	if (y2 > y1) {
		rect.y = y1;
		rect.h = y2 - y1;
	} else {
		rect.y = y2;
		rect.h = y1 - y2;
	}

	SDL_Renderer * renderer = screen_getrenderer();
	
	SDL_SetRenderDrawColor(renderer, r, g, b, 0xFF);
	SDL_RenderDrawRect(renderer, &rect);
}


/* Draw over the whole canvas */
void clear(Uint8 r, Uint8 g, Uint8 b)
{
	SDL_Renderer * renderer = screen_getrenderer();
	
	SDL_SetRenderDrawColor(renderer, r, g, b, 0xFF);
	SDL_RenderClear(renderer);
}
