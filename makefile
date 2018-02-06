# This is an example Makefile for a countwords program.  This
# program uses both the scanner module and a counter module.
# Typing 'make' or 'make count' will create the executable file.
#

# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile: $()
#
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#
# for C++ define  CC = g++
CC = g++
#CFLAGS  =
CFLAGS  = -g -Wall

PATH_UTILITIES := $(PATH):/Utilities

# PATH_UTILITIES = ./Utilities/
# PATH_MODEL = ./Model/

# typing 'make' will invoke the first target entry in the file
# (in this case the default target entry)
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
#
default: program

# To create the executable file count we need the object files
# countwords.o, counter.o, and scanner.o:
#
program:  main.o Money.o MyString.o Person.o
	$(CC) $(CFLAGS) -o program main.o Money.o MyString.o Person.o


main.o:  main.cpp Money.h MyString.h Person.h
	$(CC) $(CFLAGS) -c main.cpp

# To create the object file countwords.o, we need the source
# files countwords.c, scanner.h, and counter.h:
#
Money.o:  Money.cpp Money.h MyString.h
	$(CC) $(CFLAGS) -c Money.cpp

# To create the object file counter.o, we need the source files
# counter.c and counter.h:
#
MyString.o:  MyString.cpp MyString.h
	$(CC) $(CFLAGS) -c MyString.cpp

Person.o: Person.cpp Person.h
	$(CC) $(CFLAGS) -c Person.cpp

# To create the object file scanner.o, we need the source files
# scanner.c and scanner.h:
#
#$(PATH_UTILITIES)MyTime.o:  $(PATH_UTILITIES)MyTime.cpp $(PATH_UTILITIES)MyTime.h
#	$(CC) $(CFLAGS) -c $(PATH_UTILITIES)MyTime.cpp

# ./Utilities/MyTime.o:  ./Utilities/MyTime.cpp ./Utilities/MyTime.h
# 	$(CC) $(CFLAGS) -c ./Utilities/MyTime.cpp

# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean:
	$(RM) count *.o *~
