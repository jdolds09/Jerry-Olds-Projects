/*
 * CSE-1310-005
 * Lab 2 Part 2d
 */
package lab2part2d;

import java.util.Scanner;

/**
 *
 * @author Jerry Olds
 */
public class Lab2Part2d {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
       /*
        Declare the needed input object here using the names shown below in the
        program. Also add any other needed lines to make the input object function.
        */
        // input here should be "1310 or 1320"
        
        // Object
        Scanner input = new Scanner(System.in);
        // Variables
        int num;
        // Course Number
        System.out.print("Please enter a 4-digit course number of 1310 or 1320: ");
        String courseNum = input.next();
         try
         {
           num = Integer.parseInt(courseNum);
         }
         catch(NumberFormatException nfe)
         {
            courseNum = "1310";
            num = 1310;
         }
        
        while (num != 1310 && num != 1320)
        {
            System.out.println("Invalid Input.");
            System.out.print("Please enter a 4-digit course number of 1310 or 1320: ");
            courseNum = input.next();
            num = Integer.parseInt(courseNum);
        }
        // Semester
        System.out.print("Please enter the current semester (Fall, Spring, or Summer): ");
        String sem = input.next();
        while(!sem.equalsIgnoreCase("fall") && !sem.equalsIgnoreCase("spring") && !sem.equalsIgnoreCase("summer"))
        {
            System.out.println("Invalid Input.");
            System.out.print("Please enter the current semester (Fall, Spring, or Summer): ");
            sem = input.next();
        }
        // Additional Information
        String dept = "CSE";
        char comma = ',';
        String sectionNum = "005";
        char dash = '-';
        int year = 2017;
        String sp = " ";
        // Output Information
        System.out.println(sem + sp + year + comma + sp + dept + courseNum + dash + sectionNum);
       
    }
    
}
