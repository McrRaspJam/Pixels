#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include "SDL.h"

#include "canvas.h"
#include "screen.h"

#define MAX_SCALEFACTOR 64

SDL_Window *window;
SDL_Surface *window_surface;
SDL_Renderer *renderer;
int scalefactor;


/* Returns next lowest power of two e.g. 53 -> 32 */
int rounddown(int value)
{
	int newscale = MAX_SCALEFACTOR;
	
	while ((newscale > value) && (newscale > 1))
		newscale = newscale / 2;

	return newscale;
}


/* Calculates the largest scale factor that will fit on-screen. */
int screen_calculatescalefactor(int width, int height)
{
	SDL_DisplayMode dm;
	
	if (SDL_GetDesktopDisplayMode(0, &dm) != 0) {
		SDL_Log("SDL_GetDesktopDisplayMode Failed");
		return 1;
	}
	
	/* Leave some space for window decorations */
	dm.w = dm.w - 64;
	dm.h = dm.h - 64;

	int scale_width = dm.w / width;
	int scale_height = dm.h / height;

	int scale_final = scale_width;
	if (scale_width > scale_height)
		scale_final = scale_height;
	
	return rounddown(scale_final);
}


/* Calculate the window settings */
void screen_calcwindowsettings (int width, int height, int *win_width, int *win_height, int *scalefactor)
{
	*scalefactor = screen_calculatescalefactor(width, height);
	*win_width = width * *scalefactor;
	*win_height = height * *scalefactor;
}


/* Checks SDL event for window closing */
bool screen_closebuttonpressed()
{
	SDL_Event e;
	
	while (SDL_PollEvent(&e))
		if (e.type == SDL_QUIT)
			return true;
	
	return false;
}


/* Setup an SDL window in the standard way */
int screen_setup(int width, int height)
{
	SDL_LogSetPriority(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO);

	/* Initialise SDL */
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_Init fail : %s\n", SDL_GetError());
		return -1;
	}

	/* Create a window */
	int window_width, window_height;
	screen_calcwindowsettings(width, height, &window_width, &window_height, &scalefactor);

	window = SDL_CreateWindow("Canvas", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width, window_height, 0);
	if (!window) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Window creation fail : %s\n",SDL_GetError());
		return -1;
	}

	/* Create the window surface and check the canvas exists */
	window_surface = SDL_GetWindowSurface(window);
	SDL_Surface * canvasget = canvas_get();
	if (canvasget == NULL) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Canvas not created!");
		return -1;
	}

	/* Create the software renderer for the canvas */
	renderer = SDL_CreateSoftwareRenderer(canvas_get());
	if (!renderer) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Render creation for surface fail : %s\n",SDL_GetError());
		return -1;
	}
    
	/* Clear the canvas */
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
}


/* Access function for canvas renderer */
SDL_Renderer * screen_getrenderer()
{
	return renderer;
}


/* Blit the canvas and update window */
void screen_update()
{
	SDL_BlitScaled(canvas_get(), NULL, window_surface, NULL);
	SDL_UpdateWindowSurface(window);
}


/* Last function called by user, so do all cleanup now! */
void screen_cleanup()
{
	canvas_cleanup();
	SDL_Quit();
}
