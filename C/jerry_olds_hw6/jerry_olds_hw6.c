#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structures
typedef struct f_in
{
    char outline;
    int lines;
    int rows;
    int num_args;
}F_IN;

typedef struct args_in
{
    char in_string[20];
    int t_format;
}ARGS_IN;

// Function Prototypes
void spaces(char question[], F_IN border);
void change_border(F_IN border);
void add_question(F_IN border, int max_length, char answer[][100], char question[][100]);
void remove_question(F_IN border, char question[][100], char answer[][100]);
void print_answers(F_IN border, char answer[][100], char question[][100]);

int main(int argc, char *argv[])
{
// Variables
    int flag = 0; // Boolean Flag
    int count = 0;
    int counter = 0;
    int max_string = 21;
    char question[7][100];
    char answer[2][100];
    char selection;
    FILE *fptr;
    F_IN border;
    ARGS_IN input;
// Program Title
    printf("\n\tHomework 6");
    do
    {
    // Read in Border Values
        fptr = fopen("border.txt", "r");
        if(fptr == NULL)
        {
            fclose(fptr);
            fptr = fopen("border.txt", "w");
            fprintf(fptr, "* 5 27 5");
            fclose(fptr);
            fptr = fopen("border.txt", "r");
        }
        fscanf(fptr, "%c", &border.outline);
        fscanf(fptr, "%d", &border.lines);
        fscanf(fptr, "%d", &border.rows);
        fscanf(fptr, "%d", &border.num_args);
        fclose(fptr);
    // Open Default File
        fptr = fopen("default.txt", "r");
        if(fptr == NULL)
        {
            fclose(fptr);
            fptr = fopen("default.txt", "w");
            fprintf(fptr, "1) What char for border?2) Add question3) Remove question4) Print last answers5) Exit");
            fclose(fptr);
            fptr = fopen("default.txt", "r");
        }
    // Create Top Part of Border
        printf("\n\n");
        count = 0;
        while(count < border.rows)
        {
          printf("%c", border.outline);
          count++;
        }
        count = 0;
        printf("\n");
    // Read Values
        for(count = 0; count < border.num_args; count++)
        {
             fscanf(fptr, "%[^\n]%*c", question[count]);
             printf("%c%s", border.outline, question[count]);
             spaces(question[count], border);
        }
    // Create Bottom Part of Border
        count = 0;
        while(count < border.rows)
        {
            printf("%c", border.outline);
            count++;
        }
    // Close File
        fclose(fptr);
    // Prompt User
        printf("\n\n");
        printf("Please select one of the options above(1-%d): ", border.num_args);
        scanf("%c", &selection);
    // Input Validation
        if(border.num_args == 7)
        {
            while(selection != '1' && selection != '2' && selection != '3' && selection != '4' && selection != '5' && selection != '6' && selection != '7')
            {
                 printf("\nInvalid Input.\n");
                 printf("Please select one of the options above(1-%d): ", border.num_args);
                 scanf("%c", &selection);
            }
        }
        else if(border.num_args == 6)
        {
            while(selection != '1' && selection != '2' && selection != '3' && selection != '4' && selection != '5' && selection != '6')
            {
                printf("\nInvalid Input.\n");
                printf("Please select one of the options above(1-%d): ", border.num_args);
                scanf("%c", &selection);
            }
        }
        else
        {
            while(selection != '1' && selection != '2' && selection != '3' && selection != '4' && selection != '5')
            {
                printf("\nInvalid Input.\n");
                printf("Please select one of the options above(1-%d): ", border.num_args);
                scanf("%c", &selection);
            }
        }    
    // Preform Action Selected by User
        switch(selection)
        {
            case '1':
               change_border(border);
               break;
             case '2':
                add_question(border, max_string, answer, question);
                break;
             case '3':
                remove_question(border, question, answer);
                break;
             case '4':
                print_answers(border, answer, question);
                break;
             case '6':
               printf("Answer: %s", answer[0]);
               break;
             case '7':
               printf("Answer: %s", answer[1]);
               break;
            }
    }while(selection != '5');
// End of Program
    return 0;
}

void spaces(char question[], F_IN border)
{
// Variables
    int count = 0;
    int blanks = 0;
    int length = 0;
// Find Length of String
    while(question[count] != '\0')
    {
        length++;
        count++;
    }
// Find How Many Spaces Needed
    blanks = border.rows - (length + 2);
// Print Result
    for(count = 0; count < blanks; count++)
    {
        printf(" ");
    }
    printf("%c\n", border.outline);
}

void change_border(F_IN border)
{
// Variables
    char new_border;
    FILE* fptr;
// Prompt User
    printf("What would you like to change the border to: ");
    scanf("%*c%c", &new_border);
// Make New Border
    fptr = fopen("border.txt", "w");
    fprintf(fptr, "%c %d %d %d", new_border, border.lines, border.rows, border.num_args);
    fclose(fptr);
}

