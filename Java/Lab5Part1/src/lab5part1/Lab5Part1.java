/*
 * Intro to Programming CSE 1310-005
 * University of Texas at Arlington
 */

package lab5part1;

import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Jerry Olds
 */
public class Lab5Part1 
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        Logger logger = Logger.getLogger(LoggingExamples.class.getName());
        logger.setLevel(Level.OFF);  //INFO is on; OFF is off         
        
        Scanner keybd = new Scanner(System.in);
        JCMTtime myTime = new JCMTtime();  //  This value will have the current time in it
        // Lunar module Eagle landed on the moon on July 20, 1969, at 20:18 UTC.
        JCMTtime landedTime = new JCMTtime();
        landedTime.setYear(1969);
        landedTime.setMonth(6);
        landedTime.setDayOfMonth(20);
        landedTime.setMinute(18);
        landedTime.setHourInMil(20);
        // July 21, 1969 at 02:56:15 UTC First person steps on the moon
        JCMTtime firstStepTime = new JCMTtime(1969, 6, 21, 2, 56);  
        
        // 3.a) instantiate the birthTime value with YOUR birth date and time
        JCMTtime birthTime = new JCMTtime(1996, 3, 23, 13, 0);  
        // If you do not know your birth time, put in noon for the time
        String myName = "Jerry Olds"; // and 3.a) initialize this String to YOUR name.
    // Variable
        String mins;
        
        int inMo = -1;
        int inDay = -1;
        int inYr = -1;
        int inHr = -1;
        int inMin = -1;
       
        System.out.println("Please enter the expiration date and time of your coupon.\n");
        System.out.println("The format should be month (space) day (space) year (space) hour (space) min");
        System.out.println("like MM dd yyyy HH mm.  The coupon year must be between 1970 and 2020. ");
        System.out.println("The hour should be in military time from 0 to 23. Invalid values will be ");
        System.out.println("replaced with the current time values. Example: For a coupon that expires one");
        System.out.println("minute before midnight on Halloween the input would be 10 31 2017 23 59.  \n");
        System.out.print("Enter your coupon expiration date and time here: ");
                
        inMo = keybd.nextInt();
        inDay = keybd.nextInt();
        inYr = keybd.nextInt();
        inHr = keybd.nextInt();
        inMin = keybd.nextInt();
        mins = twoPlaces(inMin);

        System.out.println("\nYour input was "+inMo +"/"+inDay+"/"+inYr+" at "+inHr+":"+mins);
        
        JCMTtime expDate = new JCMTtime(inYr, inMo - 1, inDay, inHr, inMin);  // 3.b) initialize the coupon date with the user's inputs
        
        System.out.println("Your error-checked input is "+expDate.toStringMDYHM());
        
        System.out.println("\nNow we will check if this coupon is still valid and how many\n"
                + "days longer it is valid or that it has been expired. ");
        System.out.println("");
        System.out.println("The current time is "+myTime.toStringMDYHM());  
        
        /* 
            3.d) Call the daysBetween method here using your coupon input in expDate 
            and the current date in myTime
            Print the number of days between that are returned from the method call
        */
        
        double days;
        days = daysBetween(expDate, myTime);
        System.out.println("");
        
        if(days < 0)
            System.out.printf("Your coupon is expired by %.2f day(s).",(days * -1));
        else if(days == 0)
            System.out.println("Your coupon expires RIGHT NOW!");
        else
            System.out.printf("Your coupon expires in %.2f day(s).", days);
            System.out.println("");
    
        System.out.println("");
        System.out.println("Please enter the expiration date and time of your next coupon.\n");
        System.out.println("The format should be month (space) day (space) year (space) hour (space) min");
        System.out.println("like MM dd yyyy HH mm.  If your MM, dd, yyyy, HH, or mm values are out of");
        System.out.println("range, the program will resolve them into valid values and then check the ");
        System.out.print("coupon expiration.  Enter your coupon expiration date and time here: ");
                
        inMo = keybd.nextInt();
        inDay = keybd.nextInt();
        inYr = keybd.nextInt();
        inHr = keybd.nextInt();
        inMin = keybd.nextInt();
        mins = twoPlaces(inMin);

        System.out.println("\nYour input was "+inMo +"/"+inDay+"/"+inYr+" at "+inHr+":"+mins);        
        
        /* 
            3.f) Call the method dateResolution here using the inputs read from the user and assign
            the resulting JCMTtime value to the object expDate.  
        */
        
        expDate = dateResolution(inYr, inMo, inDay, inHr, inMin);  // call dateResolution and assign it to expDate
        
        System.out.println("Your error-checked and resolved input is "+expDate.toStringMDYHM());        
        
        System.out.println("\nNow we will check if this 2nd coupon is still valid and how many\n"
                + "days longer it is valid or that it has been expired. ");
        System.out.println("");
        System.out.println("The current time is "+myTime.toStringMDYHM()); 
       
        /* 
            3.g) Call the daysBetween method here using your coupon input in expDate 
            and the current date in myTime
            Print the number of days between that are returned from the method call
        */
           
        days = daysBetween(expDate, myTime);
        System.out.println("");
        
        if(days < 0)
            System.out.printf("Your coupon is expired by %.2f, day(s).",(days * -1));
        else if(days == 0)
            System.out.println("Your coupon expires RIGHT NOW!");
        else
            System.out.printf("Your coupon expires in %.2f day(s).", days);
            System.out.println("");
        // after calling daysBetween and printing its output then print:
        
        System.out.println("");
        System.out.println("The Eagle lunar module landed on the moon at "+landedTime.toStringMDYHM());
        System.out.println("The first person, Neil Armstrong, stepped on the moon at "+firstStepTime.toStringMDYHM());
        System.out.println("The birth date and time of "+myName+" is "+
                birthTime.getMonthName() +" "+birthTime.getDayOfMonth()+", "+
                birthTime.getYear()+" at "+birthTime.getHourInMil()+":"+
                twoPlaces(birthTime.getMinute()));
            
    }
    // 3.d) Write the method daysBetween here
    public static double daysBetween(JCMTtime expDate, JCMTtime myTime)
    {
        // Variables
        double days;
        double expDays;
        double currentDays;
        int expFullMonthDays = 0;
        int currentFullMonthDays = 0;
        int expYear = expDate.getYear();
        int expMonth = expDate.getMonth() + 1;
        int expDay = expDate.getDayOfMonth();
        double expHour = expDate.getHourInMil();
        double expMinute = expDate.getMinute();
        int currentYear = myTime.getYear();
        int currentMonth = myTime.getMonth() + 1;
        int currentDay = myTime.getDayOfMonth();
        double currentHour = myTime.getHourInMil();
        double currentMinute = myTime.getMinute();
        int expLeapDays = expYear / 4;
        int currentLeapDays = currentYear / 4;
        double expMinutes = (expHour * 60) + expMinute;
        double currentMinutes = (currentHour * 60) + currentMinute;
        double expAmountOfDay = expMinutes / 1440.0;
        double currentAmountOfDay = currentMinutes / 1440.0;
        // Find Exp Full Month Days
        if(expMonth != 1)
        {
            switch(expMonth)
            {
                case 2:
                    expFullMonthDays = 31;
                    break;
                case 3:
                    if(expYear % 4 == 0)
                        expFullMonthDays = 60;
                    else
                        expFullMonthDays = 59;
                    break;
                case 4:
                    if(expYear % 4 == 0)
                        expFullMonthDays = 91;
                    else
                        expFullMonthDays = 90;
                    break;
                case 5:
                    if(expYear % 4 == 0)
                        expFullMonthDays = 121;
                    else
                        expFullMonthDays = 120;
                    break;
                case 6:
                    if(expYear % 4 == 0)
                        expFullMonthDays = 152;
                    else
                        expFullMonthDays = 151;
                    break;
                case 7:
                    if(expYear % 4 == 0)
                        expFullMonthDays = 182;
                    else
                        expFullMonthDays = 181;
                    break;
                case 8:
                    if(expYear % 4 == 0)
                        expFullMonthDays = 213;
                    else
                        expFullMonthDays = 212;
                    break;
                case 9:
                    if(expYear % 4 == 0)
                        expFullMonthDays = 244;
                    else
                        expFullMonthDays = 243;
                    break;
                case 10:
                    if(expYear % 4 == 0)
                        expFullMonthDays = 274;
                    else
                        expFullMonthDays = 273;
                    break;
                case 11:
                    if(expYear % 4 == 0)
                        expFullMonthDays = 305;
                    else
                        expFullMonthDays = 304;
                    break;
                case 12:
                    if(expYear % 4 == 0)
                        expFullMonthDays = 335;
                    else
                        expFullMonthDays = 334;
                    break;
                default: 
                    expFullMonthDays = -999999;
            }
        }
    // Find Current Full Month Days
        if(currentMonth != 1)
        {
            switch(currentMonth)
            {
                case 2:
                    currentFullMonthDays = 31;
                    break;
                case 3:
                    if(expYear % 4 == 0)
                        currentFullMonthDays = 60;
                    else
                        currentFullMonthDays = 59;
                    break;
                case 4:
                    if(expYear % 4 == 0)
                        currentFullMonthDays = 91;
                    else
                        currentFullMonthDays = 90;
                    break;
                case 5:
                    if(expYear % 4 == 0)
                        currentFullMonthDays = 121;
                    else
                        currentFullMonthDays = 120;
                    break;
                case 6:
                    if(expYear % 4 == 0)
                        currentFullMonthDays = 152;
                    else
                        currentFullMonthDays = 151;
                    break;
                case 7:
                    if(expYear % 4 == 0)
                        currentFullMonthDays = 182;
                    else
                        currentFullMonthDays = 181;
                    break;
                case 8:
                    if(expYear % 4 == 0)
                        currentFullMonthDays = 213;
                    else
                        currentFullMonthDays = 212;
                    break;
                case 9:
                    if(expYear % 4 == 0)
                        currentFullMonthDays = 244;
                    else
                        currentFullMonthDays = 243;
                    break;
                case 10:
                    if(expYear % 4 == 0)
                        currentFullMonthDays = 274;
                    else
                        currentFullMonthDays = 273;
                    break;
                case 11:
                    if(expYear % 4 == 0)
                        currentFullMonthDays = 305;
                    else
                        currentFullMonthDays = 304;
                    break;
                case 12:
                    if(expYear % 4 == 0)
                        currentFullMonthDays = 335;
                    else
                        currentFullMonthDays = 334;
                    break;
                default: 
                    currentFullMonthDays = -999999;
            }
        }
    // Total Exp Days
        expDays = ((expYear * 365) + expLeapDays) + expFullMonthDays + expDay + expAmountOfDay;
    // Total Current Days
        currentDays = ((currentYear * 365) + currentLeapDays) + currentFullMonthDays + currentDay + currentAmountOfDay;
    // Days Between
        days = expDays - currentDays;
        return days;
    }
    
    // 3.f) Write the method dateResolution here
    static public JCMTtime dateResolution(int year, int month, int day, int hour, int minute)
    {
    // Variables
        boolean notFound = true;
        int days = 0;
    // Date Resolution Algorithm
        if(minute > 59)
        {
            hour += minute / 60;
            minute %= 60;
        }
        if(minute < 0)
        {
            if(minute >= -60)
            {
                hour -= 1;
                minute %= -60;
            }    
            else
                hour -= minute / -60;
                minute %= -60;
        }
        if(hour > 23)
        {
            day += hour / 24;
            hour %= 24;
        }
        if(hour < 0)
        {
            if(hour >= -24)
            {
                day -= 1;
                hour %= -24;
            }
            else
                day -= hour / -24;
                hour %= - 24;
        }
        if(day < 1)
            day = 1;
        while(notFound)
        {
            if(month == 2 && year % 4 == 0)
                days = 29;
            else if(month == 2 && year % 4 != 0)
                days = 28;
            else if(month == 4 || month == 6 || month == 9 || month == 11)
                days = 30;
            else
                days = 31;
            if(day <= days)
                notFound = false;
            else
            {
                day -= days;
                if(month == 12)
                {
                  month = 1;
                  year++;
                }
                else
                    month++;
            }
        }
        if(month < 0)
        {
            if(month >= -12)
            {
                year -= 1;
                month %= -12;
            }
            else
                year -= month / -12;
                month %= -12;
        }
        if(month > 12)
        {
            year += month / 12;
            month %= 12;
        }
        if(year < 1970)
            year = 1970;
        if(year > 2020)
            year = 2020;
        JCMTtime validation = new JCMTtime(year, month - 1, day, hour, minute);
        return validation;
    }
    
    /**
     * Write a method that prints the minutes properly when the value is 
     * less than 10.  
     * This means that your method will take in HH and mm of 3 and 4 
     * and output 3:04 NOT 3:4.  
     *
     */
    static public String twoPlaces(int min)
    {
        String mins = "";
        if (min < 10)
            mins = "0"+min;
        else
            mins = ""+min;
        // 3.h) make the correct string here to print the minutes
        return mins;
    }

}