# Canvas.c


## Create Canvas `void canvas_create(int width, int height)`

Creates the canvas.

Currently the program only supports a single canvas, and changing the canvas without resetting the window may create unexpected results.

### Parameters
| parameter | usage |
| --- | --- |
| width | The width of the canvas image |
| height | The height of the canvas image |

### Example
```
create_canvas(8, 8);
```
