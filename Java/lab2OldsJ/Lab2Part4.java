/*
 * CSE 1310-005
 * Lab 2 Part 4
 */
package lab2part4;

/**
 *
 * @author Jerry Olds
 */
public class Lab2Part4 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        // Variables
        double boxHeightInFeet = 1.5;
        double boxWidthInFeet = 0.5;
        double boxDepthInFeet = 0.75;
        double boxWeightInKilograms = 4.5;
        double volumeInInches;
        double weightPCI;
        // Math Function
        boxHeightInFeet = Math.ceil(boxHeightInFeet);
        // Calculate Volume and Weight Per Cubic Inch
        volumeInInches = ((boxHeightInFeet * 12) * (boxWidthInFeet * 12) * (boxDepthInFeet * 12));
        weightPCI = boxWeightInKilograms / volumeInInches;
        // Output Results
        System.out.println("Box height in feet is "+boxHeightInFeet+ " and Box height in inches is "+(boxHeightInFeet * 12));
        System.out.println("Box width in feet is "+boxWidthInFeet+ " and Box width in inches is "+(boxWidthInFeet * 12));
        System.out.println("Box depth in feet is "+boxDepthInFeet+ " and Box depth in inches is "+(boxDepthInFeet * 12));
        System.out.println();
        System.out.println("Box volume in inches is "+volumeInInches);
        System.out.println();
        System.out.println("Box weight in Kg is "+boxWeightInKilograms);
        System.out.println("Box weight in Kg per inch is "+weightPCI);
        System.out.println("Box weight in lbs is "+(boxWeightInKilograms * 2.2));
    }
    
}
