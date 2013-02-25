Overview
=

This is an opengl program that will be used as a homework assignment for my CSCI 480 course. Sample code was given to start off of but I'm going to continue building off of it. Please note that pic library is necessary for this code to compile. I have compiled and stored this into my /usr/local/ directory.

Compile Directions
=

1.) Ensure that you have the pic library and install it to a directory globally on your machine. I recommend /usr/local/src. Update the makefile with this directory

2.) Ensure that GLUT Libraries are installed on your machine and link those properly with this makefile. I recommend making a pkg-config if possible.

3.) make clean && make

Controls
=

Initialize program with -s to take screenshots every half second. 

Initialize with a grayscale image. This program only allows grayscales at the moment

Use j/k keys to switch between points, grayscale and wireframe view	

While in wireframe mode, 

Drag your mouse to rotate the heightfield. Shift drag to scale and ctrl drag to translate. Up/down/left/right keys are for rotation around the x/z axes.

Use - / + to change the wireframe density.

Features to Implement
=

1.) Refactor the display class to optimize and speed up viewing of the images
2.) Use openCV for image loading instead of the PIC library
3.) Enable some textures across this application
4.) Run the screenshot application in parallel to main application. This is currently done blockingly and can halt some animations
5.) Integrate shadows on the elements and the ability to change colors dynamically

