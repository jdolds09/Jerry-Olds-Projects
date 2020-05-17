/*
 * Lab 6 Part 1b
 * CSE-1310-005
 */
package lab6part1b;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 *
 * @author Jerry Olds
 */
public class Lab6Part1b {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
    // Variables
    //*********************************************************
    //*Values that exceed 50 for Home Assignment are set to 50*
    //*********************************************************
        boolean fileFound = true;
        File inFile = new File("grades.txt");
        Scanner in = new Scanner(System.in);
        try
        {
            in = new Scanner(inFile);
        }
        catch(FileNotFoundException fnf)
        {
            System.out.println("File not found. Please try again.");
            fileFound = false;
        }
        String last_name = "";
        String first_name = "";
        int hw_count = 0;
        double t1 = 0.0;
        double t2 = 0.0;
        double tFinal = 0.0;
        double hw1 = 0.0;
        double hw2 = 0.0;
        double hw3 = 0.0;
        double hw4 = 0.0;
        double hw5 = 0.0;
        double hw6 = 0.0;
        double q1 = 0.0;
        double q2 = 0.0;
        double MaxTestScore = (100 * .1) + (100 * .15) + (200 * .25);
        double MaxHwScore;
        double MaxQuizScore = 20 * .01;
        double MaxScore;
        double studentTestScore;
        double studentHwScore;
        double studentQuizScore;
        double studentScore;
        double studentFinalScore;
        double studentHighScore = -1;
        double studentLowScore = 101;
        double temp = 0;
        double runSum = 0;
        int count = 0;
        boolean notSorted = true;
    // Read In Values
        if(fileFound)
        {        
            while(in.hasNext())
            {
                last_name = in.next();
                t1 = in.nextDouble();
                System.out.print("TEST 1: "+t1+ " ");
                t2 = in.nextDouble();
                System.out.print("TEST 2: "+t2+ " ");
                tFinal = in.nextDouble();
                System.out.print("FINAL: "+tFinal+ " ");
                hw1 = in.nextDouble();
                if(hw1 > 50)
                    hw1 = 50;
                System.out.print("HW 1: "+hw1+" ");
                hw2 = in.nextDouble();
                if(hw2 > 50)
                    hw2 = 50;
                System.out.print("HW 2: "+hw2+" ");
                hw3 = in.nextDouble();
                    if(hw3 > 50)
                        hw3 = 5;
                System.out.print("HW 3: "+hw3+" ");
                hw4 = in.nextDouble();
                    if(hw4 > 50)
                        hw4 = 50;
                System.out.print("HW 4: "+hw4+" ");
                hw5 = in.nextDouble();
                    if(hw5 > 50)
                        hw5 = 50;
                System.out.print("HW 5: "+hw5+" ");
                hw6 = in.nextDouble();
                    if(hw6 > 50)
                        hw6 = 50;
                System.out.print("HW 6: "+hw6+" ");
                q1 = in.nextDouble();
                System.out.print("QUIZ 1: "+q1+" ");
                q2 = in.nextDouble();
                System.out.print("QUIZ 2: "+q2+" ");
                hw_count = in.nextInt();
                first_name = in.nextLine();
                first_name = first_name.trim();
            // Sort Homework Grades
                while(notSorted)
                {
                    if(hw6 > hw5)
                    {
                        temp = hw5;
                        hw5 = hw6;
                        hw6 = temp;
                    }
                    if(hw5 > hw4)
                    {
                        temp = hw4;
                        hw4 = hw5;
                        hw5 = temp;
                    }
                    if(hw6 > hw4)
                    {
                        temp = hw4;
                        hw4 = hw4;
                        hw6 = temp;
                    }
                    if(hw4 > hw3)
                    {
                        temp = hw3;
                        hw3 = hw4;
                        hw4 = temp;
                    }
                    if(hw5 > hw3)
                    {
                        temp = hw3;
                        hw3 = hw5;
                        hw5 = temp;
                    }
                    if(hw6 > hw3)
                    {
                        temp = hw3;
                        hw3 = hw6;
                        hw6 = temp;
                    }
                    if(hw3 > hw2)
                    {
                        temp = hw2;
                        hw2 = hw3;
                        hw3 = temp;
                    }
                    if(hw4 > hw2)
                    {
                        temp = hw2;
                        hw2 = hw4;
                        hw4 = temp;
                    }
                    if(hw5 > hw2)
                    {
                        temp = hw2;
                        hw2 = hw5;
                        hw5 = temp;
                    }
                    if(hw6 > hw2)
                    {
                        temp = hw2;
                        hw2 = hw6;
                        hw6 = temp;
                    }
                    if(hw2 > hw1)
                    {
                        temp = hw1;
                        hw1 = hw2;
                        hw2 = temp;
                    }
                    if(hw3 > hw1)
                    {
                        temp = hw1;
                        hw1 = hw3;
                        hw3 = temp;
                    }
                    if(hw4 > hw1)
                    {
                        temp = hw1;
                        hw1 = hw4;
                        hw4 = temp;
                    }
                    if(hw5 > hw1)
                    {
                        temp = hw1;
                        hw1 = hw5;
                        hw5 = temp;
                    }
                    if(hw6 > hw1)
                    {
                        temp = hw1;
                        hw1 = hw6;
                        hw6 = temp;
                    }
                    if(hw1 >= hw2 && hw2 >= hw3 && hw3 >= hw4 && hw4 >= hw5 && hw5 >= hw6)
                        notSorted = false;
                }
            // Calculate Max Homework Score
                if(hw_count == 6)
                    MaxHwScore = (200 * .12);
                else if(hw_count == 5)
                    MaxHwScore = (200 * .115);
                else if(hw_count == 4)
                    MaxHwScore = (200 * .1);
                else
                    MaxHwScore = (200 * .075);
            // Calculate Max Score
                MaxScore = MaxTestScore + MaxHwScore + MaxQuizScore;
            // Calculate Student Test Score
                studentTestScore = (t1 * .1) + (t2 * .15) + (tFinal * .25);
            // Calculate Student HW Score
                if(hw_count == 6)
                    studentHwScore = (hw1 + hw2 + hw3 + hw4) * .12;
                else if (hw_count == 5)
                    studentHwScore = (hw1 + hw2 + hw3 + hw4) * .115;
                else if (hw_count == 4)
                    studentHwScore = (hw1 + hw2 + hw3 + hw4) * .1;
                else
                    studentHwScore = (hw1 + hw2 + hw3 + hw4) * .075;
            // Calculate Student Quiz Score
                studentQuizScore = (q1 + q2) * .01;
            // Calculate Student Score
                studentScore = studentTestScore + studentHwScore + studentQuizScore;
            // Calculate Student Final Score
                studentFinalScore = studentScore / (MaxScore * .01);
                count++;
                runSum += studentFinalScore;
                if(count == 33)
                    runSum /= 33.0;
            // Calculate Highest Score in the Class
                if(studentFinalScore > studentHighScore)
                    studentHighScore = studentFinalScore;
            // Calculate Lowest Score in the Class
                if(studentFinalScore < studentLowScore)
                    studentLowScore = studentFinalScore;
            // Output Results
                System.out.println();
                System.out.printf(last_name+", "+first_name+": %.2f\n\n", studentFinalScore);
            }
            // Output Class Average, Highest Score, and Lowest Score
                System.out.printf("Class Average: %.2f\n", runSum);
                System.out.printf("Highest Score in the Class: %.2f\n", studentHighScore);
                System.out.printf("Lowest Score in the Class: %.2f\n", studentLowScore);
                
        }
// Close Input File
    in.close();
    }  
    
}
