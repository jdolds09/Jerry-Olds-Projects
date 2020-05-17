/*
 * CSE-1305-005
 * Lab 3 Part 3a
 */
package lab3part3a;

import java.util.Scanner;

/**
 *
 * @author Jerry Olds
 */
public class Lab3Part3a {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
      // Variables
        double groceryBill = 0.0;
        double price = 0.0;
        double highestPrice = 0.0;
        int itemCount = 0;
        int quantity;
        int largestQuantity = 0;
        Scanner input = new Scanner(System.in);
      // Output
        System.out.println("This program will read in the price and quantity of items,"
                + " then output the total cost\nalong with the highest priced item and "
                + "the item with the highest quantity.");
        System.out.println("Enter the value -1 for price to display results.");
      
      // Loop
        while(price != -1)
        {
            System.out.println();
            System.out.print("Please enter the price of the item: ");
            price = input.nextDouble();
            if (price != -1)
            {
                while(price <= 0 && price != -1)
                {
                   System.out.println();
                   System.out.println("Invalid Input.");
                   System.out.print("Please enter the price of the item: ");
                   price = input.nextDouble();
                }
                if(price > highestPrice)
                {
                    highestPrice = price;
                }
                System.out.print("Please enter the quantity of the item: ");
                quantity = input.nextInt();
                while(quantity <= 0)
                {
                   System.out.println();
                   System.out.println("Invalid Input.");
                   System.out.print("Please enter the quantity of the item: ");
                   quantity = input.nextInt(); 
                }
                if(quantity > largestQuantity)
                {
                    largestQuantity = quantity;
                }
                groceryBill += (price * quantity);
                itemCount++;
            }
        }
      // Display Results
        System.out.println();
        System.out.printf("Total cost: $%.2f\n", groceryBill);
        System.out.println("Total items: "+itemCount);
        System.out.printf("Highest price : $%.2f\n", highestPrice);
        System.out.println("Largest quantity: "+largestQuantity);
    }
    
}
