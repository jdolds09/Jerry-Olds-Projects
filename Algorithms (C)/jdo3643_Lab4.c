// Jerry Olds
// 1001533643
// CSE-2320-001
// Lab 4

// Command line to build: gcc jdo3643_Lab4.c -lm -o lab4
// Command line to run: lab4 [Insert file]
// Example run command: lab4 in.txt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function prototypes
    char *get_left_branch(char *tree);
    int find_black_height(char *tree);
    int check_double_red(char *tree);
    int check_black_height(char *tree, int black_height);

int main(int argc, char *argv[])
{
// Variables
    FILE *fptr;
    char tree[200];
    int black_height;
    int valid = 1; // Boolean variable

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

// Read tree
    fscanf(fptr, "%s", &tree);

// Output tree
    printf("%s\n", tree);

// Check to see if there are consecutive red nodes
    valid = check_double_red(tree);

    if(valid == 1)
        printf("Red property OK\n");
    else
    {
        printf("Red property problem\n");
        printf("Does not satisfy\n\n");
        return 1;
    }

// Find black height of tree
    black_height = find_black_height(tree);

    printf("Black height should be %d\n", black_height);
  
// Check black height validity
    valid = check_black_height(tree, black_height);

    if(valid == 1)
        printf("Black heights OK\n");
    else
    {
        printf("Black heights problem\n");
        printf("Does not satisfy\n\n");
        return 1;
    }

// Valid Red-Black Tree
        printf("Satisfies all properties\n\n");

// End of program
    return 0;
}

int find_black_height(char *tree)
{
// Variables
    char node;
    char *branch;
    int i;
    int black_height = 0;

// Get left branch
    branch = get_left_branch(tree);

// Count black nodes and sentinel
    for(i = 1; i < strlen(branch); i++)
        if(branch[i] == 'B' || branch[i] == '.')
            black_height++;

// Return black height
    return black_height;
}

int check_double_red(char *tree)
{
// Variables
    int i = 0;
    int j = 0;
    int c = 0;
    int valid = 1;
    int branch_size;
    int comparisons;
    char *left_branch;
    char *right_branch;
    char *branch;
    char prev_node;

// CHECK LEFT BRANCH AND ALL SUB BRANCHES FOR CONSECUTIVE RED NODES      
    left_branch = get_left_branch(tree);        
    branch = left_branch;                         
    branch_size = (strlen(branch) - 1);         
    comparisons = pow(2, (branch_size - 2));
    if(tree[branch_size + 1] == '.')
        c = (branch_size + 2);
    else
        c = (branch_size + 1);

// Go through all left side branches checking for consecutive red nodes
    for(j = 0; j < comparisons; j++)
    {    
        while(branch[i] != '.')
        {
            if(i == 0)
            {
                prev_node = branch[i];
                i++;
            }
            else
            {
                if(branch[i] == 'R' && prev_node == 'R')
                    return 0;
                else
                {
                    prev_node = branch[i];
                    i++;
                }
            }
        }
    
    // Next sub-branch
        if(j != (comparisons - 1))
        {
        // Remove sentinels from branch
            i = (strlen(branch) - 1);
            while(branch[i] == '.')
                branch[i] = '\0';
 
            if(tree[c + 1] == '.')
            {  
                branch[0] = left_branch[branch_size - 2];
                branch_size--;
            }
            else
                branch[0] = branch[(strlen(branch) - 1)];
            
            i = 1;
            
            while(tree[c] != '.')
            {
                branch[i] = tree[c];
                c++;
                i++;
            }
            
            branch[i] = '.';
            
            if(tree[c + 1] == '.')
                c += 2;
            else
                c++;
            
            i = 0;
        }
    }

// CHECK RIGHT BRANCH AND ALL SUB BRANCHES FOR CONSECUTIVE RED NODES

    i = 0;
    j = 0;
    memset(branch, '\0', sizeof(branch));
 
// First right branch
    while(tree[c] != '.')
    {
        branch[i] = tree[c];
        c++;
        i++;
    }

    branch[i] = '.';
    i = 0;
    
    if(tree[c + 1] == '.')
        c += 2;
    else
        c++; 

    right_branch = branch;

// Go through all right side branches checking for consecutive red nodes
    while(valid == 1)
    { 
        while(branch[i] != '.')
        {
            if(i == 0)
            {
                prev_node = branch[i];
                i++;
            }
            else
            {
                if(branch[i] == 'R' && prev_node == 'R')
                    return 0;
                else
                {
                    prev_node = branch[i];
                    i++;
                }
            }
        }

        i = 1;

        if(tree[c] == '\0')
            valid = 0;

    // Next sub-branch
        else
        {
            if(tree[c + 1] == '.')
                branch[0] = branch[(strlen(branch) - 3)];
            else
            {
                branch[0] = right_branch[j];
                j++;
            } 
           
            while(tree[c] != '.')
            {
                branch[i] = tree[c];
                i++;
                c++;
            }
            branch[i] = '.';
            if(tree[c + 1] == '.')
                c += 2;
            else
                c++;
        }
        i = 0;
    }

// No consecutive red nodes
    return 1;
}

