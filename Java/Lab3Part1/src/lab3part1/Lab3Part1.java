/*
 * CSE-1305-005
 * Lab 3 Part 1
 */
package lab3part1;

import java.util.InputMismatchException;
import java.util.Scanner;

/**
 *
 * @author Jerry Olds
 */
public class Lab3Part1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        // Choose car based on init cost, mpg, $ per gallon, 15kmiles yrly, 10 yr
        double priceCar1;
        double priceCar2;
        double mpgCar1;
        double mpgCar2;
        String cpg;
        double costPerGallon;
        double milesPerYear = 15000;
        double years;
        double oldMaint;
        double newMaint;
        int maintYear;
        
        double totalCar1;
        double totalCar2;
        String nameCar1;
        String nameCar2;
        int yearCar1;
        int yearCar2;
        double maintenance1 = 235.00;
        double maintenance2 = 235.00;
        Scanner input = new Scanner(System.in);
        
        String tempString1;
        String tempString2;
        double tempDouble1;
        double tempDouble2;
        char nl = '\n';
        
        priceCar1 = 965;
        priceCar2 = 2643;
        mpgCar1 = 19;
        mpgCar2 = 14;
        nameCar1 = "Yugo Cabrio";
        nameCar2 = "Suzuki Samarai";
        maintenance1 = priceCar1 * 0.04;
        maintenance2 = priceCar2 * 0.04;
        yearCar1 = 1991;
        yearCar2 = 1995;
        
        System.out.println("This program will help you choose a car "
                            + "based on cost over time.");
        System.out.println();
    // Maintenance Year
        System.out.print("Please enter the maintenance deadline year\n"
                + "(cars built after the year you enter will have a lower maintenance cost\n"
                + " than cars built before the maintenance deadline): ");
    // Input Validation for Maintenance Year
        try
        {
            maintYear = input.nextInt();
            while(maintYear < 1900 || maintYear > 2017)
            {
                System.out.println();
                System.out.println("Invalid Input.");
                System.out.print("Please enter the maintenance deadline year\n"
                    + "(cars built after the year you enter will have a lower maintenance cost\n"
                    + " than cars built before the maintenance deadline): ");
                maintYear = input.nextInt();
            }
        }
        catch(InputMismatchException e)
        {
            System.out.println();
            System.out.println("Invalid input");
            System.out.println("Default value of 2007 will be used for the maintenance deadline.");
            maintYear = 2007;
        }
    // Maintenance Percentages
        System.out.println();
        System.out.print("Please enter the maintenance cost percentage for cars built after the maintenance deadline: ");
        newMaint = input.nextDouble();
        System.out.print("Please enter the maintenance cost percentage for cars built before the maintenance deadline: ");
        oldMaint = input.nextDouble();
        while(oldMaint < newMaint)
        {
            System.out.println();
            System.out.println("Invalid Input.");
            System.out.println("Cars built before the maintenance deadline should have a higher percentage than cars built after.");
            System.out.print("Please enter the maintenance cost percentage for cars built before the maintenance deadline: ");
            oldMaint = input.nextDouble();
        }
        newMaint /= 100.0;
        oldMaint /= 100.0;
    // Years to consider for cost
        System.out.println();
        System.out.print("Please enter the amount of years you plan on owning a car: ");
        years = input.nextInt();
        input.nextLine();
    // Cost per Gallon
        System.out.println();
        System.out.print("Please enter the cost of gas per gallon.\nIf you wish to skip this step, press the ENTER key: ");
        cpg = input.nextLine();
        if(cpg.isEmpty())
        {
            costPerGallon = 2.75;
        }
        else
        {
            costPerGallon = Double.parseDouble(cpg);
        }
    // Car 1 Information
        System.out.println();
        System.out.print("Please enter, on one line, the make, model and year"
                          + nl +"of the first comparison car: ");
        tempString1 = input.nextLine();
        nameCar1 = inputCheckCar((tempString1.split(" ").length < 3),
                                  "make and model", tempString1, nameCar1);
        if (tempString1.split(" ").length == 3)
        {
            try
            {
                tempDouble1 = Integer.parseInt(tempString1.split(" ")[2]);
                yearCar1 = (int)inputCheck((tempDouble1 < 1900),
                         "year", -1, yearCar1);
            }
            catch(NumberFormatException nfe)
            {
                yearCar1 = (int)inputCheck(true, "year", -1, yearCar1);
            }
        }
    // Car 2 Information    
        System.out.print("Please enter the make, model, and year of the "
                       + "second comparison car: ");
        tempString2 = input.nextLine();
        nameCar2 = inputCheckCar((tempString2.split(" ").length < 3),
                          "make and model", tempString2, nameCar2);
        if (tempString2.split(" ").length == 3)
        {
            try
            {
                tempDouble2 = Integer.parseInt(tempString2.split(" ")[2]);
                yearCar2 = (int)inputCheck((tempDouble2 < 1900), "year",
                                        tempDouble2, yearCar2);
            }
            catch(NumberFormatException nfe)
            {
                yearCar2 = (int)inputCheck(true, "year", -1, yearCar2);
            }
        }
    // Price and MPG of Car 1    
        System.out.print("Please enter the price and the "
                + "average miles per gallon of the " +nameCar1+": ");
        tempDouble1 = input.nextDouble();
        priceCar1 = inputCheck((tempDouble1 < 0),
                "price", tempDouble1, priceCar1);
        
        tempDouble1 = input.nextDouble();
        mpgCar1 = inputCheck((tempDouble1 < 0),
                "mpg", tempDouble1, mpgCar1);
    // Price and MPG for Car 2    
        System.out.print("Please enter the price and the "
                    + "average miles per gallon of the "+nameCar2+": ");
        tempDouble2 = input.nextDouble();
        priceCar2 = inputCheck((tempDouble2 < 0),
                "price", tempDouble2, priceCar2);
        
        tempDouble2 = input.nextDouble();
        mpgCar2 = inputCheck((tempDouble2 < 0),
                "mpg", tempDouble2, mpgCar2);
    // Maintenance Cost for Car1 and Car2    
        if(yearCar1 >= maintYear)
            maintenance1 = priceCar1 * newMaint;
        else
            maintenance1 = priceCar1 * oldMaint;
        if(yearCar2 >= maintYear)
            maintenance2 = priceCar2 * newMaint;
        else
            maintenance2 = priceCar2 * oldMaint;
        
        // cost for car is init price plus cost per year times 10
        // cost per year is miles per year divided by mpg times cost per gallon
        
        totalCar1 = (milesPerYear / mpgCar1 * costPerGallon
                 + maintenance1) * years + priceCar1;
        totalCar2 = (milesPerYear / mpgCar2 * costPerGallon
                   + maintenance2) * years + priceCar2;
    // Explanation of total cost    
        System.out.println();
        System.out.println("The comparison of car costs is the initial price \n"
                + "plus cost per year over "+(int)years+" years with an average \nof "
                +(int)milesPerYear+" miles per year and a price of "
                +costPerGallon+" per gallon of gas plus a \n"
                + "yearly maintenance cost of %"
                +(newMaint*100)+" of the original car cost \n"
                + "for cars newer than "+maintYear+" and %"
                +(oldMaint*100)+" for older.");
    // Display Results    
        System.out.println();
        System.out.print("Total cost for the "+nameCar1+" is ");
        System.out.printf("%.2f\n", totalCar1);
        
        System.out.print("Total cost of the "+nameCar2+" is ");
        System.out.printf("%.2f\n", totalCar2);
        System.out.println();
        
    }
    
    public static String inputCheckCar(boolean test, String item,
           String tempStr, String defStr)
    {
        String t1, t2;
        if (test)
        {
            System.out.println("This is an invalid "+item+".");
            System.out.println("Default "+item+" of "+defStr+" will be used.");
            return defStr;
        }
        else
        {
            t1 = tempStr.split(" ")[0];
            t2 = tempStr.split(" ")[1];
            return t1+" "+t2;
        }
    }
    
    public static double inputCheck(boolean test, String item, double tempDouble, double defDouble)
    {
        if (test)
        {
            System.out.println("This is an invalid "+item+".");
            System.out.println("Default "+item+" of "+defDouble+" will be used.");
            return defDouble;
        }
        else
        {
            return tempDouble;
        }
    }        
}
