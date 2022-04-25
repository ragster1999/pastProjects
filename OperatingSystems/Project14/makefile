CC = g++
CFLAGS = -g -Wall -pthread -Werror

default: SSAndPermissionsDriver

SSAndPermissionsDriver: SSAndPermissionsDriver.o Process.o ProcessTable.o FileSystem.o Memory.o Inode.o LL.o
	$(CC) $(CFLAGS) -o SSAndPermissionsDriver SSAndPermissionsDriver.o FileSystem.o Memory.o Inode.o Process.o ProcessTable.o LL.o

PermissionsDriver: PermissionsDriver.o Process.o ProcessTable.o FileSystem.o Memory.o Inode.o LL.o
	$(CC) $(CFLAGS) -o PermissionsDriver PermissionsDriver.o FileSystem.o Memory.o Inode.o Process.o ProcessTable.o LL.o

FileSystem: FileSystem.o Memory.o Inode.o Process.o
	$(CC) $(CFLAGS) -o FileSystem FileSystem.o Memory.o Inode.o Process.o

ProcessTable.o: ProcessTable.cpp ProcessTable.h Process.o
	$(CC) $(CFLAGS) -c ProcessTable.cpp

Process.o: Process.h Process.cpp
	$(CC) $(CFLAGS) -c Process.cpp

Memory.o: Memory.h Memory.cpp
	$(CC) $(CFLAGS) -c Memory.cpp

Inode.o: Inode.h Inode.cpp LL.o
	$(CC) $(CFLAGS) -c Inode.cpp

LL.o: LL.h LL.cpp
	$(CC) $(CFLAGS) -c LL.cpp
clean: 
	$(RM) Driver *.o*
