/*
 * Lab 6 Part 1f
 * CSE-1310-005
 */
package lab6part1f;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 *
 * @author Jerry Olds
 */
public class Lab6Part1f
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
    // Variables
        boolean fileFound = true;
        File inFile = new File("grades.txt");
        File outFile = new File("gradesOut.txt");
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        try
        {
            in = new Scanner(inFile);
        }
        catch(FileNotFoundException fnf)
        {
            System.out.println("Input file not found. Please try again.");
            fileFound = false;
        }
        try
        {
            out = new PrintWriter(outFile);
        }
         catch(IOException ioe)
        {
            System.out.println("Output file not found. Please try again.");
            fileFound = false;
        }
        final int GRADES_MAX = 13;
        final int NAMES_MAX = 2;
        final int STUDENT_MAX = 33;
        int r, c;
        int count = 0;
        double compareStrings;
        double grades[][] = new double[STUDENT_MAX][GRADES_MAX];
        String names[][] = new String[STUDENT_MAX][NAMES_MAX];
        double MaxTestScore = (100 * .1) + (100 * .15) + (200 * .25);
        double MaxHwScore;
        double MaxQuizScore = 20 * .01;
        double MaxScore;
        double studentTestScore;
        double studentHwScore;
        double studentQuizScore;
        double studentScore;
        double studentFinalScore;
        double studentHighScore = 0;
        double studentLowScore = 101;
        double temp = 0;
        double runSum = 0.0;
        String tempString = "";
        String tempString2 = "";
        boolean notSorted = true;
// Read In Values
        if(fileFound)
        {        
            for(r = 0; r < 33; r++)
            {
                names[r][0] = in.next();
               for(c = 0; c < 12; c++)
                {
                    grades[r][c] = in.nextDouble();
                    if(grades[r][3] > 50)
                        grades[r][3] = 50;
                    if(grades[r][4] > 50)
                        grades[r][4] = 50;
                    if(grades[r][5] > 50)
                        grades[r][5] = 50;
                    if(grades[r][6] > 50)
                        grades[r][6] = 50;
                    if(grades[r][7] > 50)
                        grades[r][7] = 50;
                    if(grades[r][8] > 50)
                        grades[r][8] = 50;
                }
                names[r][1] = in.nextLine();
                names[r][1] = names[r][1].trim();
            }  
            // Sort Homework Grades
                for(r = 0; r < 33; r++)
                {
                    while(notSorted)
                    {
                        notSorted = false;
                        for(c = 8; c > 3; c--)
                        {
                            if(grades[r][c] > grades[r][c-1])
                            {
                                temp = grades[r][c-1];
                                grades[r][c-1] = grades[r][c];
                                grades[r][c] = temp;
                                notSorted = true;
                            }
                        }
                    }
                }
            for(r = 0; r < 33; r++)
            {
            // Find Max Hw Score
                if(grades[r][11] == 6)
                    MaxHwScore = (200 * .12);
                else if(grades[r][11] == 5)
                    MaxHwScore = (200 * .115);
                else if(grades[r][11] == 4)
                    MaxHwScore = (200 * .1);
                else
                    MaxHwScore = (200 * .075);
            // Calculate Max Score
                MaxScore = MaxTestScore + MaxHwScore + MaxQuizScore;
            // Calculate Student Test Score
                studentTestScore = (grades[r][0] * .1) + (grades[r][1] * .15) + (grades[r][2] * .25);
                // Calculate Student Hw Score
                if(grades[r][11] == 6)
                    studentHwScore = (grades[r][3] + grades[r][4] + grades[r][5] + grades[r][6]) * .12;
                else if(grades[r][11] == 5)
                    studentHwScore = (grades[r][3] + grades[r][4] + grades[r][5] + grades[r][6]) * .115;
                else if(grades[r][11] == 4)
                    studentHwScore = (grades[r][3] + grades[r][4] + grades[r][5] + grades[r][6]) * .1;
                else
                    studentHwScore = (grades[r][3] + grades[r][4] + grades[r][5] + grades[r][6]) * .075;
                // Calculate Student Quiz Score
                    studentQuizScore = (grades[r][9] + grades[r][10]) * .01;
                // Calcualte Student Score
                    studentScore = studentTestScore + studentHwScore + studentQuizScore;
                // Calculate Student Final Score
                    grades[r][12] = studentScore / (MaxScore * .01);
                    count++;
                    runSum += grades[r][12];
                    if(count == 33)
                        runSum /= 33.0;
                    if(grades[r][12] > studentHighScore)
                        studentHighScore = grades[r][12];
                    if(grades[r][12] < studentLowScore)
                        studentLowScore = grades[r][12];
            }
        // Unsorted Output
            out.println("Unsorted");
            for(r = 0; r < 33; r++)
            { 
                out.print(names[r][0]+ ", "+names[r][1]+": ");
                out.printf("%.2f", grades[r][12]);
                out.println();
            }
            out.println();
            out.println("Sorted");
        // Sort Output by Last Name
            notSorted = true;
            while(notSorted)
            {
                notSorted = false;
                for(r = 0; r < 32; r++)
                {
                    compareStrings = names[r][0].compareToIgnoreCase(names[r + 1][0]);
                    if(compareStrings > 0)
                    {
                        tempString = names[r][0];
                        tempString2 = names[r][1];
                        temp = grades[r][12];
                        names[r][0] = names[r + 1][0];
                        names[r][1] = names[r + 1][1];
                        grades[r][12] = grades[r + 1][12];
                        names[r + 1][0] = tempString;
                        names[r + 1][1] = tempString2;
                        grades[r + 1][12] = temp;
                        notSorted = true;
                    }
                }
            }
        // Sorted Output
            for(r = 0; r < 33; r++)
            { 
                out.print(names[r][0]+ ", "+names[r][1]+": ");
                out.printf("%.2f", grades[r][12]);
                out.println();
            }
            notSorted = true;
        // Sort Final Grades
            while(notSorted)
            {
                notSorted = false;
                for(r = 0; r < 32; r++)
                {
                    if(grades[r][12] > grades[r + 1][12])
                    {
                        temp = grades[r + 1][12];
                        grades[r + 1][12] = grades[r][12];
                        grades[r][12] = temp;
                        notSorted = true;
                    }
                }
            }
        // Highest, Lowest and Median Grade
            out.println();
            out.printf("Class Average: %.2f", runSum);
            out.println();
            out.printf("Highest Score in the Class: %.2f", studentHighScore);
            out.println();
            out.printf("Lowest Score in the Class: %.2f\n", studentLowScore);
            out.println();
            out.printf("Median Score: %.2f\n", grades[15][12]);
            out.println();
        }
// Close Files
    in.close();
    out.close();
    }  
}