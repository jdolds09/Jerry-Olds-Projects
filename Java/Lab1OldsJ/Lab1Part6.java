/*
 * CSE-1305-005
 * Lab 1 Part 6
 */
package lab1part6;

import java.util.Scanner;

/**
 *
 * @author Jerry Olds
 */
public class Lab1Part6 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int radius = 6;
        double pi4places = 3.1415;
        Scanner input = new Scanner(System.in);
        System.out.print("Please enter the radius of the circle: ");
        radius = input.nextInt();
        double circumference = pi4places * (radius * 2);
        System.out.println("Circumference: "+circumference);
        double area = pi4places * (radius * radius);
        System.out.println("Area: "+area);
    }
    
}
