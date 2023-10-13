#Lukas
#28/9/23
#Licienced under GPLv3 - License as a text file on folder
#Rules: Open Terminal, make sure its insid ethe folder, type "make", type "./exe"
#Git URL: https://github.com/LukasKmitas/Games_Eng2

CFILES=uTest.c 
OBJFILE=uTest.o
HFILES=minunit.h DLinkedList.h
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
