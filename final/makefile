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
LOCALDIR = $(HOME)/work
#
# this section for compiler flags and link libraries
# -O3 gives a high degree of code optimization, -W gives all warnings
# and -g turns on the debug options
#
GFLAGS  = -O3 -W -g 
LIBS    = -lm
CC      = g++

########
all: harmonic1 squarewell harm1mod hydrogen wavefunc
########
harmonic1:
	$(CC) $(GFLAGS) harmonic1.c -o $(BINDIR)/harmonic1 $(LIBS)
3Vector.o:
	$(CC) -c 3Vector.cpp
harm1mod3vec: 3Vector.o
	$(CC) harm1mod3vec.cpp 3Vector.o -o $(BINDIR)/harm1mod3vec $(LIBS)
harm1mod2D:
	$(CC) harm1mod2D.cpp -o $(BINDIR)/harm1mod2D $(LIBS)
squarewell:
	$(CC) $(GFLAGS) squarewell.cpp -o $(BINDIR)/squarewell $(LIBS)
harm1mod:
	$(CC) $(GFLAGS) harm1mod.cpp -o $(BINDIR)/harm1mod $(LIBS)
harm1modxz:
	$(CC) $(GFLAGS) harm1modxz.cpp -o $(BINDIR)/harm1modxz $(LIBS)
FRK4xv.o:
	$(CC) -c FRK4xv.cpp
wavefunc: FRK4xv.o
	$(CC) $(GFLAGS) wavefunc.cpp FRK4xv.o -o $(BINDIR)/wavefunc $(LIBS)
wavefunc2: FRK4xv.o
	$(CC) $(GFLAGS) wavefunc2.cpp FRK4xv.o -o $(BINDIR)/wavefunc2 $(LIBS)
hydrogen:
	$(CC) $(GFLAGS) hydrogen.cpp -o $(BINDIR)/hydrogen $(LIBS)
periodicwell:
	$(CC) $(GFLAGS) periodicwell.cpp -o $(BINDIR)/periodicwell $(LIBS)
schroedinger:
	$(CC) $(GFLAGS) schroedinger.cpp -o $(BINDIR)/schroedinger $(LIBS)
harm1modyx:
	$(CC) $(GFLAGS) harm1modyx.cpp -o $(BINDIR)/harm1modyx $(LIBS)
clean:
	rm *.dat


# Whenever you add a new program to your collection of work,
# you add new lines in the file to govern the compiling of your new program.
# end of makefile

