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
int addFile(FileSystem *fs, char fileName, int numberBlocks);
int removeFile(FileSystem *fs, char fileName);
int printFile(FileSystem *fs, char fileName);
int editFile(FileSystem *fs, char fileName, int offset, char newData);

