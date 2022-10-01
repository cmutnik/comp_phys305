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
#
# Now for the actual compiling instructions:
# make sure that the space before $(CC)
# is a tab whenever you add a new compiler line.
# The syntax below is such that each left-justified name is
# the "target" (or final product executable program) of the make,
# and the tabbed-in lines that follow provide all of the steps needed
# to make that executable binary file and put it into ~/bin
3Vector.o:	
	g++ -c 3Vector.cpp
3Vectortest: 3Vector.o
	$(CC) $(GFLAGS) 3Vectortest.cpp 3Vector.o -o $(BINDIR)/3Vectortest $(LIBS)
vecFRK4xv.o:
	g++ -c vecFRK4xv.cpp
projectile: 3Vector.o vecFRK4xv.o
	$(CC) $(GFLAGS) projectile.cpp 3Vector.o vecFRK4xv.o -o $(BINDIR)/projectile $(LIBS)

#harmosc1rk:
#	$(CC) $(GFLAGS) harmosc1rk.cpp -o $(BINDIR)/harmosc1rk $(LIBS)
#deriv:
#	$(CC) $(GFLAGS) deriv.cpp -o $(BINDIR)/deriv $(LIBS)
FRK2xv.o:
	g++ -c FRK2xv.cpp
harmoscRKr1:  FRK2xv.o
	g++ $(GFLAGS) harmoscRKr1.cpp  FRK2xv.o -o $(BINDIR)/harmoscRKr1 $(LIBS)
FRK4xv.o:
	g++ -c FRK4xv.cpp
harmoscRKr4:  FRK4xv.o
	g++ $(GFLAGS) harmoscRKr4.cpp  FRK4xv.o -o $(BINDIR)/harmoscRKr4 $(LIBS)

#removes all object files (things ending in ".o")	
clean:
	rm *.o
	


# Whenever you add a new program to your collection of work,
# you add new lines in the file to govern the compiling of your new program.
# end of makefile
