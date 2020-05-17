/*
 * CSE-1310-005
 * Lab 4 Part 1
 */
package lab4part1spr17;

import java.util.Scanner;

/**
 *
 * @author Jerry Olds
 */
public class Lab4Part1Spr17 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
          Scanner input = new Scanner(System.in);

        // Change the names below to better, more meaningful names for the 
        // variables 
        String month; //Was previously "moth"
        String day;   // Was previously 'a'
        int year;     // Was previously "ear"
        int date = 0; // Was previously "aBer"
        int timesRan = 0;// Was previously "count"
        int monthCount = 0;// Was previously "mthct"
        System.out.println(); 
        System.out.println("Give a date input in the form of "
                + "\"Tuesday February 21 2017\".\n  "
                + "If finished, enter \"Done\" :  ");

        day = input.next();
       
        // Fill in the needed control statement and test condition so that 
        // the program can read multiple date inputs from the user
        while(!day.equalsIgnoreCase("Done"))  
        {
            month = input.next();
            date = input.nextInt();
            year = input.nextInt(); 
            // Fill in the variable that should be used to control the switch
            switch (month)      
            { 
                // Complete the missing case statements for April and June.
                // Add the missing action in the May case.
                // How many possible categories of cases would there 
                //     be for this switch where May, may, and MAY are
                //     considered to be all ONE category?  12            
                
                // Add ALL the other needed cases to complete the switch 
                //    using the statements below as the outputs.
                // Thirty days hath September
                // Born on the 4th of July
                // Slow as molasses in January
                // March of the Penguins
                // Augustus Caesar
                // November, n. The eleventh twelfth of a weariness.
                // Try to remember the kind of September
                // October Sky
                // It is December, and nobody asked if I was ready
                // February is merely as long as is needed to pass the time until March
                
                case "January":
                case "JANUARY":
                case "january":
                    System.out.println("Slow as molasses in January");
                    monthCount = 1;
                    break;
                case "February":
                case "FEBRUARY":
                case "february":
                    System.out.println("Febrary is merely as long as is needed to pass the time until March");
                    monthCount = 2;
                    break;
                case "March":
                case "MARCH":
                case "march":
                    System.out.println("March of the Penguins");
                    monthCount = 3;
                    break;
                case "April":
                case "APRIL":
                case "april":
                    System.out.println("April showers");
                    monthCount = 4;
                    break;
                case "may":  
                case "MAY":
                case "May" : 
                    System.out.println("The merry month of May");
                    monthCount = 5;
                    break;
                case "June":
                case "JUNE":
                case "june":
                    System.out.println("Moon, swoon, June");
                    monthCount = 6;
                    break;
                case "July":
                case "JULY":
                case "july":
                    System.out.println("Born on the 4th of July");
                    monthCount = 7;
                    break;
                case "August":
                case "AUGUST":
                case "august":
                    System.out.println("Augustus Caesar");
                    monthCount = 8;
                    break;
                case "September":
                case "SEPTEMBER":
                case "september":
                    System.out.println("Try to remember the kind of September");
                    monthCount = 9;
                    break;
                case "October":
                case "OCTOBER":
                case "october":
                    System.out.println("October Sky");
                    monthCount = 10;
                    break;
                case "November":
                case "NOVEMBER":
                case "november":
                    System.out.println("November, n. The eleventh twelfth of a weariness");
                    monthCount = 11;
                    break;
                case "December":
                case "DECEMBER":
                case "december":
                    System.out.println("It is December, and nobody asked if I was ready");
                    monthCount = 12;
                    break;
                default : System.out.println("Not a month");
                    break;
            }              
            
            System.out.println("Give a date input in the form of "
                    + "\"Tuesday February 21, 2017\".\n  "
                    + "If finished, enter \"Done\" :  ");

            day = input.next();
            timesRan++;  
        }
        // Write a meaningful message in the output statement below with count
        System.out.println("This is how many dates you entered: "+timesRan); 
    }
    
}
