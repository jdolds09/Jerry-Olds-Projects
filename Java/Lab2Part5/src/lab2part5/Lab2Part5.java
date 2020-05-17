/*
 * CSE 1310-005
 * Lab 2 Part 5
 */
package lab2part5;

import java.util.Scanner;

/**
 *
 * @author Jerry Olds
 */
public class Lab2Part5 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        // Variables
        Scanner input = new Scanner(System.in);
        double boxHeightInFeet;
        double boxWidthInFeet;
        double boxDepthInFeet;
        double boxWeightInKilograms;
        double volumeInInches;
        double weightPCI;
        // Get Height
        System.out.print("Please enter the Height of the box in Feet: ");
        boxHeightInFeet = input.nextDouble();
        while(boxHeightInFeet <= 0)
        {
            System.out.println("Invalid Input.");
            System.out.print("Please enter the Height of the box in Feet: ");
            boxHeightInFeet = input.nextDouble();
        }
        // Get Width
        System.out.print("Please enter the Width of the box in Feet: ");
        boxWidthInFeet = input.nextDouble();
        while(boxWidthInFeet <= 0)
        {
            System.out.println("Invalid Input.");
            System.out.print("Please enter the Width of the box in Feet: ");
            boxWidthInFeet = input.nextDouble();
        }
        // Get Depth
        System.out.print("Please enter the Depth of the box in Feet: ");
        boxDepthInFeet = input.nextDouble();
        while(boxDepthInFeet <= 0)
        {
            System.out.println("Invalid Input.");
            System.out.print("Please enter the Depth of the box in Feet: ");
            boxDepthInFeet = input.nextDouble();
        }
        // Get Weight
        System.out.print("Please enter the Weight of the box in Kilograms: ");
        boxWeightInKilograms = input.nextDouble();
        while(boxWeightInKilograms <= 0)
        {
            System.out.println("Invalid Input.");
            System.out.print("Please enter the Weight of the box in Kilograms: ");
            boxWeightInKilograms = input.nextDouble();
        } 
        // Calculate Volume and Weight Per Cubic Inch
        volumeInInches = ((boxHeightInFeet * 12) * (boxWidthInFeet * 12) * (boxDepthInFeet * 12));
        weightPCI = boxWeightInKilograms / volumeInInches;
        // Output Results
        System.out.println();
        System.out.printf("%s%11s%10s%10s%9s\n", "Units", "Height", "Width", "Depth", "Volume");
        System.out.printf("%s%9.1f%10.1f%10.1f%11.1f\n", "Inches", boxHeightInFeet * 12, boxWidthInFeet * 12, boxDepthInFeet * 12, volumeInInches);
        System.out.printf("%s%11.2f%10.2f%10.2f%9.2f\n", "Feet", boxHeightInFeet, boxWidthInFeet, boxDepthInFeet, (volumeInInches / 1728));
        System.out.println();
        System.out.printf("%s%10s%11s%11s\n", "Weight in", "Pounds", "Kilograms", "Kg per In");
        System.out.printf("%19.4f%9.4f%11.4f\n", boxWeightInKilograms * 2.2, boxWeightInKilograms, weightPCI);
    }
    
}
