#ifndef CANVAS_H_INCLUDED

#define CANVAS_H_INCLUDED

void canvas_create(int width, int height);
SDL_Surface * canvas_get();
void canvas_cleanup();

#endif
