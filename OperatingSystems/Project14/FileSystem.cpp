#include "FileSystem.h"
#include <stdio.h>
#include <stdlib.h>

FileSystem *createFileSystem(int newNumberBlocks, int newSizeOfBlock)
{
	FileSystem *fs = (FileSystem *)malloc(sizeof(FileSystem));
	fs->inodes = (Inode **)malloc(sizeof(Inode *) * MAX_INODES);
	for (int i = 0; i < MAX_INODES; i++)
		fs->inodes[i] = 0;

	fs->numberInodes = 0;
	fs->memory = createMemory(newNumberBlocks, newSizeOfBlock);
	return fs;
}

void printFileSystem(FileSystem *fs)
{
	printMemory(fs->memory);
	for (int i = 0; i < fs->numberInodes; i++)
		printInode(fs->inodes[i]);
}

void freeFileSystem(FileSystem *fs)
{
	free(fs);
}

Inode *findInode(FileSystem *fs, char fileName)
{
	for (int i = 0; i < fs->numberInodes; i++)
	{
		if (fs->inodes[i]->name == fileName)
			return fs->inodes[i];
	}
	return NULL;
}

int addFile(FileSystem *fs, int processID, char fileName, int numberBlocks)
{
	if (fs->numberInodes == MAX_INODES) // check to see if it's full
		return 1;

	// If the filesystem isn't full
	Inode *inode = findInode(fs, fileName); // This will only work if fineInode is finished
	if (inode != NULL)
		return 1;

	// If we get here, we know the inode doesn't exist and we can add it
	fs->inodes[fs->numberInodes] = createInode(processID, fileName, numberBlocks);

	int indexOfNewBlock = fs->numberInodes;
	inode = fs->inodes[indexOfNewBlock];
	for (int i = 0; i < numberBlocks; i++)
	{
		// Find next available free block
		inode->blocks[i] = findFreeBlock(fs->memory);

		// Fill that block with the lower case version of the file name
		fillBlock(fs->memory, inode->blocks[i], fileName + 32);
	}

	// give the process that added the file full permissions
	//inode->accessCL->
	//addNode(inode->accessCL, inode->accessCL->head);

	// Update number of inodes occupied
	fs->numberInodes++;
	return 0;
}

int removeFile(FileSystem *fs, int processID, char fileName)
{
	Inode *inode = findInode(fs, fileName);

	// Check to see if the inode doesn't exists
	if (inode == NULL)
		return 1; // File doesn't exist

	// Find the file permisison
	FilePermission *newFP = inode->accessCL->head->next;
	while (newFP != NULL)
	{
		if (newFP->processID == processID)
		{
			break;
		}
		newFP = newFP->next;
	}

	// Make sure that they have editing rights
	if (newFP->permission < 2 || newFP->permission == 4 || newFP->permission == 5)
	{
		return 2;
	}

	/////////////~If the inode exists~/////////////
	// Change data in memory and bitmap
	int iterator = 0, start;
	while (inode->blocks[iterator] != 0)
	{
		start = fs->memory->sizeOfBlock * inode->blocks[iterator];

		for (int i = 0; i < fs->memory->sizeOfBlock; i++)
		{
			fs->memory->data[start + i] = 0;
		}
		fs->memory->bitmap[inode->blocks[iterator]] = 0;
		iterator++;
	}

	// Slide everything up to fill in the space
	for (int i = 0; i < fs->numberInodes; i++)
	{
		if (fs->inodes[i]->name == inode->name)
		{
			for (int j = i; j < fs->numberInodes - 1; j++)
			{
				fs->inodes[j] = fs->inodes[j + 1];
			}
			break;
		}
	}

	// Free blocks associated with file
	//freeMemory(fs->memory);

	// Remove inode from inode array
	deleteInode(inode);

	fs->numberInodes--;
	return 0;
}

int editFile(FileSystem *fs, int processID, char fileName, int offset, char newData)
{
	// Check to see if the inode exists
	Inode *inode = findInode(fs, fileName);
	if (inode == NULL)
		return 1;
	// Find the file permisison
	//return 0;
	FilePermission *newFP = inode->accessCL->head->next;
	while (newFP != NULL)
	{
		if (newFP->processID == processID)
		{
			break;
		}
		newFP = newFP->next;
	}

	if (newFP == NULL)
	{
		return 2;
	}
	// Make sure that they have editing rights
	printf("Permissions: %d", newFP->permission);
	//return 0;
	// newFP->permission < 2 || newFP->permission == 4 || newFP->permission == 5
	// !(newFP->permission == 2 || newFP->permission == 3 || newFP->permission == 6 || newFP->permission == 7)
	if (newFP->permission < 2 || newFP->permission == 4 || newFP->permission == 5)
	{
		printf("NOT ALLOWED!!");
		return 2;
	}

	////////////////~If the inode exists~////////////////
	int row = 0;
	for (int i = 0; i < MAX_INODES; i++)
	{ // If the file name (lower case) matches the memory
		if (fs->memory->data[i * fs->memory->sizeOfBlock] == fileName + 32)
		{
			row = i;
			break;
		}
	}

	// If the offset takes you outside of the block, return 3
	if (offset > row * fs->memory->sizeOfBlock)
	{
		return 3;
	}

	fs->memory->data[offset + (row * fs->memory->sizeOfBlock)] = newData;

	return 0;
}

int printFile(FileSystem *fs, int processID, char fileName)
{
	Inode *inode = findInode(fs, fileName);
	if (inode == NULL)
		return 1;
	// Find process id within inode
	FilePermission *newFP = inode->accessCL->head->next;
	while (newFP != NULL)
	{
		if (newFP->processID == processID)
		{
			break;
		}
		newFP = newFP->next;
	}

	// Check if they have read permissions
	if (newFP->permission > 3)
	{
		printf("Data\n");
		for (int i = 0; i < MAX_INODES; i++)
		{
			if (inode->blocks[i] != -1)
				printBlock(fs->memory, inode->blocks[i]);
			else
				break;
		}
		printf("\n===============================\n");
		return 0;
	}
	else
	{
		return 2;
	}
}

int changePermission(FileSystem *fs, int processID, char fileName, int newPermission)
{

	// Find inode
	Inode *inode = findInode(fs, fileName);
	if (inode == NULL)
		return 1;

	////////////////~If the inode exists~////////////////
	// Find the node of that processID in inode->accessCL
	FilePermission *newFP = inode->accessCL->head->next;
	while (newFP != NULL)
	{
		if (newFP->processID == processID)
		{
			break;
		}
		newFP = newFP->next;
	}

	if (newFP == NULL)
	{
		return 2;
	}

	// If it exists, just set permission to newPermission
	if (newFP->processID == processID)
	{
		if (newPermission == 0)
		{ // If newPermission = 0, delete node
			deleteNode(inode->accessCL, processID);
			return 0;
		}
		else // If the permissions aren't 0, change the permissions
		{
			newFP->permission = newPermission;
		}
	}
	else
	{ // If the node doesn't exist, add it up
		newFP->permission = newPermission;
		addNode(inode->accessCL, newFP);
	}

	return 0;
}