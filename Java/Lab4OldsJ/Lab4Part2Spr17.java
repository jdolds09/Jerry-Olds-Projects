/*
 * 
 */

package lab4part2spr17;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.util.Scanner;

/**
 *
 * @author jcmtiernan
 */
public class Lab4Part2Spr17 
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        String sign;
        String dayOfWeekName;
        String monthName;
        String dayNumber;
        int year;
        int dayOfMonth;
        int monthNumber;
        String dateFile;

        System.out.println(); 
        System.out.println("This program reads birthdates"
                + "from a file in the form of "
                + "\"Tuesday February 21, 2017\".\n  "
                + "and then determines the zodiac sign of this birthdate.\n\n"
                + "Please enter the name of your input file (with no blanks) :  ");

        dateFile = input.next();
        System.out.println();
        
        boolean fileFound = false;
        File datesFile = new File(dateFile); // connect this File object to the users input
        Scanner inFile = new Scanner(System.in);  // initialize this Scanner
        try
        {   
            inFile = new Scanner(datesFile);
            fileFound = true;
        }
        catch (FileNotFoundException fnf)
        {
            System.out.println("Input file "+dateFile+" not found");
        }
        
        boolean outFound = false;
        String outputFile = "signOutput.txt";
        PrintWriter outFile = new PrintWriter(System.out);
        try
        {
            outFile = new PrintWriter(outputFile);
            outFound = true;
        }
        catch(FileNotFoundException fnf)
        {
            System.out.println("Output File not found.");      
        }
        if (fileFound)
        {
            while (inFile.hasNext())
            {   
                dayOfWeekName = inFile.next();
                monthName  = inFile.next();
                dayNumber = inFile.next();
                
                // What was read in for dayNumber?
                // What does makeNum do?
                dayOfMonth = makeNum(dayNumber);
                year = inFile.nextInt();
                // Use a method to find the month number from the month name                
                monthNumber = findMoNum(monthName);
                // Print the numeric format then                
                System.out.println("You entered "+monthNumber+"/"+dayOfMonth+"/"+year);
                
                // Use a method to find the astrological sign of the birthdate                 
                sign = findSign(monthNumber, dayOfMonth);
                // Return the sign and print that                
                System.out.println("This date's astrological sign is "+sign);
                System.out.println();
                outFile.println("You entered "+monthNumber+"/"+dayOfMonth+"/"+year);
                outFile.println("This date's astrological sign is "+sign);
            }
        }
        outFile.close();
        // if the output file was found, close the file here
    }
    
    public  static int makeNum(String numCm)
    {   int num;
        try
        {
            num = Integer.parseInt(numCm);
        }
        catch (InputMismatchException ime)
        {
            num = 0;
        }
        return num;
    }
    
    public static int findMoNum(String moName)
    {
        int moNum = 0;
        switch(moName)
        {
            case "Jan":
            case "jan":
            case "JAN":
            case "January":
            case "january":
            case "JANUARY":
            moNum = 1;
            break;
            case "Feb":
            case "feb":
            case "FEB":
            case "February":
            case "february":
            case "FEBRUARY":
            moNum = 2;
            break;
            case "Mar":
            case "mar":
            case "MAR":
            case "March":
            case "march":
            case "MARCH":
            moNum = 3;
            break;
            case "Apr":
            case "apr":
            case "APR":
            case "April":
            case "april":
            case "APRIL":
            moNum = 4;
            break;
            case "May":
            case "may":
            case "MAY":
            moNum = 5;
            break;
            case "Jun":
            case "jun":
            case "JUN":
            case "June":
            case "june":
            case "JUNE":
            moNum = 6;
            break;
            case "Jul":
            case "jul":
            case "JUL":
            case "July":
            case "july":
            case "JULY":
            moNum = 7;
            break;
            case "Aug":
            case "aug":
            case "AUG":
            case "August":
            case "august":
            case "AUGUST":
            moNum = 8;
            break;
            case "Sep":
            case "sep":
            case "SEP":
            case "September":
            case "september":
            case "SEPTEMBER":
            moNum = 9;
            break;
            case "Oct":
            case "oct":
            case "OCT":
            case "October":
            case "october":
            case "OCTOBER":
            moNum = 10;
            break;
            case "Nov":
            case "nov":
            case "NOV":
            case "November":
            case "november":
            case "NOVEMBER":
            moNum = 11;
            break;
            case "Dec":
            case "dec":
            case "DEC":
            case "December":
            case "december":
            case "DECEMBER":
            moNum = 12;
            break;
        }
        return moNum;
    }
    
    public static String findSign(int mo, int day)
    {    
        String sign = "Unclear";
        // error checking for valid month and day in month
        mo = moDayCheck(mo,day);        
        
        // Look up the zodiac signs and use them to fill in the switch below
        // One sign is shown below
        switch (mo)
        {
            case 1:
                if(day <= 19)
                    sign = "Capricorn";
                else
                    sign = "Aquarius";
                break;
            case 2:
                if(day <= 18)
                    sign = "Aquarius";
                else
                    sign = "Pisces";
                break;
            case 3:
                if(day <= 20)
                    sign = "Pisces";
                else
                    sign = "Aries";
                break;
            case 4:
                if (day <= 19)
                    sign = "Aries"; 
                else
                    sign = "Taurus";
                break;
            case 5:
                if (day <= 20)
                    sign = "Taurus";
                else 
                    sign = "Gemini";
                break;
            case 6:
                if (day <= 20)
                    sign = "Gemini";
                else 
                    sign = "Cancer";
                break;
            case 7:
                if (day <= 22)
                    sign = "Cancer";
                else
                    sign = "Leo";
                break;
            case 8:
                if (day <= 22)
                    sign = "Leo";
                else 
                    sign = "Virgo";
                break;
            case 9:
                if (day <= 22)
                    sign = "Virgo";
                else
                    sign = "Libra";
                break;
            case 10:
                if (day <= 22)
                    sign = "Libra";
                else
                    sign = "Scorpio";
                break;
            case 11:
                if (day <= 21)
                    sign = "Scorpio";
                else 
                    sign = "Sagittarius";
                break;
            case 12:
                if (day <= 21)
                    sign = "Sagittarius";
                else 
                    sign = "Capricorn";
                break;
            case 0:
                System.out.println("This date is invalid.");                
        }
        return sign;
    }
    // Write method moDayCheck that takes in the month and day
    // as input parameters.  It should check for the validity of 
    // the day and month as given below.  Use the algorithm for 
    // checking date to write the method.
    // If the date is invalid the method should return a value of 0. 
    // Otherwise return the month value that was passed in.

    // Valid dates:
    // 12 months in a year Jan (1) to Dec (12)
    // 31 days Jan., Mar., May, Jul., Aug., Oct., Dec.        
    // 30 days Sept., April, June, Nov.
    // 28 days Feb. (ignoring leap year)


    // Algorithm for checking date
    // if month is NOT a valid number, then
    //    set mo to 0
    // else check if day is invalid for any month.  if so, then
    //    set mo to 0
    // else if mo is Feb and day is too large, then
    //    set mo to 0
    // else if there are more than 30 days and mo is Sep, Apr, Jun, or Nov,
    //    set mo to 0
    // return mo
    public static int moDayCheck(int mo, int day)
    {
        if(mo < 1 || mo > 12)
        {
            return 0;
        }
        if(day < 1 || day > 31)
        {
            return 0;
        }
        if(mo == 4 || mo == 6 || mo == 9 || mo == 11)
        {
            if(day > 30)
            {
                return 0;
            }
        }
        if(mo == 2)
        {
            if(day > 28)
            {
                return 0;
            }
        }
        return mo;
    }
}