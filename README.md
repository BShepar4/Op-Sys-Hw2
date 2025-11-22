This code takes in a file input that provides max, allocation, and avaliable data for use in the Banker's algorithm. It parses the file, stores the information into vectors, and then computes the safe state and sequence, 
if one exists.
By comparing the avaliable resources to the ones being requested by the given processes, they can be completed and their resources repossesed for use in other processes. The optimal order to complete processes in is 
the aformented safe sequence, and if one does not exist, the program labels it as an unsafe state. This is the function and design of the Banker's algorithm.
The example processes and allocations in the assignment do form a safe state, and the safe sequence is P3 P4 P1 P2 P0

HOW TO USE:
Open VS Code 
Connect To WSL 
Clone Git Repository with link: https://github.com/BShepar4/Op-Sys-Hw1.git

Open a terminal and run two commands: 
g++ banker.cpp
./a.out

The input txt file should be formatted with three "headers", allocation, max, and avaliable, all on their own lines. Under them, vectors of integers in the format {x, y, ... z} can form the needed matrices
There should be no empty lines in the file

The SAMPLE OUTPUT that comes from using the provided information as input is: The system is in a safe state! The safe sequence is: P3 P4 P1 P2 P0
