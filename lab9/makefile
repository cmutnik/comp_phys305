# makefile for c++ programs
#
# to create binary executable "area" below, type "make area"
#
# If you don't have a "bin" folder for binaries, create it first
#
# the "#" is the comment character for makefile scripts
#
# this section sets some variables/alaises
# The syntax "$(HOME)" gives substitution of the variable HOME
# change "your_username" below to appropriate name
#
HOME = /home/cmutnik
BINDIR  =  $(HOME)/bin
LOCALDIR = $(HOME)/Work
#
# this section for compiler flags and link libraries
# -O3 gives a high degree of code optimization, -W gives all warnings
# and -g turns on the debug options
#
GFLAGS  = -O3 -W -g 
LIBS    = -lm
CC      = g++
#
# Now for the actual compiling instructions:
# make sure that the space before $(CC)
# is a tab whenever you add a new compiler line.
# The syntax below is such that each left-justified name is
# the "target" (or final product executable program) of the make,
# and the tabbed-in lines that follow provide all of the steps needed
# to make that executable binary file and put it into ~/bin
3Vector.o: 
	$(CC) -c 3Vector.cpp
vecFRK4xv.o:
	$(CC) -c vecFRK4xv.cpp
initialize_atmosphere.o:
	$(CC) -c initialize_atmosphere.cpp
missile: 3Vector.o vecFRK4xv.o initialize_atmosphere.o
	$(CC) $(GFLAGS) missile.cpp 3Vector.o vecFRK4xv.o -o $(BINDIR)/missile $(LIBS)
missileSoln: 3Vector.o vecFRK4xv.o initialize_atmosphere.o
	$(CC) $(GFLAGS) missileSoln.cpp 3Vector.o vecFRK4xv.o -o $(BINDIR)/missileSoln $(LIBS)
# Whenever you add a new program to your collection of work,
# you add new lines in the file to govern the compiling of your new program.
# end of makefile
