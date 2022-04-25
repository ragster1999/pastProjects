// Process.h
// Header for the process control block
#ifndef PROCESS_H
#define PROCESS_H

#include <stdio.h>
#include <stdlib.h>

struct Process 
{
    int id;
    int priority;
    int cpuBurst; // How long does the process need to finish it's CPU burst
    int ioBurst; // Length of I/O Burst
    int totalTime; // Total time needed on CPU
    int remainingTime; // Time left
    char state; // Options: N, T, R, Q, B
    // New for hw10
    int numPages; // Number of pages this process is diveded into
    int *pageTable; // Tage table for this process

    
};

// Functionsid for Process Struct
void wasteCycles(int seconds);
Process *createProcess(int newID, int newPriority, int newCpuBurst, int newIoBurst, int newTotalTime, int numPages);
void printProcess(Process *p);
void printPageTable(Process *p);
int switchState(Process *p, char newState);
void freeProcess(Process *p);

#endif 