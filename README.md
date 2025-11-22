This code takes in a file input that provides max, allocation, and avaliable data for use in the Banker's algorithm. It parses the file, stores the information into vectors, and then computes the safe state and sequence, 
if one exists.
By comparing the avaliable resources to the ones being requested by the given processes, they can be completed and their resources repossesed for use in other processes. The optimal order to complete processes in is 
the aformented safe sequence, and if one does not exist, the program labels it as an unsafe state. This is the function and design of the Banker's algorithm.
The example processes and allocations in the assignment do form a safe state, and the safe sequence is P3 P4 P1 P2 P0
