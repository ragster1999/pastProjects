// Inode.cpp

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

	printf("\nPermissions: \n");
	printLL(inode->accessCL);
	printf("\n");

}

Inode *createInode(int processID, char name, int newNumBlocks) 
{
	Inode *newInode = (Inode*)malloc(sizeof(Inode));
	newInode->name = name;
	newInode->blocks = (int*)malloc(sizeof(int)*MAX_ENTRIES);

	for (int i = 0; i < MAX_ENTRIES; i++)
		newInode->blocks[i] = -1;
	
	newInode->accessCL = initializeLL();
	FilePermission *fp = (FilePermission*)malloc(sizeof(FilePermission));
	fp->processID = processID;
	fp->permission = 7; // Give the owner complete access
	fp->next = NULL;
	addNode(newInode->accessCL, fp);
	return newInode;

}

void deleteInode(Inode *inode)
{
	free(inode->blocks);
	free(inode);
	return;
}

int getPermission(Inode *inode, int processID)
{
	FilePermission *iterator = inode->accessCL->head->next;
	// Loop through all nodes in accessCL

	while (iterator != NULL)
	{
		// If processID exists, return permissions accociated with it
		if (processID == iterator->processID)
			return iterator->permission;
	}

	// Else, return 0
	return 0;
}
