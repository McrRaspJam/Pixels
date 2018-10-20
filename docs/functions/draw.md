# Draw.c



## Draw Pixel `void draw_pixel(int x, int y, Uint8 r, Uint8 g, Uint8 b)`
Draws a single pixel on the canvas

### Parameters
parameter | usage
--- | ---
x | The x coordinate of the pixel to be drawn
y | The y coordinate of the pixel to be drawn
r | The red component of the pixel colour (0-255)
g | The green component of the pixel colour (0-255)
b | The blue component of the pixel colour (0-255)

### Example
```
draw_pixel(4, 4, 213, 204, 197);
```



## Draw Rectangle `void draw_rectangle(int x1, int y1, int x2, int y2,  Uint8 r, Uint8 g, Uint8 b)`
Draws a rectangle on the canvas

### Parameters
parameter | usage
--- | ---
x1 | The x coordinate of the top left corner of the rectangle
y1 | The y coordinate of the top left corner of the rectangle
x2 | The x coordinate of the bottom right corner of the rectangle
y2 | The y coordinate of the bottom right corner of the rectangle
r | The red component of the pixel colour (0-255)
g | The green component of the pixel colour (0-255)
b | The blue component of the pixel colour (0-255)

### Example
```
draw_rectangle(1, 1, 7, 7, 213, 204, 197);
```



## Clear Canvas `clear(Uint8 r, Uint8 g, Uint8 b)`
Draw over the entire canvas

### Parameters
parameter | usage
--- | ---
r | The red component of the pixel colour (0-255)
g | The green component of the pixel colour (0-255)
b | The blue component of the pixel colour (0-255)

### Example
```
clear(0, 0, 0);
```
