#Lukas
#28/9/23
#Licienced under GPLv3
#Rules: Open Terminal, make sure its insid ethe folder, type "make", type "./exe"

CFILES=uTest.c
OBJFILE=uTest.o
HFILES=minunit.h
CC=gcc
EXEFILE=exe
FLAGS=-Wall -g -O0

%.o: %.c
	$(CC) -Wall -c $< -o $@ 


EXE: $(OBJFILE) $(HFILES)
	$(CC) $(FLAGS) $(OBJFILE) -o $(EXEFILE)

CLEAN:
	rm *.o

INSTALL:
	cp $(EXEFILE) /home//osboxes/bin/