/*
 * Lab 7 Part 1c
 * CSE-1310-005
 */
package lab7part1c;

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
public class Lab7Part1c {

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
        Scanner studentData;
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
        int age;
        int year;
        int month;
        int day;
        boolean validInput;
    // If input file is found
        if(fileFound)
        { 
            while(in.hasNext())
            {   
            // Read in data
                validInput = true;
                studentData = new Scanner(in.nextLine());
                studentData.useDelimiter(",");
                lastName = studentData.next();
                if(lastName.isEmpty())
                {
                    studentData.useDelimiter("\\s");
                    studentData.nextLine();
                    validInput = false;
                }
                if(validInput)
                {
                    studentData.useDelimiter("1");
                    firstName = studentData.next();
                    firstName = firstName.substring(1);
                    firstName = firstName.trim();
                    if(firstName.isEmpty())
                    {
                        studentData.nextLine();
                        validInput = false;
                    }
                    if(validInput)
                    {
                        studentData.useDelimiter("\\s");
                        try
                        {
                            utaID = studentData.nextLong();
                        }
                        catch(InputMismatchException ime)
                        {
                            studentData.nextLine();
                            validInput = false;
                        }
                        if(validInput)
                        {
                            major = studentData.next();
                            classYear = studentData.next();
                            try
                            {
                                birthdate = studentData.nextInt();
                            }
                            catch(InputMismatchException ime)
                            {
                                studentData.nextLine();
                                validInput = false;
                            }
                            if(validInput)
                            {
                                try
                                {
                                    GPA = studentData.nextDouble();
                                }
                                catch(InputMismatchException ime)
                                {
                                    studentData.nextLine();
                                    validInput = false;
                                }
                                if(validInput)
                                {
                                    try
                                    {
                                        totalUTAhours = studentData.nextInt();
                                    }
                                    catch(InputMismatchException ime)
                                    {
                                        studentData.nextLine();
                                        validInput = false;
                                    }
                                    if(validInput)
                                    {
                                        try
                                        {
                                            account = studentData.nextDouble();
                                        }
                                        catch(NoSuchElementException e)
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
                // Call calcAge Method
                    age = calcAge(birthdate);
                // Find Birth Day, Month, and Year
                    month = birthdate / 10000;
                    birthdate %= 10000;
                    day = birthdate / 100;
                    birthdate %= 100;
                    year = birthdate;
                // Output Results
                    System.out.println(firstName+" "+lastName+", ID number "+utaID+", is a "+major+" major with "+totalUTAhours+" hours an a "+GPA+" GPA.");
                    System.out.print(firstName+"'s academic standing is "+standing+". ");
                    if(month < 10 && day < 10)
                    {
                        System.out.print(firstName+" is a "+classYearOutput+", is "+age+" years old with a birthday of 0"+month+"/0"+day+"/"+year+" and has an account balance of $");
                        System.out.printf("%.2f\n", account);
                    }
                    else if(month < 10)
                    {
                        System.out.print(firstName+" is a "+classYearOutput+", is "+age+" years old with a birthday of 0"+month+"/"+day+"/"+year+" and has an account balance of $");
                        System.out.printf("%.2f\n", account);
                    }
                    else if(day < 10)
                    {
                        System.out.print(firstName+" is a "+classYearOutput+", is "+age+" years old with a birthday of "+month+"/0"+day+"/"+year+" and has an account balance of $");
                        System.out.printf("%.2f\n", account);
                    }
                    else
                    {
                        System.out.print(firstName+" is a "+classYearOutput+", is "+age+" years old with a birthday of "+month+"/"+day+"/"+year+" and has an account balance of $");
                        System.out.printf("%.2f\n", account);
                    }
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