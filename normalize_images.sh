#!/bin/bash

# this program is useful for making sure the images are in the right order
# then it will convert and rename each image properly

cd "screenshots"

# normalize 1->9 to 01->09
for i in {1..9} 
do
	mv $i.jpg 0$i.jpg
done

# normalize to allow for leading zeros when more than 100 images exist
for i in {01..99} 
do
	mv $i.jpg 0$i.jpg
done

for i in *
do
	# rename *.jpg to *.png
	name="${i%%jpg}png"
	echo $name
	# move the image
	mv $i $name
	# convert to png
	sips -s format png $name
done

