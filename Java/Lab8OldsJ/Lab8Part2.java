/*
 * Lab 8 Part 2
 * CSE-1310-005
 */
package lab8part2;

import java.util.InputMismatchException;
import java.util.Scanner;

/**
 *
 * @author Jerry Olds
 */
public class Lab8Part2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        String goAgain = "y";
        System.out.println("This program will take a base number and a power number and ouput the result of the exponential function.");
        while(!goAgain.equalsIgnoreCase("n"))
        {
        // Variables
            Scanner input = new Scanner(System.in);
            int base = 0;
            int power = 0;
            long result;
            boolean invalidInput = true;
        // Ask user for base and power
            System.out.println();
            System.out.print("Please enter the base number (0-10): ");
            while(invalidInput)
            {
                try
                {
                    base = input.nextInt();
                    while(base < 0 || base > 10)
                    {
                        System.out.print("Invalid Input. Please enter a number between (0-10): ");
                        base = input.nextInt();
                    }
                    invalidInput = false;
                }
                catch(InputMismatchException ime)
                {
                    System.out.println("Invalid Input.");
                    System.out.print("Please enter the base number (0-10): ");
                    input.next();
                    invalidInput = true;
                }
            }
        // Set invalidInput to true
            invalidInput = true;
        // Prompt user
            System.out.print("Please enter the power number (0-10): ");
            while(invalidInput)
            {
                try
                {
                    power = input.nextInt();
                    while(power < 0 || power > 10)
                    {
                        System.out.print("Invalid Input. Please enter a number between (0-10): ");
                        power = input.nextInt();
                    }
                    invalidInput = false;
                }
                catch(InputMismatchException ime)
                {
                    System.out.println("Invalid Input.");
                    System.out.print("Please enter the power number (0-10): ");
                    input.next();
                    invalidInput = true;
                }
            }
        // Call exponent function
            result = exponent(base, power);
            System.out.println();
            System.out.println("Result: "+result);
            System.out.println();
            System.out.print("To calculate another value enter (Y), enter (N) to quit: ");
            goAgain = input.next();
            while(!goAgain.equalsIgnoreCase("y") && !goAgain.equalsIgnoreCase("n"))
            {
                System.out.println();
                System.out.print("Invalid input. Please enter (Y) to calculate another value or enter (N) to quit: ");
                goAgain = input.next();
            }
            
        }
        
    }

public static long exponent(int b, int p)
{
    if(p == 0)
        return 1;
    if(p == 1)
        return b;
    else
        return b * exponent(b, p - 1);
}
    
}
