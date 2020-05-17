/*
 * CSE 1310-005
 * Lab 2 Part 3
 */
package lab2part3;

/**
 *
 * @author Jerry Olds
 */
public class Lab2Part3 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        double x1 = 4;
        double y1 = 1;
        double x2 = 1;
        double y2 = 5;
        double x3, y3;
        int base = (int)x1 - (int)x2;
        int height = (int)y2 - (int)y1;
        double hypotenuse = Math.sqrt(Math.pow(base, 2) + Math.pow(height, 2));
        double area;
        area = (base * height) / 2.0;
        
        System.out.printf("The base is length %d and the height is %3d\n",base,height);
        System.out.print("The distance between ("+x1+","+y1+") and ");
        System.out.printf("(%.0f,%2.0f) is %4.1f\n",x2,y2,hypotenuse);
        System.out.print("the area of the right triangle is "+area);
        System.out.println();
        double circumference = base + height + hypotenuse;
        System.out.print("The circumference of the right triangle is "+circumference);
        System.out.println();
    }
    
}
