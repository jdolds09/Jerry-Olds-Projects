/*
 * CSE-1305-005
 * Lab 1 Part 5
 */
package lab1part5;

/**
 *
 * @author Jerry Olds
 */
public class Lab1Part5 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
       int radius = 6;
       double pi4places = 3.1415;
       System.out.println("radius = 6");
       double circumference = pi4places * (radius * 2);
       System.out.println("Circumference = "+circumference);
       double area = pi4places * (radius * radius);
       System.out.println("Area = "+area);
    }
    
}