int check_black_height(char *tree, int black_height)
{
// Variables
    char *branch;
    char *left_branch;
    char *right_branch;
    int branch_size;
    int comparisons;
    int valid = 1;
    int bh = 0;
    int i = 1;
    int j;
    int c;

// CHECK LEFT BRANCH AND ALL SUB BRANCHES FOR BLACK HEIGHT
    left_branch = get_left_branch(tree);
    branch = left_branch;
    branch_size = (strlen(branch) - 1);
    comparisons = pow(2, (branch_size - 2));
    if(tree[branch_size + 1] == '.')
        c = (branch_size + 2);
    else
        c = (branch_size + 1);

// Check all left side branches for valid black height
    for(j = 0; j < comparisons; j++)
    {
    // Count black nodes
        while(branch[i] != '.')
        {
            if(branch[i] == 'B')
                bh++;
            i++;
        }
    
    // Increment black height for sentinel
        bh++;
  
    // Check for validity
        if(bh != black_height)
            return 0;
        bh = 0;

    // Next sub-branch
        if(j != (comparisons - 1))
        {
        // Remove sentinels from branch
            i = (strlen(branch) - 1);
            while(branch[i] == '.')
                branch[i] = '\0';

            if(tree[c + 1] == '.')
            {
                branch[0] = left_branch[branch_size - 2];
                branch_size--;
            }
            else
                branch[0] = branch[(strlen(branch) - 1)];

            i = 1;

            while(tree[c] != '.')
            {
                branch[i] = tree[c];
                c++;
                i++;
            }

            branch[i] = '.';

            if(tree[c + 1] == '.')
                c += 2;
            else
                c++;

            i = 0;
        }
    }

// CHECK RIGHT BRANCH AND ALL SUB BRANCHES FOR CONSECUTIVE RED NODES

    i = 0;
    j = 0;
    memset(branch, '\0', sizeof(branch));

// First branch on right side
    while(tree[c] != '.')
    {
        branch[i] = tree[c];
        c++;
        i++;
    }

    branch[i] = '.';
    i = 0;

    if(tree[c + 1] == '.')
        c += 2;
    else
        c++;

    right_branch = branch;

// Check for black height validity
    while(valid == 1)
    {
        while(branch[i] != '.')
        {
          if(branch[i] == 'B')
              bh++;
          i++;
        }

        i = 1;

        if(tree[c] == '\0')
            valid = 0;

    // Next sub-branch
        else
        {
            if(tree[c + 1] == '.')
                branch[0] = branch[(strlen(branch) - 3)];
            else
            {
                branch[0] = right_branch[j];
                j++;
                right_branch[j] = tree[c];
            }

            while(tree[c] != '.')
            {
                branch[i] = tree[c];
                i++;
                c++;
            }
            branch[i] = '.';
            if(tree[c + 1] == '.')
                c += 2;
            else
                c++;
        }
        i = 0;
    }

// Valid black height among all branches
    return 1;
}

char *get_left_branch(char *tree)
{
// Variables
    char node;
    int i = 0;
    char *branch;

// Find length of left most branch
    do
    {
        node = tree[i];
        i++;
    }while(node != '.');

// Allocate memory for branch
    branch = (char *)malloc(i * sizeof(char *));

// Fill branch
    i = 0;
    do
    {
        node = tree[i];
        branch[i] = node;
        i++;
    }while(node != '.');    

    return branch;
}

