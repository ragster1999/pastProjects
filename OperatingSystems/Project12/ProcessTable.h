// ProcessTable.h
// Header file for ProcessTable

#include "Process.h"

struct ProcessTable
{
    int numProcesses;
    Process **processes; // Pointer to an array of Process Pointers
    int numFinished; // The number of processed that have finished
    int cpuProcess; // PID of the process running on the CPU
};

ProcessTable *createInitialTable(int newNumProcesses, char *fileName);
void printTable(ProcessTable *pt);
void freeProcessTable(ProcessTable *pt);
void printPageTables(ProcessTable *pt);
Process * findProcess(ProcessTable *pt, int ID);