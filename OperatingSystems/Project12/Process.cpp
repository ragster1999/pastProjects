// Process.cpp
// Implimentation file for Process.h

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "Process.h"

// A function to waste time dependant on the input of seconds to waste
void wasteCycles(int seconds)
{
    clock_t start = time(0);
	while (time(0) - start < seconds);
}

// Methods for Process Struct
Process *createProcess(int newId, int newPriority, int newCpuBurst, int newIoBurst, int newTotalTime, int newNumPages)
{
    Process *newProcess = (Process*)malloc(sizeof(Process));
    newProcess->id = newId;
    newProcess->priority = newPriority;
    newProcess->cpuBurst = newCpuBurst;
    newProcess->ioBurst = newIoBurst;
    newProcess->totalTime = newTotalTime;
    newProcess->remainingTime = newTotalTime;
    newProcess->state = 'N';
    newProcess->numPages = newNumPages;
    newProcess->pageTable = (int*)malloc(sizeof(int)*newNumPages);

    // initialize values
    for (int i = 0; i < newNumPages; i++)
    {
        newProcess->pageTable[i] = 0;
    }
    return newProcess;
}

// that yung print function
void printProcess(Process *p)
{
    printf("Process ID: %d\tpriority: %d\tCPU Burst: %d\tI/O Burst: %d\tTotal time: %d\tCurrent state: %c\tTime remaining: %d\n", p->id, p->priority, p->cpuBurst, p->ioBurst, p->totalTime, p->state, p->remainingTime);
}

// Print that yung table
void printPageTable(Process *p)
{
    printf("\n\nPage table for: [%d]\n", p->id);
    for (int i = 0; i < p->numPages; i++)
    {
        printf("%d\t", i);
    }
    printf("\n");
    for (int i = 0; i< p->numPages; i++)
    {
        printf("%d\t", p->pageTable[i]);
    }
    printf("\n");
}

// A function to switch the state
int switchState(Process *p, char newState)
{
    p->state = newState;
    return 0;
}

// A function to free the process
void freeProcess(Process *p)
{
    free(p);
    p = NULL;
}