using System;

public class Exercises04
{
    public void Exercise04_01()
    {
        // Count how many numbers between 1 and 100 are divisable by 3 with no remainder and display output
        int count = 0;
        for(int i = 1; i <= 100; i++)
        {
            if (i % 3 == 0)
            {
                count++;
            }
        }
        System.Console.WriteLine(count);
    }

    public void Exercise04_02()
    {
        // ask user to input line "ok" and iterate until they don't, then at the end print out how many times they typed "ok"
        int count = 0;
        while(true)
        {
            System.Console.WriteLine("Type \"ok\": ");
            var input = Console.ReadLine();
            if(input == "ok")
            {
                count++;
                continue;
            }
            System.Console.WriteLine("\nWe out, but with " + count + " ok's");
            break;
        }
    }

    public void Exercise04_04()
    {
        var randNum = new Random();
        randNum.Next(0, 10);
        byte guesses = 4;

        while (guesses > 0)
        {
            var currentGuess = Console.ReadLine();

            try
            {
                if ((int)currentGuess == randNum)
                {
                    System.Console.WriteLine("You guessed it!");
                    break;
                }
            }
            catch (System.Exception)
            {
                System.Console.WriteLine("Not valid input.");
            }

            guesses--;
            System.Console.WriteLine("You have " + guesses + "left.");
        }
        if (guesses < 1)
        {
            System.Console.WriteLine("You've lost, sorry pal :/");
        }
    }
}