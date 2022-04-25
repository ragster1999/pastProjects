CC = g++
CFLAGS = -g -Wall -pthread -Werror

default: SSDriver

SSDriver: SSDriver.o Process.o ProcessTable.o FileSystem.o Memory.o Inode.o
	$(CC) $(CFLAGS) -o SSDriver SSDriver.o FileSystem.o Memory.o Inode.o Process.o ProcessTable.o

FileSystem: FileSystem.o Memory.o Inode.o Process.o
	$(CC) $(CFLAGS) -o FileSystem FileSystem.o Memory.o Inode.o Process.o

ProcessTable.o: ProcessTable.cpp ProcessTable.h Process.o
	$(CC) $(CFLAGS) -c ProcessTable.cpp

Process.o: Process.h Process.cpp
	$(CC) $(CFLAGS) -c Process.cpp

Memory.o: Memory.h Memory.cpp
	$(CC) $(CFLAGS) -c Memory.cpp

Inode.o: Inode.h Inode.cpp
	$(CC) $(CFLAGS) -c Inode.cpp

clean: 
	$(RM) Driver *.o*
