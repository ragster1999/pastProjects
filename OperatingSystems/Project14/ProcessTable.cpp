// ProcessTable.cpp
// Implimentation file for ProcessTable

#include "ProcessTable.h"
#include <stdio.h>
#include <stdlib.h>

ProcessTable *createInitialTable(int newNumProcesses, char *fileName)
{
    FILE *inputFile = fopen(fileName, "r");

    // Set stuff to 0
    int id = 0, priority = 0, cpuBurst = 0, ioBurst = 0, totalTime = 0, numPages = 0;

    // Initialize ProcessTable
    ProcessTable *pt = (ProcessTable*)malloc(sizeof(ProcessTable));

    pt->processes = (Process**)malloc(sizeof(Process*) * newNumProcesses);

    pt->numProcesses = newNumProcesses;
    for(int i = 0; i < pt->numProcesses; i++)
    {
        // Read in the file attributes per process
        fscanf(inputFile, "%d", &id);
        fscanf(inputFile, "%d", &priority);
        fscanf(inputFile, "%d", &cpuBurst);
        fscanf(inputFile, "%d", &ioBurst);
        fscanf(inputFile, "%d", &totalTime);
        fscanf(inputFile, "%d", &numPages);

        // Create a new Process struct for pt->processes[i] using those values
        pt->processes[i] = createProcess(id, priority, cpuBurst, ioBurst, totalTime, numPages);
    }
    fclose(inputFile);

    pt->numFinished = 0;
    pt->cpuProcess = -1; // -1 denoted idle

    return pt;

}

void printTable(ProcessTable *pt)
{
    for (int i = 0; i < pt->numProcesses; i++)
    {
        printProcess(pt->processes[i]);
    }
    printf("Process currently on CPU: %d, number of processes completed: %d \n", pt->cpuProcess, pt->numFinished);
    
}

// Print every page table
void printPageTables(ProcessTable *pt)
{
    for (int i = 0; i < pt->numProcesses; i++)
    {
        printPageTable(pt->processes[i]);
    }
}

void freeProcessTable(ProcessTable *pt)
{
    for (int i = 0; i < pt->numProcesses; i++)
    {
        freeProcess(pt->processes[i]);
    }
    free(pt);
    pt = NULL;
}

Process * findProcess(ProcessTable *pt, int ID)
{
    for (int i = 0; i < pt->numProcesses; i++)
    {
    if (pt->processes[i]->id == ID)
        return pt->processes[i];
    }
    return NULL;
}