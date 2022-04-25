
#define MAX_ENTRIES 5

struct Inode
{
	char name; // Single char name
	int *blocks; // Number of blocks (will be no more than 5)
};

void printInode(Inode *inode);
Inode *createInode(char name, int newNumBlocks);
void deleteInode(Inode *inode);

