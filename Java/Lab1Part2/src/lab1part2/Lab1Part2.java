/*
 * CSE-1305-005
 * Lab 1 Part 2
 */
package lab1part2;

/**
 *
 * @author Jerry Olds
 */
public class Lab1Part2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // Manipulating Integer variables
        int num1 = 64; // num1 & num2 are variables
        int num2;      // that can hold INTeger values
        System.out.println("Printing variable values");
        System.out.println("Num1 = "+num1);
        num2 = 8;
        System.out.println("Num2 = "+num2);
        System.out.println("Sum of num1 & num2 = "+(num1 + num2));
        System.out.println(); // prints blank line
        
        num1 = num1 - (num2 * 6);
        num2 = num2 / 4 + num1;
        System.out.println("New value of num1 is "+num1);
        System.out.println(num2+ " is the final value of num2");
        System.out.println("Sum of nums(version 1) "+ num1 + num2);
        System.out.println("Sum of nums(version 2) "+(num1+ num2));
    }
    
}
