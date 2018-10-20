# Window setup and cleanup

The chosen functionality of SDL has been abstracted in McrRaspJam Pixels into two components, the **canvas** and the **window**.

## The canvas

The canvas is the "virtual image" that will be displayed in a desktop window. It is usually a small size, which is then upscaled to fit a large window on-screen.

The canvas is created with `canvas_create()` and deleted during window cleanup. (see below)

## The window

The windows size is determined using the canvas size. To preserve pixel aspect ratio, the resolution of the canvas is doubled as many times as can still fit on the desktop.

The window is created during `screen_setup()` and removed along with the canvas during `screen_cleanup()`. The window contents will not update until you call `screen_update()`.

## Template Program

The following headers are included in the example files: (Not all of the standard library headers are required)

```
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include "SDL.h"
#include "pixels/canvas.h"
#include "pixels/screen.h"
#include "pixels/draw.h"
```

Begin your program by creating the canvas and window (providing the same parameter values for both methods).

```
int main(int argc, char *argv[])
{
        int width = 8;
        int height = 8;

        canvas_create(width, height);
        screen_setup(width, height);
```

Then, you can call whichever draw functions you wish. At the end of the "frame" you should call `screen_update()` to push the pixels from the canvas to the window.

When working with a single frame, you should call `sleep()` before running cleanup, otherwise your window will close immediately when the program is executed.

If working with multiple frames, the simple loop shown below can be used. `usleep()` takes a microsecond delay as the parameter, so `16777` will produce 60 frames per second (minus execution time per frame). `screen_closebuttonpressed()` returns true if the close window button has been pressed, which can be used to escape the loop.

```
        while (exit == false)
        {
                if (screen_closebuttonpressed())
                        break;

                // Frame draw calls here


                screen_update();
                usleep(16700);
        }
```

finally, perform the required cleanup by calling `screen_cleanup()` and closing the program.

```
        screen_cleanup();
        return 0;
}
```
