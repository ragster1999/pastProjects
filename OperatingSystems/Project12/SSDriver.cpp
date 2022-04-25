#include <stdio.h>
#include <stdlib.h>
#include "FileSystem.h"
#include "ProcessTable.h"

// argv[1] = Number of processes
// argv[2] = Name of file with process information 
// argv[3] = Number of operations
// argv[4] = Name of file with operations
// argv[5] = Number of blocks
// argv[6] = Size of blocks

// To run: ./SSDriver 2 LabFile.txt 10 LabRequests.txt 10 4
int main(int argc, char *argv[])
{
        int throwAway;
        int numProcesses = atoi(argv[1]);
    // Initializing the table and queue
    //readFile(table, argv[2]);

    FileSystem *fs = createFileSystem(atoi(argv[5]), atoi(argv[6]));
        ProcessTable *table = createInitialTable(atoi(argv[1]), argv[2]);
    int numOperations = atoi(argv[3]);
    FILE *operationFile = fopen(argv[4], "r");
        printFileSystem(fs);
        for (int i = 0; i < numOperations; i++)
        {
                int processID = 0;
                char in[10];
                fscanf(operationFile, "%d", &processID);
                fscanf(operationFile, "%s", in);
                char operation = in[0];
                fscanf(operationFile, "%s", in);
                char fileName = in[0];
                Process *process = findProcess(table, processID);

                if (operation == 'W') // Write
                {
                        int numberBlocks = 0;
                        fscanf(operationFile, "%d", &numberBlocks);
                        printf("Process %d wants to write file %c and needs %d blocks\n", processID, fileName, numberBlocks);
                        if (addFile(fs, fileName, numberBlocks) == 1)
                        {
                                printf("Write error: File already exists\n");
                        }
                        else
                                printf("File %c added successfully\n", fileName);

                }
                else if (operation == 'E') // Edit
                {
                        char editIn[10];
                        fscanf(operationFile, "%s", editIn);
                        char newData = editIn[0];
                        int offset;
                        fscanf(operationFile, "%s", &newData);
                        fscanf(operationFile, "%d", &offset);

                        throwAway = editFile(fs, fileName, offset, newData);

                        if (throwAway == 0) // Deletion worked
                        {
                                printf("\nFile %d edited successfully", fileName);
                                printf("\n====================================");
                        }
                        else // File already exists
                        {
                                printf("\nError: file %d does not exist", fileName);
                                printf("\n====================================");
                                
                        }
                }
                else if (operation == 'D') // Delete
                {
                        throwAway = removeFile(fs, fileName);

                        if (throwAway == 0) // Deletion worked
                        {
                                printf("\nFile %c deleted successfully", fileName);
                                printf("\n====================================");
                        }
                        else // File already exists
                        {
                                printf("\nError: file %c does not exist", fileName);
                                printf("\n====================================");

                        }
                        

                }
                else if (operation == 'R') // Read
                {
                        printFile(fs, fileName);
                        printf("\nFile %c read successfully", fileName);
                        printf("\n==============================");

                }
                printFileSystem(fs);


        }
        return 0;
}