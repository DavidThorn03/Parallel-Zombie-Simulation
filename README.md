# Parallel-Zombie-Simulation

This project was completed for the Parallel Computing module

This involved creating a cellular automata model to simulate the outbreak of a zombie virus. 

It has been developed in C using Pthreads, implementing mutexes, condition variables, and barriers to avoid critical section issues and ensure the program executes correctly.

This cellular automata model had rules based on the logic for zombie virus outbreak explained in [When zombies attack!: Mathematical modelling
of an outbreak of zombie infection](url), with transitions between Susceptible, zombie, and removed, with the addition of an Infected state in the latient infection model. 

The program assesses each cell, changing its state based on previous events and its neighbouring cells, doing this for every cell each day/cycle and logging these changes to external text files. 

This project involved developing the cellular automata model, parallelising it, and discussing the parallelisation process in a presentation, discussing the differences in results between serial and parallel execution.
