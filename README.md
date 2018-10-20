# Pixels
A C program for drawing pixels on screen at high refresh rates

[Read the documentation](https://mcrraspjam.github.io/Pixels/)

## About

McrRaspJam Pixels provides a number of functions that abstract the functionality of the [Simple DirectMedia Layer](https://www.libsdl.org/) library. This allows you to create windows containing pixel graphics.

It was designed for use in Raspberry Pi workshops, but should run on any system capable of running SDL.

<video width="128" height="128" autoplay loop>
        <source src="docs/img/testpattern.mp4" type="video/mp4">
</video>

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
$ gcc -o main main.c pixels/canvas.c pixels/draw.c screen.c `sdl2-config --cflags --libs`
```
