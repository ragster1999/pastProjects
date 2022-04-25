#include "Inode.h"
#include <stdio.h> 
#include <stdlib.h> 

void printInode(Inode *inode)
{
	printf("File name: %c\n", inode->name);
	for (int i = 0; i < MAX_ENTRIES; i++)
		printf("%d\t", i);
	printf("\n");
	for (int i = 0; i < MAX_ENTRIES; i++)
		printf("%d\t", inode->blocks[i]);
	printf("\n");
}

Inode *createInode(char name, int newNumBlocks) // Why newNumBlocks
{
	Inode *newInode = (Inode*)malloc(sizeof(Inode));
	newInode->name = name;
	newInode->blocks = (int*)malloc(sizeof(int)*MAX_ENTRIES);

	for (int i = 0; i < MAX_ENTRIES; i++)
		newInode->blocks[i] = -1;
	
	return newInode;

}

void deleteInode(Inode *inode)
{


}

