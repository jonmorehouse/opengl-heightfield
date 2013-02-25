#!/bin/bash

# this is a short bash script to programmatically create an animation from screenshots using imagemagick
interval=20

# create filler gap images
convert screenshots/*.png -delay $interval -morph $interval temp/%05d.morph.png

# q scale = quality where 1 = highest and 32 = lowest
ffmpeg -r 25 -qscale 2 -i temp/%05d.morph.png output.mp4