# Canvas.c


## Create Window `int screen_setup(int width, int height)`

Creates the canvas.

Currently the program only supports a single canvas, and changing the canvas without resetting the window may create unexpected results.

### Parameters
parameter | usage
--- | ---
width | Input width, expected to be the same as the canvas width
height | Input height, expected to be the same as the canvas height

### Example
```
int width = 8;
int height = 8;

create_canvas(width, height);
screen_setup(width, height);
```



## Update Window `void screen_update()`

Transfers the canvas to the window. Should be called after the drawing of each frame has finished.

### Example
```
draw_pixel(3, 4, 255, 0, 0);
draw_pixel(4, 4, 0, 255, 0);
draw_pixel(5, 4, 0, 0, 255);

screen_update();
```



## Window Cleanup `void screen_cleanup()`

Performs required cleanup at the end of your programs. Removes both the canvas and window.

### Example
```
screen_cleanup();
```
