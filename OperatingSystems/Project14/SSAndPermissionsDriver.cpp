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
int main(int argc, char *argv[])
{
	int numProcesses = atoi(argv[1]);
    // Initializing the table and queue
    //readFile(table, argv[2]);

    FileSystem *fs = createFileSystem(atoi(argv[5]), atoi(argv[6]));
	ProcessTable *table = createInitialTable(atoi(argv[1]), argv[2]);
    int numOperations = atoi(argv[3]);
    FILE *operationFile = fopen(argv[4], "r");
    for (int i = 0; i < numOperations; i++)
    {
		printf("*******************OPERATION: %d********************\n", i);
		int processID = 0;
		char op = '0', fileName = '0';
		
        fscanf(operationFile, "%d", &processID);
		char in[10];
		fscanf(operationFile, "%s", in);
		op = in[0];
		fscanf(operationFile, "%s", in);
		fileName = in[0];
        Process *process = findProcess(table, processID);
		if (op == 'W')
        {
			int numberBlocks = 0;
			fscanf(operationFile, "%d", &numberBlocks);
			printf("Process %d wants to write file %c and needs %d blocks\n", processID, fileName, numberBlocks);
			if (addFile(fs, processID, fileName, numberBlocks) == 1)
				printf("Write error: File already exists\n");
			else
				printf("File %c added successfully\n", fileName);
        }
		else if (op == 'C')
		{
			int permission = 0;
			fscanf(operationFile, "%d", &permission);	

			printf("Process %d changing permissions to %d for file %c\n", processID, permission, fileName);
			changePermission(fs, processID, fileName, permission);
		}
        else if (op == 'D')
        {
			printf("Process %d wants to delete file %c\n", processID, fileName);
			int error = removeFile(fs, processID, fileName);
			if (error == 1)
				printf("Delete error: File does not exist\n");	
			else if (error == 2)
				printf("Delete error: User does not have permission to delete file\n");
			else
				printf("File %c deleted successfully\n", fileName);	
		}
		else if (op == 'R')
		{
			printf("Process %d wants to read file %c\n", processID, fileName);
			int error = printFile(fs, processID, fileName);
			if (error == 1)
				printf("Read error: File does not exist\n");
			else if (error == 2)
				printf("Read error: Process does not have read access\n");
			else
				printf("File %c read successfully\n", fileName);
		}
		else if (op == 'E')
		{
			int offset = 0;
			char newData = 'A';
			fscanf(operationFile, "%d", &offset);
			fscanf(operationFile, "%s", in);
			newData = in[0];
			printf("Process %d wants to edit file %c\n", processID, fileName);
			int error = editFile(fs, processID, fileName, offset, newData);
			if ( error == 1)
				printf("Edit error: File does not exist\n");
			else if (error == 2)
				printf("Edit error: Process does not have permission to edit file\n");
			else if (error == 3)
				printf("Edit error: Offset outside the valid range\n");
			else
				printf("File %c edited successfully\n", fileName);	
		}
		printFileSystem(fs);
	}	
	table = NULL;
	fs = NULL;
	return 0;
}
