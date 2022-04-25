#include <stdio.h> 
#include <stdlib.h> 
#include "FileSystem.h"
#include "ProcessTable.h"

// argv[1] = Number of processes
// argv[2] = Name of file with process information 
// argv[3] = Number of blocks
// argv[4] = Size of blocks
int main(int argc, char *argv[])
{
	int numProcesses = atoi(argv[1]);
    // Initializing the table and queue
    //readFile(table, argv[2]);

    FileSystem *fs = createFileSystem(atoi(argv[3]), atoi(argv[4]));
	ProcessTable *table = createInitialTable(atoi(argv[1]), argv[2]);
	addFile(fs, table->processes[0]->id, 'A', 3);
	addFile(fs, table->processes[0]->id, 'B', 2);
	addFile(fs, table->processes[1]->id, 'C', 1);
	printFileSystem(fs);
	changePermission(fs, table->processes[0]->id, 'A', 5);
	printFileSystem(fs);
	changePermission(fs, table->processes[1]->id, 'B', 3);	
	printFileSystem(fs);
	changePermission(fs, table->processes[0]->id, 'A', 0);
	printFileSystem(fs);
	/*freeProcessTable(table);
	free(table);
	freeFileSystem(fs);
	free(fs);*/
	table = NULL;
	fs = NULL;
	return 0;
}

// g++ -c Inode.cpp Process.cpp ProcessTable.cpp LL.cpp

// make PermissionsDriver