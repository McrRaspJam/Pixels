#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include "SDL.h"

#include "canvas.h"
#include "screen.h"

#define MAX_SCALEFACTOR 64

SDL_Window *window;
SDL_Surface *surface;
SDL_Renderer *renderer;
struct window_settings current_settings;

/* Returns next lowest power of two e.g. 53 -> 32 */
int rounddown(int value)
{
	int newscale = MAX_SCALEFACTOR;
	
	while ((newscale > value) && (newscale > 1))
		newscale = newscale / 2;

	return newscale;
}


/*
 * Calculates the largest scale factor
 * that will fit on-screen for a given canvas size.
 */
int screen_calculatescalefactor (int width, int height)
{
	SDL_DisplayMode dm;

	//SDL_Init(SDL_INIT_VIDEO);
	
	if (SDL_GetDesktopDisplayMode(0, &dm) != 0) {
		SDL_Log("SDL_GetDesktopDisplayMode Failed");
		return 1;
	}
	
	dm.w = dm.w - 64;
	dm.h = dm.h - 64;	

	int scale_width = dm.w / width;
	int scale_height = dm.h / height;
	int scale_final;

	if (scale_width < scale_height)
		scale_final = scale_width;
	else
		scale_final = scale_height;
	
	/*
	if (scale_final > MAX_SCALEFACTOR)
		scale_final = MAX_SCALEFACTOR;
	printf("Scale Factor:\t%d\n", scale_final);
	*/
	
	return rounddown(scale_final);
}


/* Calculate all the window settings */
struct window_settings screen_getwindowsettings (int width, int height)
{
	struct window_settings ret;

	ret.scalefactor = screen_calculatescalefactor(width, height);
	ret.w = width * ret.scalefactor;
	ret.h = height * ret.scalefactor;

	return ret;
}

bool screen_closebuttonpressed()
{
	SDL_Event e;
	
	while (SDL_PollEvent(&e))
		if (e.type == SDL_QUIT)
			return true;
	
	return false;
}

/* Setup an SDL window in the standard way */
void screen_setup(int width, int height)
{
	SDL_LogSetPriority(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO);

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_Init fail : %s\n", SDL_GetError());
		return;
	}
	
	current_settings = screen_getwindowsettings(width, height);
	int w = current_settings.w;
	int h = current_settings.h;

	window = SDL_CreateWindow("Canvas", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, 0);
	if (!window) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Window creation fail : %s\n",SDL_GetError());
		return;
	}

	surface = SDL_GetWindowSurface(window);
	renderer = SDL_CreateSoftwareRenderer(surface);

	if (!renderer) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Render creation for surface fail : %s\n",SDL_GetError());
		return;
	}
    
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
}


/* Update renderer with canvas, upscaling on the way */
void screen_update()
{
	Canvas *canvas = canvas_get();

	SDL_Rect block;
	block.w = current_settings.scalefactor;
	block.h = current_settings.scalefactor;
	
	int p;
	for (p = 0; p < (canvas->size_x * canvas->size_y); p++) {
		int x = p % canvas->size_x;
		int y = p / canvas->size_x;
		block.x = x * current_settings.scalefactor;
		block.y = y * current_settings.scalefactor;

		struct canvas_pixel *pixel = canvas->pixels + p;
		
		SDL_SetRenderDrawColor(renderer, pixel->r, pixel->g, pixel->b, 0xFF);

		SDL_RenderFillRect(renderer, &block);
	}	
	SDL_UpdateWindowSurface(window);
}


/* Window cleanup */
void screen_cleanup()
{
	SDL_Quit();
}
