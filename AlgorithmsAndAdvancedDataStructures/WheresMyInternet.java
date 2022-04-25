package whereIsMyInternet;

import java.util.LinkedList;
import java.util.Queue;

public class WheresMyInternet{

	public static void main(String[] args)
	{
		// Create file to read in from
		Kattio io = new Kattio(System.in, System.out);
		int N = io.getInt(); // Number of houses
		int M = io.getInt(); // Number of connections


		// Create an array of Linked Lists to store edge connections
		LinkedList<Integer>[] houses = new LinkedList[N+1]; // N+1 here so I don't have to do N-1 everywhere else

		// Initialize array of linked lists
		for (int i = 0; i < N+1; i++)
			houses[i] = new LinkedList<Integer>();

		// Store connections in linked list
		int x, y;
		for (int i = 0; i < M; i++)
		{
			// Store variables
			x = io.getInt();
			y = io.getInt();

			// Add connections to linked list
			houses[x].add(y);
			houses[y].add(x);
		}

		boolean [] houseConnectionArray = new boolean[N];
		houseConnectionArray[0] = true; // initialize 1

		// Create a queue and add 1
		Queue<Integer> houseQueue = new LinkedList<Integer>();
		houseQueue.add(1);
		int current = 0;

		// Create a loop while the queue is not empty
		while (!houseQueue.isEmpty()) // While there is a queue
		{
			//System.out.println("Current: " + houseQueue.peek()); // check
			while(!houses[houseQueue.peek()].isEmpty()) // while 
			{
				if (!houseConnectionArray[houses[houseQueue.peek()].peek() - 1])
				{
					//System.out.println("Add: " + houses[houseQueue.peek()].peek()); // check
					houseQueue.add(houses[houseQueue.peek()].peek()); // add to houseQueue if not already connected
					houseConnectionArray[houses[houseQueue.peek()].peek() - 1] = true;
				}
				houses[houseQueue.peek()].remove();
			}
			//System.out.println("Pop: " + houseQueue.peek());
			houseQueue.remove();
		}

		//System.out.println("\n===================\n" + "  finished queue \n" + "===================\n\n" ); // check

		// Check to see if every house is connected
		// Check to see if every house is connected
		boolean allHousesConnected = true;
		int pickup = N;
		for (int i = 1; i < N; i++)
		{
			if(!houseConnectionArray[i])
			{
				allHousesConnected = false;
				pickup = i;
				break;
			}
		}

		// Print output
		if (allHousesConnected)
		{
			io.println("Connected");
		}
		else
		{
			for (int i = pickup; i < N; i++)
			{
				if(!houseConnectionArray[i])
				{
					allHousesConnected = false;
					io.println(i+1);
				}
			}
		}
		// Close io
		io.close();
	}
}

/* Sample Input

6 4
1 2
2 3
3 4
5 6

 */
