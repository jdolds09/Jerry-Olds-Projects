/*
 * CSE-1310-005
 * Lab 2 Part 1
 */
package lab2part1;

/**
 *
 * @author Jerry Olds
 */
public class Lab2Part1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        int item1 = 5;
        int item2;
        double num1 = 3.0;
        double num2 = 24;
        item2 = 6;
        int titem = item2;
        System.out.println("Printing values");
        System.out.println("int item1 value = "+item1);
        System.out.println("int item2 value = "+item2);
        System.out.println("double num1 value = "+num1);
        System.out.println("double num2 value = "+num2);
        System.out.println();
        
        item2 = item2 / item1;
        System.out.println("orig item2/item1 "+titem+"/"+item1+" = item2 = "+item2);
        item2 = 15;
        System.out.println("resetting item2 value = "+item2);
        System.out.println();
        num2 = item2 / num1;
        System.out.println("item2/num1 "+item2+"/"+num1+" = num2 = "+num2);
        item1 = 8;
        num2 = item1 * num1/ 2;
        System.out.println("item1 * num1/2 "+item1+"*"+num1+"/2 = num2 = "+num2);
        System.out.println();
        System.out.println("int item2 value = "+item2);
        System.out.println("double num1 value = "+num1);
        item2 = (item2 - 1) / 3;
        num1 = (num1 * item2) + 2.1;
        System.out.println("after item2 = (item2-1) / 3: item2 value = "+item2);
        System.out.println("after num1 *= item2 + 2.1: num1 value = "+num1);
        System.out.println();
        
        System.out.println("num1 < item1 is "+(num1 < item1));
        System.out.println("num2 != item2 is "+(num2 != item2));
        System.out.println();
        System.out.println("Printing values");
        System.out.println("int item1 value = "+item1);
        System.out.println("int item2 value = "+item2);
        System.out.println("double num1 value = "+num1);
        System.out.println("double num2 value = "+num2);
    }
    
}
