/*
 *   Intro to Programming CSE 1310
 * University of Texas at Arlington
 */

package lab5part1;

import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author jcmtiernan
 */
public class JCMTtime 
{
    private int year;
    private int month; // 0 - 11
    private String monthName;
    private int dayOfMonth;
    private int hourInMil;
    private int minute;
    private String ExpDate;
    private GregorianCalendar calNow = new GregorianCalendar(); // for current time
    
    private static final Logger LOG = Logger.getLogger(LoggingExamples.class.getName());
    private SimpleDateFormat sdf = new SimpleDateFormat("MM/dd/yyyy hh:mm"); 

    /**
     * Constructor that takes in values and does error checking.
     * If field values are not valid, they are replaced with the current value
     * for that field from the GregorianCalendar
     * @param year  // 1970 to 2020
     * @param month  // Jan (0) to Dec (11)
     * @param dayOfMonth
     * @param hourInMil  // military time 0 - 23 hours
     * @param minute 
     */
    public JCMTtime(int year, int month, int dayOfMonth, int hourInMil, int minute)
    {
        this.LOG.info("Constructor with inputs");
        setYear(year);
        setMonth(month);  // sets month name too
        setDayOfMonth(dayOfMonth);
        setHourInMil(hourInMil);
        setMinute(minute);
        this.LOG.setLevel(Level.OFF);  //INFO is on; OFF is off  
        this.LOG.info("CalNow : " + sdf.format(calNow.getTime()));
        this.LOG.info("CalNow : "+ calNow);
    }

    /**
     * Default constructor for a JCMTtime object that gets the current time
     * as input.
     */
    public JCMTtime()
    {
        this.LOG.info("Constructor no inputs");
        this.year = calNow.get(Calendar.YEAR);
        this.month = calNow.get(Calendar.MONTH);
        this.monthName = numMonthName(this.month);
        this.dayOfMonth = calNow.get(Calendar.DAY_OF_MONTH);
        this.hourInMil = calNow.get(Calendar.HOUR_OF_DAY);
        this.minute = calNow.get(Calendar.MINUTE);
        this.LOG.setLevel(Level.OFF);  //INFO is on; OFF is off 
        this.LOG.info("CalNow : " + sdf.format(calNow.getTime()));
        this.LOG.info("CalNow : "+ calNow);
    }
    
    // -- year methods
    public int getYear()
    {
        return year;
    }

    public void setYear(int year)
    {
        this.LOG.info("In setYear, input year is "+year+" and calNow.YEAR is "+calNow.YEAR);
        if (checkYear(year))
        {
            this.year = year;
        }
        else 
        {
            this.year = calNow.get(Calendar.YEAR);
        }
        this.LOG.info("In setYear, output year is "+this.year);
    }    

    /**
     * Verifies range of user input year value.
     * @param year must be between 1970 and 2020 inclusive
     * @return true if year is valid
     */
    public boolean checkYear(int year)
    {
        if ((year >= 1969) && (year <= 2020))  // valid years are 1970 to 2020
        {
            return true;
        }
        else 
        {
            this.LOG.info("In checkYear, input year is outside the valid range of 1970 to 2020");
            return false;
        }
    }    
    
    // -- month methods
    public int getMonth()
    {
        return month;
    }

    public void setMonth(int month)
    {
        this.LOG.info("In setMonth, input month is "+month+" and calNow.MONTH is "+calNow.MONTH);
        if (checkMonth(month))
        {
            this.month = month;  // month is recorded as 0 to 11
        }
        else 
        {
            this.month = calNow.get(Calendar.MONTH);
        }
        this.monthName = numMonthName(this.month);
        this.LOG.info("In setMonth, output month is "+this.month+" and month name is "+this.monthName);
    }
    /**
     * Verifies range of user input month value.
     * @param month must be in the range of 0 (Jan) to 11 (Dec)
     * @return true if month is valid
     */
    public boolean checkMonth(int month)
    {
        if ((month >= 0) && (month <= 11))
        {
            return true;
        }
        else 
        {
            this.LOG.info("In checkMonth, input month is outside the valid range of 0 - 11");
            return false;
        }
    } 
    public String getMonthName()
    {
        return monthName;
    }

    public void setMonthName(int month)
    {
        this.monthName = numMonthName(month);  // method returns month name
    }

