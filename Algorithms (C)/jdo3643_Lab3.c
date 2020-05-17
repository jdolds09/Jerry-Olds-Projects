// Jerry Olds
// 1001533643
// CSE-2320-001
// Lab 3

// Command line to build: gcc jdo3643_Lab3.c -o lab3
// Command line to run: lab3 [Insert file]
// Example run command: lab3 in.dat

#include <stdio.h>
#include <stdlib.h>

// Function prototype
    void find_subsequence(int *S, int **C, int size, int t1, int t2);
    void print_result(int *S, int **C, int size, int t1, int t2);

int main(int argc, char *argv[])
{
// Variables
    FILE *fptr;
    int *set;
    int **targets;
    int set_size;
    int set_value;
    int target1;
    int target2;
    int i;

// Check to see if input file has been sent through as command line argument
    if(argc == 1)
    {
        printf("No input file was sent through as command line argument.\n\n");
        return 1;
    }

// Open file
    fptr = fopen(argv[1], "r");

// Check to see if fptr is NULL
    if(fptr == NULL)
    {
        printf("NULL File Error.\n\n");
        return 1;
    }

// Read in number of values in the set and target values
    fscanf(fptr, "%d%d%d", &set_size, &target1, &target2);

// Dynamically allocate arrays
    set = (int *)malloc(set_size * sizeof(int));
    targets = (int **)malloc(2 * sizeof(int));
    targets[0] = (int *)malloc(target1 * sizeof(int));
    targets[1] = (int *)malloc(target2 * sizeof(int));

// Read in values to set array
    for(i = 0; i < set_size; i++)
    {
        fscanf(fptr, "%d", &set_value);
        set[i] = set_value;
    }

// Initalize 2d array to 0
    for(i = 0; i < target1; i++)
        targets[0][i] = 0;
    for(i =0; i < target2; i++)
        targets[1][i] = 0;

// Find subsequence
    find_subsequence(set, targets, set_size, target1, target2);

// Print results
    print_result(set, targets, set_size, target1, target2);

// Close file
    fclose(fptr);

// End of program
    return 0;
}

void find_subsequence(int *S, int **C, int size, int t1, int t2)
{
// Variables
    int j;
    int potentialSum;
    int leftover;

// Subsequence for target 1
    for(potentialSum = 1; potentialSum <= t1; potentialSum++)
    {
        for(j = 1; j <= size; j++)
        {
            leftover = potentialSum - S[j];
            if (leftover >= 0 && C[0][leftover] < j)
            break;
        }
        C[0][potentialSum] = j;
    }

// Subsequence for target 2
    for(potentialSum = 1; potentialSum <= t2; potentialSum++)
    {
        for(j = 1; j <= size; j++)
        {
            leftover = potentialSum - S[j];
            if (leftover >= 0 && C[1][leftover] < j)
            break;
        }
        C[1][potentialSum] = j;
    }
}

void print_result(int *S, int **C, int size, int t1, int t2)
{
// Variable
    int i;

// Print result
    printf("\nTargets are %d and %d\n", t1, t2);
    printf("i    S\n");
    printf("--------\n");
    for(i = 0; i < size; i++)
        printf("%d    %d\n", (i + 1), S[i]);
    printf("\nsubsequence for %d:\n", t1);
    for(i = t1; i > 0; i -= S[C[0][i]])
        printf("%d\n", S[C[0][i]]);
    printf("\nsubsequence for %d:\n", t2);
    for(i = t2; i > 0; i -= S[C[1][i]])
        printf("%d\n", S[C[1][i]]);
 
}