void add_question(F_IN border, int max_length, char answer[][100], char question[][100])
{
// Variables
    int count = 0;
    int length = 0;
    char input[100];
    FILE* fptr;
// Check to See if num_args Exceeds 7
    if(border.num_args == 7)
    {
        printf("Number of added questions must not exceed 2.\n");
        printf("Please remove a question before adding another.");
    }
    else
    {
        border.num_args++;
        printf("Please enter the question you would like to add: ");
        scanf("%*c%[^\n]%*c", input);
        strcpy(question[border.num_args], input);
        printf("Please enter the answer to that question: ");
        if(border.num_args == 6)
        {
            scanf("%[^\n]%*c", &answer[0]);
        }
        else
        {
            scanf("%[^\n]%*c", &answer[1]);
        }
        while(input[count] != '\0')
        {
            length++;
            count++;
        }
        if(length > max_length)
        {
            border.rows += (length - max_length);
        }
        if(border.num_args == 6)
        {
            fptr = fopen("answers.txt", "w");
            fprintf(fptr, "%s", answer[0]);
            fclose(fptr);
        }
        else
        {
            fptr = fopen("answers.txt", "a+");
            fprintf(fptr, " %s", answer[1]);
            fclose(fptr);
        }
        fptr = fopen("default.txt", "w");
        for(count = 0; count < (border.num_args - 1); count++)
        {
            fprintf(fptr, "%s\n", question[count]);
        }
        fprintf(fptr, "%d) %s", border.num_args, input);
        fclose(fptr);
        fptr = fopen("border.txt", "w");
        fprintf(fptr, "%c %d %d %d", border.outline, border.lines, border.rows, border.num_args);
        fclose(fptr);
    }
}

void remove_question(F_IN border, char question[][100], char answer[][100])
{
// Variables
    FILE* fptr;
    int count = 0;
    int counter = 0;
    int length = 0;
    int input = 0;
    int max_length = 0;
// Action if num_args is equal to 5
    if(border.num_args == 5)
    {
        printf("You must first add a question if you want to remove a question.");
    }
    else if(border.num_args == 6)
    {
        fptr = fopen("default.txt", "w");
        for(count = 0; count < 5; count++)
        {
            fprintf(fptr, "%s\n", question[count]);
        }
        fclose(fptr);
        for(count = 0; count < 100; count++)
        {
            answer[0][count] = '\0';
        }
    }
    else
    {
        printf("Please enter the question you would like removed(6-7): ");
        scanf("%d", &input);
        while(input != 6 && input != 7)
        {
            printf("Invalid input.\n");
            printf("Please enter the question you would like removed(6-7): ");
            scanf("%d", &input);
        }
        if(input == 6)
        {
            strcpy(question[5], question[6]);
            strcpy(answer[0], answer[1]);
            question[5][0] = '6';
            for(count = 0; count < 100; count++)
            {
                question[6][count] = '\0';
                answer[1][count] = '\0';
            }
            fptr = fopen("default.txt", "w");
            for(count = 0; count < 6; count++)
            {
                fprintf(fptr, "%s\n", question[count]);
            }
            fclose(fptr);
        }
        else
        {
            for(count = 0; count < 100; count++)
            {
                question[6][count] = '\0';
                answer[1][count] = '\0';
            }
            fptr = fopen("default.txt", "w");
            for(count = 0; count < 6; count++)
            {
                fprintf(fptr, "%s\n", question[count]);
            }
            fclose(fptr);
        }
    }
    if(border.num_args == 6 || border.num_args == 7)
    {
        border.num_args--;
    // Find Longest String
        for(count = 0; count < border.num_args; count++)
        {
            counter = 0;
            length = 0;
            while(question[count][counter] != '\0')
            {
                length++;
                counter++;
            }
            if(length > max_length)
            {
                max_length = length;
            }
        }
        border.rows = (max_length + 3);
        fptr = fopen("border.txt", "w");
        fprintf(fptr, "%c %d %d %d", border.outline, border.lines, border.rows, border.num_args);
        fclose(fptr);
    }
}

void print_answers(F_IN border, char answer[][100], char question[][100])
{
// Variable
    int count = 0;
// Check to see if question has been added
    if(border.num_args == 5)
    {
        printf("You must add at least 1 question before printing answers.");
    }
    else if(border.num_args == 6)
    {
        for(count = 0; count < 97; count++)
        {
            question[5][count] = question[5][count + 3];
        }
        printf("Question: %s\n", question[5]);
        printf("Answer: %s", answer[0]);
    }
    else
    {
        for(count = 0; count < 97; count++)
        {
            question[5][count] = question[5][count + 3];
        }
        for(count = 0; count < 97; count++)
        { 
            question[6][count] = question[6][count + 3];
        }
        printf("Question: %s\n", question[5]);
        printf("Answer: %s\n\n", answer[0]);
        printf("Question: %s\n", question[6]);
        printf("Answer: %s", answer[1]);
    }    
}
