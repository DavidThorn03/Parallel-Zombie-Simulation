# Makefile for Parallel Program with Latent Model

CC = gcc
CFLAGS = -g -Wall
LDFLAGS = -lpthread

DEPS =	vars_defs_functions.h timer.h

OBJ = 	parallel.o\
	child_thread.o\
	initialiseWorld.o\
	outputDaySIZRD.o\
	outputWorld.o\
	countZombieNeighbours.o\
	countSusceptibleNeighbours.o\
	decide_S_to_IorR.o\
	decide_I_to_Z.o\
	decide_I_to_D.o\
	decide_Z_to_D.o\
	decide_S_to_D.o\
	decide_R_to_Z.o\
	decide_D_to_Empty.o

#.SUFFIXES	.c

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

parallel: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm *.o
	rm parallel
