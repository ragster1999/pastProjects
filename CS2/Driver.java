package yCOS212_FinalProjectDriver;

import java.util.*;

public class Driver {

	public static void main(String[] args) 
	{
		int throwAway;
		// Hello, welcome to the code for my game.
		Scanner input = new Scanner(System.in); // duh

		Model g = new Model();

		System.out.println("Would you like to create a custom a game? (1 for yes)");
		throwAway = input.nextInt();
		if (throwAway == 1)
		{
			g.setCustomGame(true); 
			System.out.println("Custom game has been set");
		}

		// Main while loop for the game
		while (g.isPlay() && !g.isWonGame())
		{
			// Game SETUP
			// Populate key
			System.out.println("\n\n============ NEW GAME ======================");

			// Section to create key
			if (g.isCustomGame())
			{
				System.out.print("\nPlease enter desired number of pegs: \t");
				g.setNumPegs(input.nextInt());
				System.out.print("\nEnter new sequence: \t");
				try {
					g.newCustomGame(input.next());
				} catch (Exception e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
					System.out.println("Incorrect number of pegs");
				}
			}
			else
			{
				g.newGame();
			}

			// System.out.print("\nCorrect Sequence: " + g.printKey() + "\n"); // check



			System.out.println("\nEnter your guesses in format: " + g.getFormatString());

			////////////////////////////////////////////////////////////////////////////////////
			// Game PLAY
			while (g.getTurn() < 10 && !g.isWonGame())
			{

				System.out.print("\nGuess #" + (1 + g.getTurn()) + "-->\t");
				try {
					g.setGuess(input.next());
				} catch (Exception e) {
					e.printStackTrace();
					System.out.println("Incorrect guess length");
				}


				// If they won (4 black) , break
				if (g.countNumBlack() == g.getNumPegs()) // if they guessed everything correctly
				{
					g.setWonGame(true);
				}
				else
				{
					// Print out the guess information
					System.out.println("Black: " + g.countNumBlack());
					System.out.println("White: " + g.countNumWhite());
				}

			}

			// Win / Lose Conditions
			if (g.getTurn() < 10)
			{
				// WINNER
				System.out.println("Congrats!! You won with a total of " + (11 - g.getTurn())+ " points <3");
			}
			else
			{
				// LOSER
				System.out.print("\nOpe, you lost. Sorry about it. The correct sequence was: " + g.printKey()); 
				System.out.println("\n");
			}





			g.setWonGame(false);
			System.out.println("\n\nWould you like to play again? (1 for yes)");
			throwAway = input.nextInt();
			if (throwAway != 1)
				g.setPlay(false);


		}


		System.out.println("Thank you for playing!!");
		input.close();
	}
}


/* Key
 * Black peg: Correct color, correct position
 * White peg: Correct color, incorrect position


 */