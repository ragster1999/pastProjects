#include "FileSystem.h"
#include <stdio.h> 
#include <stdlib.h>

FileSystem *createFileSystem(int newNumberBlocks, int newSizeOfBlock)
{
	FileSystem *fs = (FileSystem*)malloc(sizeof(FileSystem));
	fs->inodes = (Inode**)malloc(sizeof(Inode*)*MAX_INODES);
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

int addFile(FileSystem *fs, char fileName, int numberBlocks)
{
	if (fs->numberInodes == MAX_INODES) // check to see if it's full
		return 1;
	
	// If the filesystem isn't full
	Inode *inode = findInode(fs, fileName); // This will only work if fineInode is finished
	if (inode != NULL)
		return 1;

	// If we get here, we know the inode doesn't exist and we can add it
	fs->inodes[fs->numberInodes] = createInode(fileName, numberBlocks);

	int indexOfNewBlock = fs->numberInodes;
	inode = fs->inodes[indexOfNewBlock];
	for (int i = 0; i < numberBlocks; i++)
	{
		// Find next available free block
		inode->blocks[i] = findFreeBlock(fs->memory);

		// Fill that block with the lower case version of the file name
		fillBlock(fs->memory, inode->blocks[i], fileName+32);
	}
	
	// Update number of inodes occupied
	fs->numberInodes++;
	return 0;
}

int removeFile(FileSystem *fs, char fileName)
{
	Inode *inode = findInode(fs, fileName); 
	
	// Check to see if the inode doesn't exists
	if (inode == NULL)
		return 1; // File doesn't exist

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
		iterator ++;
		
	}

	// Free blocks associated with file
	freeMemory(fs->memory);

	// Remove inode from inode array
	inode = NULL;

	fs->numberInodes--;
	return 0;
}

int editFile(FileSystem *fs, char fileName, int offset, char newData)
{
	// Check to see if the inode exists
	Inode *inode = findInode(fs, fileName); 
	if (inode == NULL)
		return 1;

	////////////////~If the inode exists~////////////////
	int row = 0;
	for (int i = 0; i < MAX_INODES; i++)
	{// If the file name (lower case) matches the memory
		if (fs->memory->data[i * fs->memory->sizeOfBlock] == fileName + 32)
		{
			row = i; break;
		}
	}

	fs->memory->data[offset + (row * fs->memory->sizeOfBlock)] = newData;

	return 0;
}

int printFile(FileSystem *fs, char fileName)
{
	Inode *inode = findInode(fs, fileName);
    if (inode == NULL)
        return 1;

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