    // -- day of month methods
    public int getDayOfMonth()
    {
        return dayOfMonth;
    }

    public void setDayOfMonth(int dayOfMonth)
    {
        this.LOG.info("*** BEGIN In setDayOfMonth, input day of month is "+dayOfMonth
                +" and calNow.DAY_OF_MONTH is "+ calNow.get(Calendar.DAY_OF_MONTH) );        
        if (checkDayOfMonth(dayOfMonth, this.month, this.year))
        {
            this.dayOfMonth = dayOfMonth;  // error checks for all days
        }
        else 
        {
            this.dayOfMonth = calNow.get(Calendar.DAY_OF_MONTH) ;
        }   
        this.LOG.info("*** END In setDayOfMonth, output day of month is "+this.dayOfMonth);
    }
    
    // -- hour in military time methods
    public int getHourInMil()
    {
        return hourInMil;
    }

    public void setHourInMil(int hourInMil)
    {
        this.LOG.info("In setHourInMil, input hour in military time is "+hourInMil
                +" and calNow.HOUR_OF_DAY is "+calNow.get(Calendar.HOUR_OF_DAY));
        if (checkHourInMil(hourInMil))
        {
            this.hourInMil = hourInMil;  // in range 00 to 23
        }
        else 
        {
            this.hourInMil = calNow.get(Calendar.HOUR_OF_DAY);
        }  
        this.LOG.info("In setHourInMil, output hour in military time is "+this.hourInMil);        
    }
    
    /**
     * Verifies range of user input hour value.
     * @param hourInMil must be in the range of 0 to 23 
     * @return true if hour value is valid
     */
    public boolean checkHourInMil(int hourInMil)
    {
        if ((hourInMil >= 0) && (hourInMil <= 23))
        {
            return true;
        }
        else 
        {
            this.LOG.info("In checkHourInMil, input hour is outside the valid range of 0 - 23");
            return false;
        }
    } 

    // -- minute methods
    public int getMinute()
    {
        return minute;
    }

    public void setMinute(int minute)
    {
        this.LOG.info("In setMinute, input minute is "+minute+" and calNow.MINUTE is "+calNow.MINUTE);
        if (checkMinute(minute))
        {
            this.minute = minute;  // in range 00 to 59
        }
        else 
        {
            this.minute = calNow.get(Calendar.MINUTE);
        }  
        this.LOG.info("In setMinute, output minute is "+this.minute);        
    }
    
    /**
     * Verifies range of user input minute value.
     * @param minute must be in the range of 0 to 59 
     * @return true if minute value is valid
     */
    public boolean checkMinute(int minute)
    {
        if ((minute >= 0) && (minute <= 59))
        {
            return true;
        }
        else 
        {
            this.LOG.info("In checkMinute, input minute is outside the valid range of 0 - 59");
            return false;
        }
    } 
    
    // -- helper methods
    /**
     * Method finds the name of the given month number
     * @param month - input number of month as 0 to 11
     * @return a String with the full name of the month
     */
    private String numMonthName(int month)
    {
        // Month numbers need to be 0 (Jan) - 11 (Dec)
     switch (month)      
     { 
         case 0: return "January";
         case 1: return "February";
         case 2: return "March";
         case 3: return "April";
         case 4: return "May";
         case 5: return "June";
         case 6: return "July";
         case 7: return "August";
         case 8: return "September";
         case 9: return "October";
         case 10: return "November";
         case 11: return "December";
         default: return "Invalid month";
     }
         
    }
      /**
     * Verify if input day number is valid for given month.
     * 
     * Assumes that a valid month is entered in range 0 - 11
     * converts input month to moNum = month + 1 to change range
     * 12 months in a year Jan (1) to Dec (12)
     * 31 days Jan., Mar., May, Jul., Aug., Oct., Dec.
     * 30 days Sept., April, June, Nov.
     * 28 or 29 days Feb.
     * if the date is invalid return a false
     * 
     * Algorithm for checking date:
     *  If day is not too small, i.e greater than 0, then
     *      if the month is Sep, Apr, Jun, or Nov, then
     *          if there are more than 30 days, then
     *              the day is invalid (set the valid flag to false)
     *      else if the month is Feb, then
     *          call a method to check the day and set valid to true or false 
     *      else all remaining months have 31 days so if day is more than 31, then
     *          the day is invalid 
     *  else the day was 0 or below so
     *      the day is invalid 
     * 
     * @param day day of month to verify
     * @param month month value as 0 to 11 (note range change to 1 - 12)
     * @param year needed to check values in Feb for validity
     * @return boolean value is true if day is valid
     */
    public boolean checkDayOfMonth(int day, int month, int year)
    {
        // Assumes that a valid month is entered in range 0 - 11
        // converts input month to moNum = month + 1 to change range
        // 12 months in a year Jan (1) to Dec (12)

        int moNum = month+1;
        boolean valid = true;
        if (day > 0)
        {   //  mo is Sep, Apr, Jun, or Nov
            if (((moNum == 4) || (moNum == 6)) || 
                ((moNum == 9) || (moNum == 11)))
            {
                if (day > 30)
                {
                    valid = false;
                    //System.out.println("Your day value is greater than 30 for the month of "+moNum);
                }
            }
            else if (moNum == 2)  //  month is Feb
            {
                valid = checkFebDays(day, year);   // method checks with leap year  
            }
            else if (day > 31) // month is valid so must be a 31-day month
            {
                valid = false;
                //System.out.println("Your day value is greater than 31 for the month of "+moNum);            
            }
        }
        else  // day was 0 or below
        {
            valid = false;
            //System.out.println("Your day value is less than 0");
        }
        return valid;
    }
    
