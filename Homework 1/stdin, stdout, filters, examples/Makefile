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

all: filter1.exe  filter2.exe

filter1.exe: filter1.c
	$(CC) $(CFLAGS) -o filter1.exe  filter1.c

filter2.exe: filter2.c
	$(CC) $(CFLAGS) -o filter2.exe  filter2.c
