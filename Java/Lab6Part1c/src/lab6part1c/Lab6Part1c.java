/*
 * Lab 6 Part 1c
 * CSE-1310-005
 */
package lab6part1c;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 *
 * @author Jerry Olds
 */
public class Lab6Part1c {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
    // Variables
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
        final int GRADES_MAX = 12;
        final int NAMES_MAX = 2;
        int count = 0;
        double grades[] = new double[GRADES_MAX];
        String names[] = new String[NAMES_MAX];
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
        boolean notSorted = true;
// Read In Values
        if(fileFound)
        {        
            while(in.hasNext())
            {
                names[0] = in.next();
                grades[0] = in.nextDouble();
                System.out.print("TEST 1: "+grades[0]+ " ");
                grades[1] = in.nextDouble();
                System.out.print("TEST 2: "+grades[1]+ " ");
                grades[2] = in.nextDouble();
                System.out.print("FINAL: "+grades[2]+ " ");
                grades[3] = in.nextDouble();
                    if(grades[3] > 50)
                        grades[3] = 50;
                System.out.print("HW 1: "+grades[3]+" ");
                grades[4] = in.nextDouble();
                    if(grades[4] > 50)
                        grades[4] = 50;
                System.out.print("HW 2: "+grades[4]+" ");
                grades[5] = in.nextDouble();
                    if(grades[5] > 50)
                        grades[5] = 50;
                System.out.print("HW 3: "+grades[5]+" ");
                grades[6] = in.nextDouble();
                    if(grades[6] > 50)
                        grades[6] = 50;
                System.out.print("HW 4: "+grades[6]+" ");
                grades[7] = in.nextDouble();
                    if(grades[7] > 50)
                        grades[7] = 50;
                System.out.print("HW 5: "+grades[7]+" ");
                grades[8] = in.nextDouble();
                    if(grades[8] > 50)
                        grades[8] = 50;
                System.out.print("HW 6: "+grades[8]+" ");
                grades[9] = in.nextDouble();
                System.out.print("QUIZ 1: "+grades[9]+" ");
                grades[10] = in.nextDouble();
                System.out.print("QUIZ 1: "+grades[10]+" ");
                grades[11] = in.nextInt();
                names[1] = in.nextLine();
                names[1] = names[1].trim();
            // Sort Homework Grades
                while(notSorted)
                {
                    notSorted = false;
                    for(int i = 8; i > 3 ; i--) 
                    {
                        if(grades[i] > grades[i-1])
                        {
                            temp = grades[i-1];
                            grades[i-1] = grades[i];
                            grades[i] = temp;
                            notSorted = true;
                        }
                    }
                }
            // Calculate Max Homework Score
                if(grades[11] == 6)
                    MaxHwScore = (200 * .12);
                else if(grades[11] == 5)
                    MaxHwScore = (200 * .115);
                else if(grades[11] == 4)
                    MaxHwScore = (200 * .1);
                else
                    MaxHwScore = (200 * .075);
            // Calculate Max Score
                MaxScore = MaxTestScore + MaxHwScore + MaxQuizScore;
            // Calculate Student Test Score
                studentTestScore = (grades[0] * .1) + (grades[1] * .15) + (grades[2] * .25);
            // Calculate Student HW Score
                if(grades[11] == 6)
                    studentHwScore = (grades[3] + grades[4] + grades[5] + grades[6]) * .12;
                else if (grades[11] == 5)
                    studentHwScore = (grades[3] + grades[4] + grades[5] + grades[6]) * .115;
                else if (grades[11] == 4)
                    studentHwScore = (grades[3] + grades[4] + grades[5] + grades[6]) * .1;
                else
                    studentHwScore = (grades[3] + grades[4] + grades[5]+ grades[6]) * .075;
            // Calculate Student Quiz Score
                studentQuizScore = (grades[9] + grades[10]) * .01;
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
            // Calculate the Lowest Score in the Class
                if(studentFinalScore < studentLowScore)
                    studentLowScore = studentFinalScore;
            // Output Results
                System.out.println();
                System.out.printf(names[0]+", "+names[1]+": %.2f\n\n", studentFinalScore);
            }
            // Output Highest and Lowest Scores
                System.out.printf("Class Average: %.2f\n", runSum);
                System.out.printf("Highest Score in the Class: %.2f\n", studentHighScore);
                System.out.printf("Lowest Score in the Class: %.2f\n", studentLowScore);
        }
// Close Input File
    in.close();
    }  
    
}
