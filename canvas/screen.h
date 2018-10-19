#ifndef SCREEN_H_INCLUDED

#define SCREEN_H_INCLUDED

struct window_settings {
	int w;
	int h;
	int scalefactor;
};

int rounddown(int value);
int screen_calculatescalefactor (int width, int height);
struct window_settings screen_getwindowsettings (int width, int height);
bool screen_closebuttonpressed();
void screen_setup(int width, int height);
void screen_update();
void screen_cleanup();

#endif
