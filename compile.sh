#!/bin/bash

# this is a short bash script to programmatically create an animation from screenshots using imagemagick

interval=${1}
folder=${2}
output=${3}

if [[ ${#1} -eq 0 || ${#2} -eq 0 || ${#3} -eq 0 ]]; then
	echo "Proper usage: compile interval folder output.mp4"
	exit
fi

# q scale = quality where 1 = highest and 32 = lowest
# ffmpeg -r 25 -qscale 2 -i %05d.morph.jpg output.mp4
