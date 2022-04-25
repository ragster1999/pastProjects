// LL.h

struct FilePermission
{
	int processID;
	int permission;
	FilePermission *next;
};

struct LL
{
	int length;
	FilePermission* head;
};

LL *initializeLL();

int addNode(LL *ll, FilePermission *newFP);

int deleteNode(LL *ll, int processID);

bool isEmpty(LL *ll);

void printPermission(int processID, int permission);

void printLL(LL *ll);

void freeLL(LL *ll);
