package application;


import java.util.Random;

public class Model 
{
	private boolean customGame;
	private boolean play; // true loop for game-play
	private boolean wonGame; // if the player has won the game or not
	private int turn; // keeps track of what turn it is
	private final static char [] possibleColors = {'R', 'B', 'Y', 'G', 'O', 'P'}; // the possible colors we can have
	private int numPegs; // how many pegs we are playing with
	private boolean canRepeat; // a variable to decide if letters can repeat or not
	private String formatString;

	private char key[];
	private char guess[][];

	/**
	 * A model
	 */
	public Model()
	{
		customGame = false;
		play = true;
		wonGame = false;
		turn = 0;
		numPegs = 4;
		canRepeat = false;

		// Setup Format
		formatString = "";
		for (int i = 0; i < numPegs; i++)
		{
			formatString = formatString + "X";
		}

		guess = new char [10][numPegs];
		key = new char [numPegs];

	}

	public Model(char [] newPossibleColors, int newNumPegs, boolean newCanRepeat)
	{
		setPossibleColors(newPossibleColors);
		numPegs = newNumPegs;
		canRepeat = newCanRepeat;
	}

	/**
	 * Creates a new game and sets the correct values
	 */
	public void newGame()
	{
		// Set turn to 0 and create a new key
		turn = 0;
		for (int i = 0; i < numPegs; i++)
		{
			key[i] = generateRandomColor();
			// System.out.print(" " + key[i]); // Prints the correct sequence
			for (int j = 0; j < 10; j++)
				guess[j][i] = '-';
		}

		if (!canRepeat)
		{
			// check if there are repeats
			for(int i = 0; i < key.length; i++)
			{
				for (int j = 0; j < i; j++)
				{
					if (key[i] == key[j])
					{
						while (key[i] == key[j])
						{
							key[i] = generateRandomColor();
						}
						i = 0; j = i;
					}
				}
			}
		}

	}

	/**
	 * Creates a custom game
	 * @param s
	 * @throws Exception
	 */
	public void newCustomGame(String s) throws Exception
	{
		// Throw exception if it doesn't match length
		turn = 0;
		if (s.length() != numPegs)
			new Exception ("Incorrect number of pegs entered");

		// If it does match length
		for (int i = 0; i < numPegs; i++)
		{
			key[i] = lowerCaseToUpperCase(s.charAt(i));
		}
		return;
	}

	public char generateRandomColor()
	{
		// Generate random color from choices: R, B, Y, G, O, P
		int c = new Random().nextInt(possibleColors.length);

		return possibleColors[c];
	}

	public int countNumBlack()
	{
		int counter = 0; // initialize counter
		for (int i = 0; i < key.length; i++)
		{
			// System.out.println(key[i] + ":" + guess[turn][i]);
			if (key[i] == guess[turn][i])
				counter++;
		}
		// System.out.println("Num black from MODEL: " + counter);
		return counter;
	}

	/**
	 * Counts the number of white pegs
	 * @return
	 */
	public int countNumWhite()
	{
		int n = 0;

		for (int i = 0; i < key.length; i++)
		{
			
			for (int j = 0; j < key.length; j++)
			{
				if (key[i] == guess[turn][j])
				{
					n++;
					break;
				}
			}
		}

		n = n - countNumBlack();
		// System.out.println("Num Whites: " + n + "\nTURN : " + turn);
		turn++;
		// Make sure to subtract numBlack
		return n;
	}

	/** 
	 * converts lower case to upper case, and leaves upper alone
	 * @param c
	 * @return an uppercase char
	 */
	public char lowerCaseToUpperCase(char c)
	{
		if ((int)c >= 97 && c <= 122)
			c = (char)((int)c - 32);

		return c;
	}


	/**
	 * Prints out the key
	 * @return
	 */
	public String printKey()
	{
		String s = "";
		for (int i = 0; i < key.length; i++) 
			s = s + key[i];
		return s;
	}

	/**
	 * Prints out the guess
	 * @return
	 */
	public String printGuess()
	{
		String s = "";
		for (int i = 0; i < guess.length; i++) 
			s = s + guess[turn][i];
		return s;
	}

	////////////////////~Setters and Getters~////////////////////////////////
	/**
	 * @return the play
	 */
	public boolean isPlay() {
		return play;
	}

	/**
	 * @param play the play to set
	 */
	public void setPlay(boolean play) {
		this.play = play;
	}

	/**
	 * @return the wonGame
	 */
	public boolean isWonGame() {
		return wonGame;
	}

	/**
	 * @param wonGame the wonGame to set
	 */
	public void setWonGame(boolean wonGame) {
		this.wonGame = wonGame;
	}

	/**
	 * @return the turn
	 */
	public int getTurn() {
		return turn;
	}

	/**
	 * @return the possibleColors
	 */
	public char[] getPossibleColors() {
		return possibleColors;
	}

	/**
	 * @param possibleColors the possibleColors to set
	 */
	public void setPossibleColors(char[] newPossibleColors) 
	{
		for (int i = 0; i < newPossibleColors.length; i++)
		{
			possibleColors[i] = newPossibleColors[i];
		}
		return;
	}

	/**
	 * @return the numPegs
	 */
	public int getNumPegs() {
		return numPegs;
	}

	/**
	 * @return the canRepeat
	 */
	public boolean isCanRepeat() {
		return canRepeat;
	}

	/**
	 * @param canRepeat the canRepeat to set
	 */
	public void setCanRepeat(boolean canRepeat) {
		this.canRepeat = canRepeat;
	}

	/**
	 * @param guess the guess to set
	 */
	public void setGuess(String s) throws Exception
	{
		// If length of s != numPegs.length, throw exception
		if (s.length() != numPegs)
			new Exception("Incorrect guess length");

		// If length is correct, set array
		for (int i = 0; i < numPegs; i++)
		{
			if (!isViableGuess(s.charAt(i)))
				new Exception("Guess '" + s.charAt(i) + "' is not viable");
			
			guess[turn][i] = lowerCaseToUpperCase(s.charAt(i));
		}
		return;
	}

	/**
	 * @return the formatString
	 */
	public String getFormatString() {
		return formatString;
	}

	public void setCustomGame(boolean bool)
	{
		customGame = bool;
	}

	/**
	 * Checks for custom game
	 * @return true or false
	 */
	public boolean isCustomGame()
	{
		return customGame;
	}
	
	/**
	 * A method to check if a guess is viable
	 * @param c the char of guess
	 * @return true or false
	 */
	public boolean isViableGuess(char c)
	{
		for (int i = 0; i < possibleColors.length; i++)
		{
			if (lowerCaseToUpperCase(c) == lowerCaseToUpperCase(possibleColors[i]))
				return true;
		}
		return false;
	}

}


/* *TODO: 
 	* Throw exceptions if invalid guess
 	* Delete play question at beginning
 	* Delete variable length
 	* Fix double counting in countNumWhites() 
	
	
	
	*/
