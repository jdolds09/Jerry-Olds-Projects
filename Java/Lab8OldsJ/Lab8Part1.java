/*
 * Lab 8 Part 1
 * CSE-1310-005
 */
package lab8part1;

import java.util.InputMismatchException;
import java.util.Random;
import java.util.Scanner;

/**
 *
 * @author Jerry Olds
 */
public class Lab8Part1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
    // Variables
        Scanner input = new Scanner(System.in);
        String title = "TIC TAC TOE";
        String playAgain = "y";
        String username;
    // Title
        System.out.printf("%90s\n",title);
    // Greet User and get Username
        System.out.print("Hello! Please enter your name: ");
        username = input.nextLine();
    while(!playAgain.equalsIgnoreCase("n"))
    {   
    // Variables
        final int MAX_SIZE = 9;
        String board [] = new String[MAX_SIZE]; 
        String mark;
        int moveNumber = 0;
        int count;
        int winner;
        boolean gameOver = false;
        boolean invalidInput;
    // Initialize board array with values;
        for(count = 0; count < MAX_SIZE; count++)
            board[count] = ""+(count + 1);
    // Set count back to 0
        count = 0;
    // Ask if user would like to be X's or O's
        System.out.println();
        System.out.println("Would you like to be X's or O's?");
        System.out.print("Enter (X) to be X's or enter (O) to be O's: ");
        mark = input.next();
        while(!mark.equalsIgnoreCase("x") && !mark.equalsIgnoreCase("o"))
        {
            System.out.println("Invalid Input.");
            System.out.print("Enter (X) to be X's or enter (O) to be O's: ");
            mark = input.next();
        }
    // Display Board
        System.out.println();
        System.out.println(" 1 | 2 | 3 ");
        System.out.println("-----------");
        System.out.println(" 4 | 5 | 6 ");
        System.out.println("-----------");
        System.out.println(" 7 | 8 | 9 ");
        System.out.println();
    // Input values until game is over
        while(!gameOver)
        {
        // Prompt User
            System.out.print("Your move "+username+"! Please enter the number of your desired spot: ");
            invalidInput = true;
        // Input Validation
            while(invalidInput)
            {
                try
                {
                    moveNumber = input.nextInt();
                    while(moveNumber < 1 || moveNumber > 9)
                    {
                        System.out.println("Invalid input.");
                        System.out.print("Please enter the number of your desired spot: ");
                        moveNumber = input.nextInt();
                    }
                }
                catch(InputMismatchException ime)
                {
                    System.out.println("Invalid input. Default value of 1 will be used.");
                    moveNumber = 1;
                    input.next();
                }
                invalidInput = inputValidation(board, moveNumber);
                if(invalidInput)
                {
                    System.out.println();
                    System.out.println("That spot is already taken!");
                    System.out.print("Please choose another spot: ");
                }
            }
            System.out.println();
            count++;
        // Send input to generateBoard method
            generateBoard(board, mark, username, moveNumber, count);
        // Check to see if there is a winner
            winner = gameOverCheck(board, mark, username);
        // Display Winner Output
            if(winner == 1)
            {
                System.out.println();
                System.out.println("Congratulations "+username+"! You Win!");
                gameOver = true;
            }
            if(winner == 2)
            {
                System.out.println();
                System.out.println("You Lose! Better Luck Next Time!");
                gameOver = true;
            }
            if(!gameOver && count == 5)
            {
                System.out.println();
                System.out.println("Draw!");
                gameOver = true;
            }
        }
        System.out.println();
        System.out.print("Play Again? Please enter (Y) to play again or (N) to quit: ");
        playAgain = input.next();
        while(!playAgain.equalsIgnoreCase("y") && !playAgain.equalsIgnoreCase("n"))
        {
            System.out.println("Invalid Input.");
            System.out.print("Please enter (Y) to play again or (N) to quit: ");
            playAgain = input.next();
        }
            input.nextLine();
        }
    }

public static boolean inputValidation(String[] board, int num)
{
// Check to see if spot is already taken
    if(board[num - 1].equals("X") || board[num - 1].equals("O"))
        return true;
    else
        return false;
}
    
