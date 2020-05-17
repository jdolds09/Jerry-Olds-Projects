/*
 * CSE-1305-005
 * Lab 1 Part 3 
 */
package lab1part3;

/**
 *
 * @author Jerry Olds
 */
public class Lab1Part3 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // Correctly convert a Celsius temperature to a Fahrenheit temperature
        double celsTemp;
        celsTemp = 35;
        System.out.println("The Celsius temp is "+celsTemp);
        double fahrTemp;
        fahrTemp = ((celsTemp * 9/5) + 32);
        System.out.println("The converted Fahrenheit temp is "+fahrTemp);
        System.out.println();
        System.out.println();
    }
    
}
