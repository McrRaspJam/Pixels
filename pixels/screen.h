#ifndef SCREEN_H_INCLUDED

#define SCREEN_H_INCLUDED

struct window_settings {
	int w;
	int h;
	int scalefactor;
};

int rounddown(int value);
int screen_calculatescalefactor(int width, int height);
void screen_calcwindowsettings (int width, int height, int *win_width, int *win_height, int *scalefactor);
bool screen_closebuttonpressed();
int screen_setup(int width, int height);
SDL_Renderer * screen_getrenderer();
void screen_update();
void screen_cleanup();

#endif
