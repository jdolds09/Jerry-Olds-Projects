#include<stdio.h>
#include<string.h>

// Function Prototypes
void ascending_sort(char *string, int length);
void descending_sort(char *string, int length);
void display(char *string, int length);

int main(int argc, char *argv[])
{
//Variables
    char unsorted_string[] = {"ZkAyapHw9V2KX0cboqQe"};
    char* string_ptr = unsorted_string;
    int length = sizeof(unsorted_string) / sizeof(unsorted_string[0]);
    int i;

// Program Title
    printf("\n\tHomework 3\n");

// Display Unsorted String
    printf("Unsorted string: ");
    for(i = 0; i < (length - 1); i++)
    {
        printf("%c", *(string_ptr + i));
    }
    printf("\n");
  
// Call Ascending Sort Function
    ascending_sort(string_ptr, length);

// Call Descending Sort Function
    descending_sort(string_ptr, length);
   
// End of Program
    printf("\n");
    return 0;
}

void ascending_sort(char *string, int length)
{
// Variables
    int bool = 1; // Boolean Flag
    int i;
    char temp; 
// Sort Algorithm
    while(bool == 1)
    {
        bool = 0;
        for(i = 0; i < (length - 1); i++)
        {
            if(string[i + 1] < string[i])
            {
                temp = string[i];
                string[i] = string[i + 1];
                string[i + 1] = temp;
                if(bool == 0)
                {
                    bool = 1;
                }
            }
        }
    }
// Call Display Function
    printf("Ascending sort : ");
    display(string, length);
}

void descending_sort(char *string, int length)
{
// Variables
    int bool = 1; // Boolean Flag
    int i;
    char temp;
// Sort Algorithm
    while(bool == 1)
    {
        bool = 0;
        for(i = 0; i < (length - 1); i++)
        {
            if(string[i] < string[i + 1])
            {
                temp = string[i];
                string[i] = string[i + 1];
                string[i + 1] = temp;
                if(bool == 0)
                {
                    bool = 1;
                }
            }
        }
    }
// Call Display Function
    printf("Descending sort: ");
    display(string, length);    
}

void display(char *string, int length)
{
    int i;
    for(i = 0; i < length; i++)
    {
        printf("%c", string[i]);
    }

    printf("\n");
}

