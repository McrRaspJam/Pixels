McrRaspJam Pixels is a C program for drawing pixel graphics. It consists of a number of functions which abstract the functionality of the [Simple DirectMedia Layer](https://www.libsdl.org/) library.

It was designed for use in Raspberry Pi workshops, but should run on any system capable of running SDL.

## Contents

### Function Reference
- [canvas.c](functions/canvas.md)
- [screen.c](functions/screen.md)
- [draw.c](functions/draw.md)

### Workshop

## Installation

On a recent version of Raspbian, install the SDL library with the following commands:

```
$ sudo apt-get update
$ sudo apt-get install libsdl2-dev
```

On other distributions, ensure you have the GNU C compiler and libraries installed:

```
$ sudo apt-get install build-essentials
```

Then, download and extract the [latest file release](https://github.com/McrRaspJam/Pixels/releases/latest) from the GitHub Repo. You can compile the included program with the following command:

```
$ gcc -o program program.c pixels/canvas.c pixels/draw.c screen.c `sdl2-config --cflags --libs`
```
