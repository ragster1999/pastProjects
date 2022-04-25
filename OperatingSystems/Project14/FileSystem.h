#include "Inode.h"
#include "Memory.h"

#define MAX_INODES 10
struct FileSystem
{
	int numberInodes;
	Inode **inodes;
	Memory *memory;		
};

FileSystem *createFileSystem(int newNumberBlocks, int newSizeOfBlock);
void printFileSystem(FileSystem *fs);
void freeFileSystem(FileSystem *fs);
Inode *findInode(FileSystem *fs, char fileName);
int addFile(FileSystem *fs, int processID, char fileName, int numberBlocks);
int removeFile(FileSystem *fs, int processID, char fileName);
int printFile(FileSystem *fs, int processID, char fileName);
int editFile(FileSystem *fs, int processID, char fileName, int offset, char newData);
int changePermission(FileSystem *fs, int processID, char fileName, int newPermission);