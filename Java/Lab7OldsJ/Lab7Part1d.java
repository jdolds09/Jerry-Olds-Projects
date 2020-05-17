/*
 * Lab 7 Part 1d
 * CSE-1310-005
 */
package lab7part1d;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Date;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.util.Scanner;

/**
 *
 * @author Jerry Olds
 */
public class Lab7Part1d {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
    // Declaring Input File
        Scanner in = new Scanner(System.in);
        File inFile = new File("students2.txt");
        boolean fileFound = true;
        try
        {
            in = new Scanner(inFile);
        }
        catch(FileNotFoundException fnf)
        {
            System.out.println("Input file not found.");
            fileFound = false;
        }
    // Variables
        Date date = new Date();
        String studentData;
        String [] stringArray;
        String lastName = "";
        String firstName = "";
        long utaID = 0;
        String major = "";
        String classYear = "";
        int birthdate = 0;
        double GPA = 0;
        int totalUTAhours = 0;
        double account = 0;
        String standing;
        String classYearOutput;
        boolean invalidHours;
        boolean invalidTuition;
        boolean hasOutstandingCharges;
        boolean validInput;
        int age;
        int year;
        int month;
        int day;
    // If input file is found
        if(fileFound)
        { 
            while(in.hasNext())
            {   
            // Read in data
                validInput = true;
                studentData = in.nextLine();
                stringArray = studentData.split(",");
                lastName = stringArray[0];
                if(lastName.isEmpty())
                {
                    validInput = false;
                }
                if(validInput)
                {
                    studentData = studentData.replaceFirst(lastName, "");
                    stringArray = studentData.split("1");
                    firstName = stringArray[0];
                    try
                    {
                        firstName = firstName.substring(1);
                    }
                    catch(StringIndexOutOfBoundsException e)
                    {
                        validInput = false;
                    }
                    firstName = firstName.trim();
                    if(firstName.isEmpty())
                    {
                        validInput = false;
                    }
                    if(validInput)
                    {
                        studentData = studentData.replaceFirst(firstName, "");
                        studentData = studentData.substring(1);
                        studentData = studentData.trim();
                        stringArray = studentData.split("\\s");
                        try
                        {
                            utaID = Long.parseLong(stringArray[0]);
                        }
                        catch(InputMismatchException ime)
                        {
                            validInput = false;
                        }
                        if(validInput)
                        {
                            major = stringArray[1];
                            classYear = stringArray[2];
                            try
                            {
                                birthdate = Integer.parseInt(stringArray[3]);
                            }
                            catch(NumberFormatException nfe)
                            {
                                validInput = false;
                            }
                            if(birthdate < 10000)
                            {
                                validInput = false;
                            }
                            if(validInput)
                            {
                                try
                                {
                                    GPA = Double.parseDouble(stringArray[4]);
                                }
                                catch(InputMismatchException ime)
                                {
                                    validInput = false;
                                }
                                if(GPA < 0 || GPA > 4)
                                {
                                    validInput = false;
                                }
                                if(validInput)
                                {
                                    try
                                    {
                                        totalUTAhours = Integer.parseInt(stringArray[5]);
                                    }
                                    catch(InputMismatchException ime)
                                    {
                                        validInput = false;
                                    }
                                    if(totalUTAhours == 0)
                                        validInput = false;
                                    if(validInput)
                                    {
                                        try
                                        {
                                            account = Double.parseDouble(stringArray[6]);
                                        }
                                        catch(ArrayIndexOutOfBoundsException e)
                                        {
                                            validInput = false;
                                        }
                                       
                                    }
                                }
                            }
                        }
                    }
                    
                }
                if(validInput)
                {
                    // Call calcStanding Method
                        standing = calcStanding(GPA, totalUTAhours);
                    // Call calcClassYear Method
                        classYearOutput = calcClassYear(classYear);
                    // Call classYearVerification Method
                        invalidHours = classYearVerification(classYear, totalUTAhours);
                    // Call tuition Method
                        invalidTuition = tuition(classYear, totalUTAhours);
                    // Call charges Method
                        hasOutstandingCharges = charges(account);
                    // Call calcAge Method
                        age = calcAge(birthdate);
                    // Find Birth Day, Month, and Year
                        month = birthdate / 10000;
                        birthdate %= 10000;
                        day = birthdate / 100;
                        birthdate %= 100;
                        year = birthdate;
                    // Display First Name, Last Name, ID number, Major, Age, and Birthdate
                    if(month < 10 && day < 10)
                        System.out.println(firstName+" "+lastName+", ID number "+utaID+", is a "+major+" major, and is "+age+" years old with a birthday of 0"+month+"/0"+day+"/"+year+".");
                    else if(month < 10)
                        System.out.println(firstName+" "+lastName+", ID number "+utaID+", is a "+major+" major, and is "+age+" years old with a birthday of 0"+month+"/"+day+"/"+year+".");
                    else if(day < 10)
                        System.out.println(firstName+" "+lastName+", ID number "+utaID+", is a "+major+" major, and is "+age+" years old with a birthday of "+month+"/0"+day+"/"+year+".");
                    else
                        System.out.println(firstName+" "+lastName+", ID number "+utaID+", is a "+major+" major, and is "+age+" years old with a birthday of "+month+"/"+day+"/"+year+".");
                    // Display Academic Standing
                    System.out.println(firstName+"'s academic standing is "+standing+" with a "+GPA+" GPA.");
                    // Display Class Year and Total Hours
                    if(invalidHours)
                        System.out.println(firstName+" is a "+classYearOutput+" with "+totalUTAhours+" hours. ERROR: Student is not within "+classYearOutput+" credit hour parameters!");
                    else
                        System.out.println(firstName+" is a "+classYearOutput+" with "+totalUTAhours+" hours."); 
                    if(invalidTuition)
                        System.out.println("NOTICE: Student exceeds 150 credit hours and is subject to non-resident tuition.");
                    // Display Student Account
                    if(hasOutstandingCharges)
                        System.out.printf(firstName+" has an account balance of $%.2f and owes $%.2f.\n", account, (account * -1));
                    else
                        System.out.printf(firstName+" has an account balance of $%.2f and has no outstanding charges at this time.\n", account); 
                    System.out.println();
                }
            }
        }
     in.close();   
    }
    public static String calcClassYear(String classYear)
    {
        switch(classYear)
        {
            case "FR":
                return "freshman";
            case "SO":
                return "sophomore";
            case "JR":
                return "junior";
            case "SR":
                return "senior";
            case "5TH":
                return "second baccalaureate";
            case "MS":
                return "master's student";
            case "PHD":
                return "doctoral student";
            case "SPEC":
                return "special student";
            default:
                return "If this case is used I goofed somewhere.";
        }
    }
    
    public static boolean classYearVerification(String year, int hours)
    {
        if(year.equalsIgnoreCase("FR") && (hours > 30))
            return true;
        else if(year.equalsIgnoreCase("SO") && (hours < 31 || hours > 60))
            return true;
        else if(year.equalsIgnoreCase("JR") && (hours < 61 || hours > 90))
            return true;
        else if(year.equalsIgnoreCase("SR") && (hours < 90))
            return true;
        else
            return false;
    }
    
    public static boolean tuition(String year, int hours)
    {
        if(year.equalsIgnoreCase("SR") && hours > 150 || year.equalsIgnoreCase("5TH") && hours > 150)
            return true;
        else
            return false;
    }
    
    public static boolean charges(double account)
    {
        if(account < 0)
            return true;
        else
            return false;
    }
    
    public static String calcStanding(double GPA, int hours)
    {
        if(GPA < 2.0 && hours < 30)
            return "On Probation";
        else if(GPA < 2.0 && hours >= 30)
            return "On Dismissal";
        else if(GPA < 2.25 && hours >= 30)
            return "On Probation";
        else
            return "Good";
    }
    
    public static int calcAge(int birthdate)
    {
    // Variables
        Date date = new Date();
        int currentYear = date.getYear();
        int currentMonth = date.getMonth();
        currentMonth += 1;
        int currentDay = date.getDate();
        int age;
        int birthMonth = birthdate / 10000;
        birthdate %= 10000;
        int birthDay = birthdate / 100;
        birthdate %= 100;
        int birthYear = birthdate;
    // Calculate age
        if(birthMonth > currentMonth)
            age = currentYear - (birthYear + 1);
        else if(birthMonth == currentMonth)
        {
            if(birthDay < currentDay || birthDay == currentDay)
                age = currentYear - birthYear;
            else
                age = currentYear - (birthYear + 1);
        }
        else 
            age = currentYear - birthYear;
    // Return age
        return age;
    }
}