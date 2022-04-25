#include "Memory.h"
#include <stdio.h> 
#include <stdlib.h> 

Memory *createMemory(int newNumberBlocks, int newSizeOfBlock)
{
	Memory *newMemory = (Memory*)malloc(sizeof(Memory));
	newMemory->numBlocks = newNumberBlocks;
	newMemory->sizeOfBlock = newSizeOfBlock;
	newMemory->data = (char*)malloc(sizeof(char)*newNumberBlocks*newSizeOfBlock);
	newMemory->bitmap = (int*)malloc(sizeof(int)*newNumberBlocks);

	for (int i = 0; i < newNumberBlocks; i++)
	{
		newMemory->bitmap[i] = 0;
	}

	// Populate data array
	for (int i = 0; i < newNumberBlocks; i++)
	{
		newMemory->data[i] = 0;
	}
	return newMemory;
}

void printBlock(Memory *mem, int blockNumber)
{
	for (int i = 0; i < mem->sizeOfBlock; i++)
		printf("%c", mem->data[blockNumber*mem->sizeOfBlock]);
}

// Returnes the address of the free block
int findFreeBlock(Memory *mem)
{
	for (int i = 0; i < mem->numBlocks; i++)
	{
		if (mem->bitmap[i] == 0)
			return i;
	}
	return -1;
}

void fillBlock(Memory *mem, int blockNumber, char data)
{
	int start = blockNumber * mem->sizeOfBlock;
	// printf("--------Block Number: %d\t Size of Block: %d\n", blockNumber, mem->sizeOfBlock);
	for (int i = 0; i < mem->sizeOfBlock ; i++)
	{
		mem->data[start + i] = data;
	}
	mem->bitmap[blockNumber] = 1;
}

void printMemory(Memory *mem)
{
	printf("=========================\n");
	printf("Bitmap\n");
	for (int i = 0; i < mem->numBlocks; i++)
		printf("%d\t", mem->bitmap[i]);
	printf("\n=========================\n");
	printf("Size: %d\n", mem->numBlocks);
	for (int i = 0; i < mem->numBlocks; i++)
	{
		printf("Block: %d\t", i);
		for (int j = 0; j < mem->sizeOfBlock; j++) 
		{
			if (mem->data[i*mem->sizeOfBlock + j] == 0)
				printf("-");
			else
				printf("%c", mem->data[i*mem->sizeOfBlock + j]);
		}
		printf("\n");
	}
	printf("\n=========================\n");
}
	

void freeMemory(Memory *mem)
{
	free(mem);
}

// ./SSDriver 2 LabFile.txt 2 LabRequests.txt 10 5