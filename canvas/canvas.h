#ifndef CANVAS_H_INCLUDED

#define CANVAS_H_INCLUDED

struct canvas_struct {
	int	size_x;
	int	size_y;
	struct canvas_pixel *pixels;
	bool	allocated;	
};

struct canvas_coordinate {
	int x;
	int y;
};

struct canvas_pixel {
	Uint8	r;
	Uint8	g;
	Uint8	b;
};

typedef struct canvas_struct Canvas;
typedef struct canvas_coordinate Coordinate;

Canvas * canvas_get();
bool coordinate_validate(Coordinate *coordinate);
void coordinate_bound(Coordinate *coordinate);
struct canvas_pixel * canvas_getpixel(Coordinate coordinate);
void canvas_create(int width, int height);

#endif
