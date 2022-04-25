// LL.cpp
#include "LL.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Initialize a list and create ad ummy node
 */
LL *initializeLL()
{
	LL *newLL = (LL*)malloc(sizeof(LL));
	newLL->head = (FilePermission*)malloc(sizeof(FilePermission));
	newLL->head->next = NULL;
	newLL->head->processID = -1;
	newLL->head->permission = 0;
	newLL->length = 0;
	return newLL;
}

/**
 * Add a new node to the end of the linked list
 */
int addNode(LL *ll, FilePermission *fp)
{
	FilePermission *iterator = ll->head;
	while (iterator->next != NULL)
		iterator = iterator->next;
	iterator->next = fp;
	ll->length++;
	return 0;
}

/**
 * Delete a node from the linked list if matches the  ID
 */
int deleteNode(LL *ll, int processID)
{
	FilePermission *iterator = ll->head;
	while (iterator->next != NULL && iterator->next->processID != processID)
	{
		iterator = iterator->next;
	}
	if (iterator->next == NULL)
		return 1;
	else
	{
		FilePermission *nodeToDelete =iterator->next;
		iterator->next =iterator->next->next;	
		free(nodeToDelete);
		ll->length--;
		return 0;
	}
}

void freeLL(LL *ll)
{
	while (!isEmpty(ll))
	{
		deleteNode(ll, ll->head->next->processID);
	}
	free(ll->head);
}

void printLL(LL *ll)
{
	FilePermission *iterator = ll->head->next;
    while (iterator != NULL)
	{
		printPermission(iterator->processID, iterator->permission);
		iterator = iterator->next;
	}
}

void printPermission(int processID, int permission)
{
	printf("%d: ", processID);
	if (permission == 0)
		printf("\n");
	else if (permission == 1)
		printf("x\n");
	else if (permission == 2)
		printf("w\n");
	else if (permission == 3)
		printf("wx\n");
	else if (permission == 4)
		printf("r\n");
	else if (permission == 5)
		printf("rx\n");
	else if (permission == 6)
		printf("rw\n");
	else
		printf("rwx\n");

}


/**
 * Return true if the list is empty, false otherwise
 */
bool isEmpty(LL *ll)
{
	return (ll->length == 0);
}


