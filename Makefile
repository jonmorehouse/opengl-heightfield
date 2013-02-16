# Makefile 
# CSCI 480
# Assignment 1


# makefile reformatted and rewritten for current assignment
# could be more dynamic in the future, but for now want to have easy readability to help us ensure how the project is working / compiling together


# we assume the pic directory locates one level above,
# change PIC_PATH if this is not the case
# PIC_PATH = $(abspath $(CURDIR)/../pic)
PIC_PATH = /usr/local/src/pic

# set up include paths -- places to look for header files
INCLUDE = -I$(PIC_PATH)
INCLUDE += -Iinclude

LIBRARIES = -L$(PIC_PATH) -framework OpenGL -framework GLUT -lpicio -ljpeg

COMPILER = g++
COMPILERFLAGS = -O3 $(INCLUDE)
PROGRAM = current

# compile the modules into our main function
all: modules.o src/main.cpp 

	$(COMPILER) $(COMPILERFLAGS) -o $(PROGRAM) src/main.cpp modules.o $(LIBRARIES)

# compile our modules object
modules.o: src/modules/*.cpp include/modules/*.hpp 

	$(COMPILER) $(COMPILERFLAGS) -c -o src/modules.o src/modules/*.cpp $(LIBRARIES)

# clean up after ourselves
clean:
	-rm -rf *.o *~ .*~ $(PROGRAM)
	-rm -rf src/*.o src/*~
