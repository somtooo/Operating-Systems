#
# On Windows, use this makefile with the command
#    c:\cs30200\MinGW32\bin\mingw32-make
#
# For Linux, change
#    CC=c:\cs30200\MinGW32\bin\gcc
# to
#    CC=gcc
# and use this makefile with just the command
#    make
CC=c:\cs30200\MinGW32\bin\gcc
CFLAGS=-g -std=c99 -pedantic -Wall -Wextra

all: scanf-example_1.exe  scanf-example_2.exe scanf-example_3.exe

scanf-example_1.exe: scanf-example_1.c
	$(CC) $(CFLAGS) -o scanf-example_1.exe  scanf-example_1.c

scanf-example_2.exe: scanf-example_2.c
	$(CC) $(CFLAGS) -o scanf-example_2.exe  scanf-example_2.c

scanf-example_3.exe: scanf-example_3.c
	$(CC) $(CFLAGS) -o scanf-example_3.exe  scanf-example_3.c
