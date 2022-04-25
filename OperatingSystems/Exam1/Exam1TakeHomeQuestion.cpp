/////////////////////
// Exam question
/////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

char *array;	   // The array of characters generated
int vowels[5];	 // The counts of each vowel
int size;		   // The size of the array
int numberThreads; // The number of threads to use

pthread_mutex_t mutexLock[10]; // creates a mutex lock variable
int count = 0;

/* waste cycles method */
void wasteCycles(int number)
{
	clock_t start = clock();
	clock_t end = clock();
	while (end - start < number)
		end = clock();
}

/* This method counts the number of vowels each
and populates the vowels array */
void *countVowels(void *input)
{
	pthread_mutex_lock(&mutexLock[count]);
	long myID = (long)input;
	/** This code ensures each thread does exactly the same number of elements based on the range
	 and its ID number */
	int range = size / numberThreads;
	int myLower = myID * range;
	int myUpper = (myID + 1) * range;
	int mySmallest = array[myLower];
	for (int i = myLower; i < myUpper; i++)
	{
		int x = -1;
		if (array[i] == 'a')
			x = 0;
		if (array[i] == 'e')
			x = 1;
		if (array[i] == 'i')
			x = 2;
		if (array[i] == 'o')
			x = 3;
		if (array[i] == 'u')
			x = 4;
		/* If x is not equal to -1, means one of the vowels was found and the variable x
		gets sets to that index accordingly */
		if (x >= 0)
		{
			/* Retrieve the current value of vowels[x] */
			int currentValue = vowels[x];
			/* Increase the count by 1 */
			currentValue = currentValue + 1;
			//wasteCycles(10); // what a waste of cycles
			/* Write the new value back to the vowels count at that same location */
			vowels[x] = currentValue;
		}
	}
	pthread_mutex_unlock(&mutexLock[count]);
	count++;
}

/* The main method 
argv[1] = Number of threads
argv[2] = The input number that dictates the size of the array */
int main(int argc, char *argv[])
{
	char letters[5] = {'a', 'e', 'i', 'o', 'u'};
	numberThreads = atoi(argv[1]);
	size = atoi(argv[2]);
	srand(100);
	array = (char *)malloc(sizeof(char) * size);
	for (int i = 0; i < 5; i++)
		vowels[i] = 0;
	/* Populating the array */
	for (int i = 0; i < size; i++)
		array[i] = rand() % 26 + 'a';
	clock_t start = clock(); // start the clock
	pthread_t threads[numberThreads];
	/* Initializing the threads */
	for (long i = 0; i < numberThreads; i++)
	{
		pthread_create(&threads[i], NULL, countVowels, (void *)i);
	}
	/* Joining the threads */
	for (int i = 0; i < numberThreads; i++)
		pthread_join(threads[i], NULL);

	clock_t end = clock(); // stop the clock
	/* Printing out the number of vowels each */
	for (int i = 0; i < 5; i++)
	{
		printf("%c: %d\n", letters[i], vowels[i]);
	}
	printf("\nTime taken: %lf seconds\n\n", ((double)end-start)/CLOCKS_PER_SEC);
	free(array);
	return 0;
}
