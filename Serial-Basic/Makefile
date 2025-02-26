# Makefile for Serial Program with Basic Model

CC = gcc
CFLAGS = -g -Wall

DEPS =	vars_defs_functions.h

OBJ = 	serial.o\
	initialiseWorld.o\
	outputDaySZRD.o\
	outputWorld.o\
	countZombieNeighbours.o\
	countSusceptibleNeighbours.o\
	decide_S_to_ZorR.o\
	decide_Z_to_D.o\
	decide_S_to_D.o\
	decide_R_to_Z.o\
	decide_D_to_Empty.o

#.SUFFIXES	.c

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

serial: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm *.o
	rm serial
