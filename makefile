# 'make depend' uses makedepend to automatically generate dependencies
#               (dependencies are added to end of Makefile)
# 'make'        build executable file 'mycc'
# 'make clean'  removes all .o and executable files
#

# define the C compiler to use
CC = g++-7

# define any compile-time flags
CFLAGS = -std=gnu++0x -Wall -g #Enables GNU extensions
# CFLAGS = -std=c++0x -Wall -g #Disables GNU extenstions
# CFLAGS = -Wall -g

# define any directories containing header files other than /usr/include
#
#INCLUDES = -I./Utilities  -I./Model
INCLUDES = -I./Model -I./
# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
#LFLAGS = -L./Utilities  -L./Model
LFLAGS = -L./Model -L./

# define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname
#   option, something like (this will link in libmylib.so and libm.so:
LIBS = -l./Model -lm
#LIBS =
# define the C source files
DIR_MODEL = ./Model/
DIR_UTILITIES = ./Utilities/
DIR_CONTROLLER = ./Controller/
DIR_TEST = ./Test/

UTILS=$(DIR_UTILITIES)MyString.cpp $(DIR_UTILITIES)TimeAndDate.cpp $(DIR_UTILITIES)MyDate.cpp $(DIR_UTILITIES)Period.cpp $(DIR_UTILITIES)MyClock.cpp $(DIR_UTILITIES)MyTime.cpp
MODELS=$(DIR_MODEL)Account.cpp $(DIR_MODEL)Money.cpp $(DIR_MODEL)Person.cpp $(DIR_MODEL)User.cpp $(DIR_TEST)Expected.cpp

SRCS = main.cpp $(DIR_TEST)Test.cpp $(UTILS) $(MODELS)

# SRCS = main.cpp $(DIR_TEST)Test.cpp $(DIR_UTILITIES)MyString.cpp $(DIR_UTILITIES)TimeAndDate.cpp $(DIR_UTILITIES)MyDate.cpp $(DIR_UTILITIES)Period.cpp $(DIR_UTILITIES)MyClock.cpp $(DIR_UTILITIES)MyTime.cpp $(DIR_MODEL)Account.cpp $(DIR_MODEL)Money.cpp $(DIR_MODEL)Person.cpp $(DIR_MODEL)User.cpp  $(DIR_TEST)Expected.cpp

# define the C object files
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
#
OBJS = $(SRCS:.c=.o)

# define the executable file
MAIN = myprogram

#
# The following part of the makefile is generic; it can be used to
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
#

#.PHONY: depend clean

all:  $(MAIN)
	@echo  SUCCESS: Compiler named myprogram has been compiled.

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS)
	#$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)
# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file)
# (see the gnu make manual section about automatic variables)
.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN)

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it
