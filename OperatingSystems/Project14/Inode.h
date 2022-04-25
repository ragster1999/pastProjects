// Inode.h

#include "LL.h"
#define MAX_ENTRIES 5

struct Inode
{
	char name; // Single char name
	int *blocks; // Number of blocks (will be no more than 5)
	LL *accessCL; // pointer to linked list of access control per node
};

void printInode(Inode *inode);
Inode *createInode(int processID, char name, int newNumBlocks);
void deleteInode(Inode *inode);
int getPermission(Inode *inode, int processID);