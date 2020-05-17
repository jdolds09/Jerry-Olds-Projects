/*
 * Lab 7 Part 1f
 * CSE-1310-005
 */
package lab7part1f;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
import java.util.Scanner;

/**
 *
 * @author Jerry Olds
 */
public class Lab7Part1f {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
    // Declaring input file
        File inFile = new File("students2.txt");
        Scanner in = new Scanner(System.in);
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
    // Declaring output file
        File outFile = new File("studentsOut.txt");
        PrintWriter writer = new PrintWriter(System.out);
        try
        {
            writer = new PrintWriter(outFile);
        }
        catch(IOException e)
        {
            System.out.println("Output File not found.");
        }
    // Variables
        int rSize = 1000;
        int cSize = 9;
        int r = -1;
        int c;
        int testInt;
        int stringLength;
        double testDouble;
        long testLong;
        int day, month, year, birthdate;
        double highestGPA;
        boolean validData;
    // Array
        String studentData [][] = new String [rSize][cSize];
    // If Input File is Found
        if(fileFound)
        {
            while(in.hasNext())
            {
            // Read in Data
                try
                {
                    validData = true;
                    r += 1;
                    c = 0;
                    in.useDelimiter(",");
                    studentData[r][c] = in.next();
                    studentData[r][c] = studentData[r][c].trim();
                    if(studentData[r][c].isEmpty())
                    {
                        r -= 1;
                        validData = false;
                    }
                    stringLength = studentData[r][c].length();
                    if(stringLength > 25)
                    {
                        r -= 1;
                        validData = false;
                    }
                    if(validData)
                    {
                        c += 1;
                        in.useDelimiter("1");
                        studentData[r][c] = in.next();
                        studentData[r][c] = studentData[r][c].substring(1);
                        studentData[r][c] = studentData[r][c].trim();
                        if(studentData[r][c].isEmpty())
                        {
                            r -= 1;
                            validData = false;
                        }
                        if(validData)
                        {
                            c += 1;
                            in.useDelimiter("\\s");
                            studentData[r][c] = in.next();
                            if(Long.parseLong(studentData[r][c]) < 1000000000)
                            {
                                r -= 1;
                                validData = false;
                            }
                            if(validData)
                            {
                                c+= 1;
                                studentData[r][c] = in.next();
                                c+= 1;
                                studentData[r][c] = in.next();
                                c+= 1;
                                studentData[r][c] = in.next();
                                try
                                {
                                    testInt = Integer.parseInt(studentData[r][c]);
                                }
                                catch(NumberFormatException nfe)
                                {
                                    r -= 1;
                                    validData = false;
                                }
                                if(Integer.parseInt(studentData[r][c]) < 10000)
                                {
                                    r -= 1;
                                    validData = false;
                                }
                                if(validData)
                                {
                                    c += 1;
                                    studentData[r][c] = in.next();
                                    if(Double.parseDouble(studentData[r][c]) < 0 || Double.parseDouble(studentData[r][c]) > 4)
                                    {
                                        r -= 1;
                                        validData = false;
                                    }
                                    if(validData)
                                    {
                                        c += 1;
                                        studentData[r][c] = in.next();
                                        if(Integer.parseInt(studentData[r][c]) == 0)
                                        {
                                            r -= 1;
                                            validData = false;
                                        }
                                        if(validData)
                                        {
                                            c += 1;
                                            try
                                            {
                                                studentData[r][c] = in.next();
                                            }
                                            catch(NoSuchElementException nse)
                                            {
                                                r -= 1;
                                                in.nextLine();
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    
                    }
                in.nextLine();
                }    
                    catch(NoSuchElementException nse)
                    {
                        rSize = r + 1;
                    }
                    
                }
            
        // Find Highest GPA
            highestGPA = calcHighestGPA(studentData, rSize);
            System.out.println("Student(s) with highest GPA(s)");
            writer.println("Student(s) with highest GPA(s)");
            System.out.println();
            writer.println();
            for(r = 0; r < rSize; r++)
            {
                if(Double.parseDouble(studentData[r][6]) == highestGPA)
                {
                    System.out.printf("%s %s %s major %.1f GPA\n", studentData[r][1], studentData[r][0], studentData[r][3], Double.parseDouble(studentData[r][6]));
                    writer.println(studentData[r][1]+" "+studentData[r][0]+" "+studentData[r][3]+" major "+Double.parseDouble(studentData[r][6])+" GPA");
                }
            }
            System.out.println();
            writer.println();
        // Unsorted Output for Major
            System.out.println("Unsorted: ");
            writer.println("Unsorted: ");
            System.out.println();
            writer.println();
            for(r = 0; r < rSize; r++)
            {
                System.out.println(studentData[r][0]+", "+studentData[r][1]+" "+studentData[r][3]+" major.");
                writer.println(studentData[r][0]+", "+studentData[r][1]+" "+studentData[r][3]+" major.");
            }
            System.out.println();
            writer.println();
        // Call Sorted Last Name Output
            sortedLastNameOutput(studentData, rSize, writer);
        // Unsorted Output for Birthday
            System.out.println("Unsorted: ");
            writer.println("Unsorted: ");
            System.out.println();
            writer.println();
            for(r = 0; r < rSize; r++)
            {
               birthdate = Integer.parseInt(studentData[r][5]);
               month = birthdate / 10000;
               birthdate %= 10000;
               day = birthdate / 100;
               birthdate %= 100;
               year = birthdate;
               if(month < 10 && day < 10)
               {
                System.out.println(studentData[r][0]+", "+studentData[r][1]+" 0"+month+"/0"+day+"/"+year);
                writer.println(studentData[r][0]+", "+studentData[r][1]+" 0"+month+"/0"+day+"/"+year);
               }
               else if(month < 10)
               {
                   System.out.println(studentData[r][0]+", "+studentData[r][1]+" 0"+month+"/"+day+"/"+year);
                   writer.println(studentData[r][0]+", "+studentData[r][1]+" 0"+month+"/"+day+"/"+year);
               }
               else if(day < 10)
               {
                   System.out.println(studentData[r][0]+", "+studentData[r][1]+" "+month+"/0"+day+"/"+year);
                   writer.println(studentData[r][0]+", "+studentData[r][1]+" "+month+"/0"+day+"/"+year);
               }
               else
               {
                   System.out.println(studentData[r][0]+", "+studentData[r][1]+" "+month+"/"+day+"/"+year);
                   writer.println(studentData[r][0]+", "+studentData[r][1]+" "+month+"/"+day+"/"+year);
               }
            }
        // Call Sorted Birthday Output
            sortedBirthdayOutput(studentData, rSize, writer);
        }
    // Close Files
        in.close();
        writer.close();
    }
 
    
    public static double calcHighestGPA(String[][] array, int size)
    {
    // Variables
        double GPA;
        double highestGPA = 0;
    // Find Highest GPA
        for(int count = 0; count < size; count++)
        {
            GPA = Double.parseDouble(array[count][6]);
            if(GPA > highestGPA)
                highestGPA = GPA;
        }
        return highestGPA;
    }
    
    public static void sortedLastNameOutput(String[][] array, int size, PrintWriter writer)
    {
    // Variables
        boolean notSorted = true;
        double compareStrings;
        String tempLastName;
        String tempFirstName;
        String tempMajor;
        String tempBirthdate;
    // Sort
        while(notSorted)
        {
            notSorted = false;
            for(int count = 0; count < size - 1; count++)
            {
                compareStrings = array[count][0].compareToIgnoreCase(array[count + 1][0]);
                if(compareStrings > 0)
                {
                    tempLastName = array[count][0];
                    tempFirstName = array[count][1];
                    tempMajor = array[count][3];
                    tempBirthdate = array[count][5];
                    array[count][0] = array[count + 1][0];
                    array[count][1] = array[count + 1][1];
                    array[count][3] = array[count + 1][3];
                    array[count][5] = array[count + 1][5];
                    array[count + 1][0] = tempLastName;
                    array[count + 1][1] = tempFirstName;
                    array[count + 1][3] = tempMajor;
                    array[count + 1][5] = tempBirthdate;
                    notSorted = true;
                }
            }
        }
    // Output Results
        System.out.println("Sorted by Last Name: ");
        writer.println("Sorted by Last Name: ");
        System.out.println();
        writer.println();
        for(int count = 0; count < size; count++)
        {
            System.out.println(array[count][0]+", "+array[count][1]+" "+array[count][3]+" major");
            writer.println(array[count][0]+", "+array[count][1]+" "+array[count][3]+" major");
        }
        System.out.println();
        writer.println();
    }
    
    public static void sortedBirthdayOutput(String[][] array, int size, PrintWriter writer)
    {
    // Variables
        int birthdate1, birthdate2;
        int day1, day2;
        int month1, month2;
        int year1, year2;
        String tempLastName, tempFirstName, tempBirthdate;
        boolean notSorted = true;
    // Sort
        while(notSorted)
        {
            notSorted = false;
            for(int r = 0; r < size - 1; r++)
            {
                birthdate1 = Integer.parseInt(array[r][5]);
                month1 = birthdate1 / 10000;
                birthdate1 %= 10000;
                day1 = birthdate1 / 100;
                birthdate1 %= 100;
                year1 = birthdate1;
                birthdate2 = Integer.parseInt(array[r + 1][5]);
                month2 = birthdate2 / 10000;
                birthdate2 %= 10000;
                day2 = birthdate2 / 100;
                birthdate2 %= 100;
                year2 = birthdate2;
                if(year2 < year1)
                {
                    tempLastName = array[r][0];
                    tempFirstName = array[r][1];
                    tempBirthdate = array[r][5];
                    array[r][0] = array[r + 1][0];
                    array[r][1] = array[r + 1][1];
                    array[r][5] = array[r + 1][5];
                    array[r + 1][0] = tempLastName;
                    array[r + 1][1] = tempFirstName;
                    array[r + 1][5] = tempBirthdate;
                    notSorted = true;
                }
                if(year1 == year2 && month2 < month1)
                {
                   tempLastName = array[r][0];
                    tempFirstName = array[r][1];
                    tempBirthdate = array[r][5];
                    array[r][0] = array[r + 1][0];
                    array[r][1] = array[r + 1][1];
                    array[r][5] = array[r + 1][5];
                    array[r + 1][0] = tempLastName;
                    array[r + 1][1] = tempFirstName;
                    array[r + 1][5] = tempBirthdate;
                    notSorted = true; 
                }
                if(year1 == year2 && month1 == month2 && day2 < day1)
                {
                    tempLastName = array[r][0];
                    tempFirstName = array[r][1];
                    tempBirthdate = array[r][5];
                    array[r][0] = array[r + 1][0];
                    array[r][1] = array[r + 1][1];
                    array[r][5] = array[r + 1][5];
                    array[r + 1][0] = tempLastName;
                    array[r + 1][1] = tempFirstName;
                    array[r + 1][5] = tempBirthdate;
                    notSorted = true;
                }
            }
        }
   // Output Results
        System.out.println();
        writer.println();
        System.out.println("Sorted by Birthdate: ");
        writer.println("Sorted by Birthdate: ");
        System.out.println();
        writer.println();
        for(int count = 0; count < size; count++)
        {
            birthdate1 = Integer.parseInt(array[count][5]);
            month1 = birthdate1 / 10000;
            birthdate1 %= 10000;
            day1 = birthdate1 / 100;
            birthdate1 %= 100;
            year1 = birthdate1;
            if(month1 < 10 && day1 < 10)
            {
                System.out.println(array[count][0]+", "+array[count][1]+" 0"+month1+"/0"+day1+"/"+year1);
                writer.println(array[count][0]+", "+array[count][1]+" 0"+month1+"/0"+day1+"/"+year1);
            }
               else if(month1 < 10)
               {
                   System.out.println(array[count][0]+", "+array[count][1]+" 0"+month1+"/"+day1+"/"+year1);
                   writer.println(array[count][0]+", "+array[count][1]+" 0"+month1+"/"+day1+"/"+year1);
               }
               else if(day1 < 10)
               {
                   System.out.println(array[count][0]+", "+array[count][1]+" "+month1+"/0"+day1+"/"+year1);
                   writer.println(array[count][0]+", "+array[count][1]+" "+month1+"/0"+day1+"/"+year1);
               }
               else
               {
                   System.out.println(array[count][0]+", "+array[count][1]+" "+month1+"/"+day1+"/"+year1);
                   writer.println(array[count][0]+", "+array[count][1]+" "+month1+"/"+day1+"/"+year1);
               }
        }
    }
}
