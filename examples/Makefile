program: program.c
	gcc -Wall -o program program.c pixels/canvas.c pixels/screen.c pixels/draw.c -I/usr/include/SDL2 -D_REENTRANT -L/usr/lib/arm-linux-gnueabihf -lSDL2

1_pixel: 1_pixel.c
	gcc -Wall -o 1_pixel 1_pixel.c pixels/canvas.c pixels/screen.c pixels/draw.c -I/usr/include/SDL2 -D_REENTRANT -L/usr/lib/arm-linux-gnueabihf -lSDL2

2_line: 2_line.c
	gcc -Wall -o 2_line 2_line.c pixels/canvas.c pixels/screen.c pixels/draw.c -I/usr/include/SDL2 -D_REENTRANT -L/usr/lib/arm-linux-gnueabihf -lSDL2

3_box: 3_box.c
	gcc -Wall -o 3_box 3_box.c pixels/canvas.c pixels/screen.c pixels/draw.c -I/usr/include/SDL2 -D_REENTRANT -L/usr/lib/arm-linux-gnueabihf -lSDL2

4_splash: 4_splash.c
	gcc -Wall -o 4_splash 4_splash.c pixels/canvas.c pixels/screen.c pixels/draw.c -I/usr/include/SDL2 -D_REENTRANT -L/usr/lib/arm-linux-gnueabihf -lSDL2

5_rows: 5_rows.c
	gcc -Wall -o 5_rows 5_rows.c pixels/canvas.c pixels/screen.c pixels/draw.c -I/usr/include/SDL2 -D_REENTRANT -L/usr/lib/arm-linux-gnueabihf -lSDL2

6_avalanche: 6_avalanche.c
	gcc -Wall -o 6_avalanche 6_avalanche.c pixels/canvas.c pixels/screen.c pixels/draw.c -I/usr/include/SDL2 -D_REENTRANT -L/usr/lib/arm-linux-gnueabihf -lSDL2

clean:
	rm -f program 1_pixel 2_line 3_box 4_splash 5_rows 6_avalanche
