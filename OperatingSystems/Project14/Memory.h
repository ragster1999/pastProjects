
struct Memory
{
	int numBlocks; // The number of blocks in memory
	int sizeOfBlock; // The size of one block
	char *data; // The data
	int *bitmap; // A tasteful map of the bits
};

Memory *createMemory(int newNumberBlocks, int newSizeOfBlock);
void printMemory(Memory *mem);
void printBlock(Memory *mem, int blockNumber);
int findFreeBlock(Memory *mem);
void fillBlock(Memory *mem, int blockNumber, char data);
void freeMemory(Memory *mem);