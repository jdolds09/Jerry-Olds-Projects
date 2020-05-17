/*
 * Lab 7 Part 1a
 * CSE-1310-005
 */
package lab7part1a;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Date;
import java.util.Scanner;

/**
 *
 * @author Jerry Olds
 */
public class Lab7Part1a {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
    // Declaring Input File
        Scanner in = new Scanner(System.in);
        File inFile = new File("students1.txt");
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
        Scanner studentData;
        String lastName;
        String firstName;
        long utaID;
        String major;
        String classYear;
        int birthdate;
        double GPA;
        int totalUTAhours;
        double account;
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
                studentData = new Scanner(in.nextLine());
                studentData.useDelimiter(",");
                lastName = studentData.next();
                studentData.useDelimiter("1");
                firstName = studentData.next();
                firstName = firstName.substring(1);
                firstName = firstName.trim();
                studentData.useDelimiter("\\s");
                utaID = studentData.nextLong();
                major = studentData.next();
                classYear = studentData.next();
                birthdate = studentData.nextInt();
                GPA = studentData.nextDouble();
                totalUTAhours = studentData.nextInt();
                account = studentData.nextDouble();
                if(studentData.hasNextLine())
                    studentData.nextLine();
            // Call calcAge Method
                age = calcAge(birthdate);
            // Find birth year, birth month, and birth day.
                month = birthdate / 10000;
                birthdate %= 10000;
                day = birthdate / 100;
                birthdate %= 100;
                year = birthdate;
            // Output Results
                System.out.println(firstName+" "+lastName+", ID number "+utaID+", is a "+major+" major with "+totalUTAhours+" hours an a "+GPA+" GPA.");
                if(month < 10 && day < 10)
                {
                    System.out.print(firstName+" is a "+classYear+", is "+age+" years old with a birthday of 0"+month+"/0"+day+"/"+year+" and has an account balance of $");
                    System.out.printf("%.2f\n", account);
                }
                else if(month < 10)
                {
                    System.out.print(firstName+" is a "+classYear+", is "+age+" years old with a birthday of 0"+month+"/"+day+"/"+year+" and has an account balance of $");
                    System.out.printf("%.2f\n", account);
                }
                else if(day < 10)
                {
                    System.out.print(firstName+" is a "+classYear+", is "+age+" years old with a birthday of "+month+"/0"+day+"/"+year+" and has an account balance of $");
                    System.out.printf("%.2f\n", account);
                }
                else
                {
                    System.out.print(firstName+" is a "+classYear+", is "+age+" years old with a birthday of "+month+"/"+day+"/"+year+" and has an account balance of $");
                    System.out.printf("%.2f\n", account);
                }
                System.out.println();
            }
        }
     in.close();   
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