    /**
     * Validate a day in February for the given year.
     * 
     * Method checks to see if year is a leap year and then 
     * validates the day based on leap year (29 days) or common 
     * year (28 days)
     * 
     * @param day a possible day in the month of Feb to check
     * @param year the associated year to check for leap year
     * @return true if the day is valid for Feb in that year
     */
    private boolean checkFebDays(int day, int year)
    {
        /*  Use the algorithm below to determine if the year is a common year 
        or a leap year and use boolean value to record.

        Leap year algorithm:
        if (year is not exactly divisible by 4) then (it is a common year)
        else if (year is not exactly divisible by 100) then (it is a leap year)
        else if (year is not exactly divisible by 400) then (it is a common year)
        else (it is a leap year)

        * Use the boolean value leap to record if the year is a leap year or not	
        */ 
        // day is already checked to be greater than 0

        boolean valid = true;
        boolean leap = false;

        if ((year % 4) == 0)
        {
            if ((year % 100 ) != 0) // leap year b/c yr is div by 4 but not by 100
            {
               leap = true;
            }
            else if ((year % 400) == 0) // leap year b/c yr is div by 400
            { 
                leap = true;
            }
        }
        // check day value based on leap year or common year
        if (!leap && (day > 28)) // not a leap year so 28 is max
        {
            valid = false;
            //System.out.println("Your Feb. day value is greater than 28 for the year "+year);
        } 
        else if (leap && (day > 29))  // is a leap year so 29 is max
        {
            valid = false;
            //System.out.println("Your Feb. day value is greater than 29 for the year "+year);
        }   
        return valid;
    }
    
    // -- output methods
    @Override
    /**
     * Outputs JCMTtime value in "MM/DD/YYYY at hh:mm" format
     */
    public String toString()
    {      
        return (getMonth()+1)+"/"+getDayOfMonth()+"/"+
                getYear()+" at "+getHourInMil()+":"+getMinute();        
    }
    
    /** 
     * Outputs JCMTtime value in MM/DD/YYYY format
     * @return String of MM/DD/YYYY
     */
    public String toStringMDY()
    {      
        return (getMonth()+1)+"/"+getDayOfMonth()+"/"+getYear();        
    }    
    
    /**
     * Outputs JCMTtime value in MMMMMM DD, YYYY at HH:mm am/pm format
     * @return String of MMMMMM DD, YYYY at HH:mmxm
     */
    public String toStringMDYHM()
    {
        int hr = getHourInMil();
        String ap = "pm";
        
        if ((hr > 0) && (hr <= 11))
        {
            ap = "am";
        }
        else if (hr == 0)
        {
            hr = 12;
            ap = "am";
        } 
        else if (hr > 12)
        {
            hr = hr - 12;
        }
      
        if(getMinute() < 10)
        return getMonthName() +" "+getDayOfMonth()+", "+
                getYear()+" at "+hr+":0"+getMinute()+ap; 
        else
        return getMonthName() +" "+getDayOfMonth()+", "+
                getYear()+" at "+hr+":"+getMinute()+ap;    
    }    

}