public static void generateBoard(String[] board, String mark, String name, int num, int count)
{
// Variables
    Random rand = new Random();
    int value;
    int winner;
// Generate Board if user is (X)
    if(mark.equalsIgnoreCase("x"))
    {
        board[num - 1] = "X";
    // Check to see if game is over
        winner = gameOverCheck(board, mark, name);
    // CPU Move
        value = rand.nextInt(9);
        while((board[value].equals("X") || board[value].equals("O")) && count < 5)
            value = rand.nextInt(9);
        if(count < 5 && (winner != 1 && winner != 2))
            board[value] = "O";
    // Print Board
        System.out.println(" "+board[0]+" | "+board[1]+" | "+board[2]+" ");
        System.out.println("-----------");
        System.out.println(" "+board[3]+" | "+board[4]+" | "+board[5]+" ");
        System.out.println("-----------");
        System.out.println(" "+board[6]+" | "+board[7]+" | "+board[8]+" ");
    }
// Generate Board if user is (O)
    else
    {
        board[num - 1] = "O";
    // Check to see if game is over
        winner = gameOverCheck(board, mark, name);
    // CPU Move
        value = rand.nextInt(9);
        while((board[value].equals("X") || board[value].equals("O")) && count < 5)
            value = rand.nextInt(9);
        if(count < 5 && (winner != 1 && winner != 2))
            board[value] = "X";
    // Print Board
        System.out.println(" "+board[0]+" | "+board[1]+" | "+board[2]+" ");
        System.out.println("-----------");
        System.out.println(" "+board[3]+" | "+board[4]+" | "+board[5]+" ");
        System.out.println("-----------");
        System.out.println(" "+board[6]+" | "+board[7]+" | "+board[8]+" ");
    }
}

public static int gameOverCheck(String[] board, String mark, String name)
{
// Variables
    final int ROW_MAX = 8;
    final int COLUMN_MAX = 9;
    int token;
    String winners[][] = new String[ROW_MAX][COLUMN_MAX];
    for(int count = 0; count < ROW_MAX; count++)
    {
        for(int counter = 0; counter < COLUMN_MAX; counter++)
        {
            winners[count][counter] = "A";
        }
    }
// Winning Condition #1
    winners[0][0] = "W";
    winners[0][1] = "W";
    winners[0][2] = "W";
// Winning Condition #2
    winners[1][3] = "W";
    winners[1][4] = "W";
    winners[1][5] = "W";
// Winning Condition #3 
    winners[2][6] = "W";
    winners[2][7] = "W";
    winners[2][8] = "W";
// Winning Condition #4
    winners[3][0] = "W";
    winners[3][3] = "W";
    winners[3][6] = "W";
// Winning Condition #5
    winners[4][1] = "W";
    winners[4][4] = "W";
    winners[4][7] = "W";
// Winning Condition #6
    winners[5][2] = "W";
    winners[5][5] = "W";
    winners[5][8] = "W";
// Winning Condition #7
    winners[6][0] = "W";
    winners[6][4] = "W";
    winners[6][8] = "W";
// Winning Condition #8
    winners[7][2] = "W";
    winners[7][4] = "W";
    winners[7][6] = "W";
// Check for winner when user is (X)
    if(mark.equalsIgnoreCase("x"))
    {
    // Check to see if user wins
        for(int count = 0; count < ROW_MAX; count++)
        {
            token = 0;
            for(int counter = 0; counter < COLUMN_MAX; counter++)
            {
                if(winners[count][counter].equals("W") && board[counter].equals("X"))
                {
                    token++;
                    if(token == 3)
                        return 1;
                }
            }
        }
    // Check to see if CPU wins
        for(int count = 0; count < ROW_MAX; count++)
        {
            token = 0;
            for(int counter = 0; counter < COLUMN_MAX; counter++)
            {
                if(winners[count][counter].equals("W") && board[counter].equals("O"))
                {
                    token++;
                    if(token == 3)
                        return 2;   
                }
            }
        }
    }
// Check for winner when user is (O)
    else
    {
    // Check to see if user wins
        for(int count = 0; count < ROW_MAX; count++)
        {
            token = 0;
            for(int counter = 0; counter < COLUMN_MAX; counter++)
            {
                if(winners[count][counter].equals("W") && board[counter].equals("O"))
                {
                    token++;
                    if(token == 3)
                       return 1;
                    
                }
            }
        }
    // Check to see if CPU wins
        for(int count = 0; count < ROW_MAX; count++)
        {
            token = 0;
            for(int counter = 0; counter < COLUMN_MAX; counter++)
            {
                if(winners[count][counter].equals("W") && board[counter].equals("X"))
                {
                    token++;
                    if(token == 3)
                       return 2;
                }
            }
        } 
    }
return 3;
}

}