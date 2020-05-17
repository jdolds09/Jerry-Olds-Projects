#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "jerry_olds_hw7.h"

int main(int argc, char *argv[])
{
// Variable
    Node *head = NULL;
    FILE *fptr;
    char word[100];
    char alternate[100];
    char letter;
    int i;
    int iterations = 0;
    int bool = 1;
// Program Title
    printf("\n\n\t\tHomework 7\n\n");
    if(argc < 2)
    {
        printf("No files found.\n");
        printf("Enter words to replace file. Hit the Enter key when finished.\n\n");
        alternate[0] = '\0';
        while(alternate[0] != 'X')
        {
            printf("Please enter a word: ");
            if(iterations == 0)
            {
                scanf("%[^\n]", alternate);
            }
            else
            {
                scanf("%*c%[^\n]", alternate);
            }
            if(alternate[0] == '\0')
            {
                alternate[0] = 'X';
            }
            if(alternate[0] != 'X')
            {
                insert(&head, alternate);
                sort(&head);
                i = 0;
                while(alternate[i] != '\0')
                {
                    alternate[i] = '\0';
                    i++;
                }
            }
            iterations++;
        }
        printf("\n");    
        display(&head);
    }
// If One File is Inputted in Command Line
    else if(argc == 2)
    {
    // Alternate Logic for Only One File
        printf("Only one file found.\n");
        printf("Please words to replace the second file.\n");
        printf("Press the Enter key when finsihed\n\n");
        alternate[0] = '\0';
        while(alternate[0] != 'X')
        {
            printf("Please enter a word: ");
            if(iterations == 0)
            {
                scanf("%[^\n]", alternate);
            }
            else
            {
                scanf("%*c%[^\n]", alternate);
            }
            if(alternate[0] == '\0')
            {
                alternate[0] = 'X';
            }
            if(alternate[0] != 'X')
            {
                insert(&head, alternate);
                sort(&head);
                i = 0;
                while(alternate[i] != '\0')
                {
                    alternate[i] = '\0';
                    i++;
                }
            }
            iterations++;
        }
    // Open File
        fptr = fopen(argv[1], "r");
    // Read Data
        while(fscanf(fptr, "%s", &word) != EOF)
        {
            insert(&head, word);
            sort(&head);
            i = 0;
            while(word[i] != '\0')
            {
                word[i] = '\0';
                i++;
            }
        }
    // Call Display Function
        display(&head);
    // Close File
        fclose(fptr);
    }
    else
    {
    // Open File
        fptr = fopen(argv[1], "r");
    // Read Data
        while(fscanf(fptr, "%s", &word) != EOF)
        {
            insert(&head, word);
            sort(&head);
            i = 0;
            while(word[i] != '\0')
            {
                word[i] = '\0';
                i++;
            }
        }
    // Close File
        fclose(fptr);
    // Open File
        fptr = fopen(argv[2], "r");
    // Read Data
        while(fscanf(fptr, "%s", &word) != EOF)
        {
            insert(&head, word); 
            sort(&head);
            i = 0;
            while(word[i] != '\0')
            {
                word[i] = '\0';
                i++;
            }
        }
    // Call Display Function
        display(&head);
    // Close File
        fclose(fptr);
    }
// End of Program
    return 0;
}

