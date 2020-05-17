/*
 * CSE-1305-005
 * Lab 1 Part 4
 */
package lab1part4;

import java.util.Scanner;

/**
 *
 * @author Jerry Olds
 */
public class Lab1Part4 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
       Scanner myscanner = new Scanner(System.in);
       int a;
       int b;
       System.out.print("Please enter a number: ");
       a = myscanner.nextInt();
       System.out.print("Please enter another number: ");
       b = myscanner.nextInt();
       double c = Math.pow(a,b);
       System.out.println("Value = "+c);
    }
    
}
