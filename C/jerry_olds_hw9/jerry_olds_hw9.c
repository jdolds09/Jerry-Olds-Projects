#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "jerry_olds_hw9.h"

void distribute(char *data, char *num1, char *num2, char *num3, char *num4, char *num5);

int main(int argc, char *argv[])
{
// Variables
    Node *head = NULL;
    FILE *fptr;
    char data[21];
    char num1[5];
    char num2[5];
    char num3[5];
    char num4[5];
    char num5[5];
    int number1 = 0;
    int number2 = 0;
    int number3 = 0;
    int number4 = 0;
    int number5 = 0;
    int i = 0;
    int count = 1;
    int num_lists;
    int value = 0;
// Program Title
    printf("\n\t\tHomework 9\n\n");
// Check for Insufficient Parameters
    if(argc < 3)
    {
        printf("Insufficient Parameters.\n");
        printf("Please enter a file and a number in the command line.\n\n");
        return 1;
    }
// Number of Linked Lists
    num_lists = atoi(argv[2]);
    Node *lists[num_lists];
    for(i = 0; i < num_lists; i++)
    {
        lists[i] = NULL;
    }  
// Open File
    fptr = fopen(argv[1], "r");
// Read Data
    while(fscanf(fptr, "%s", data) != EOF)
    {
        distribute(data, num1, num2, num3, num4, num5);
        number1 = atoi(num1);
        number2 = atoi(num2);
        number3 = atoi(num3);
        number4 = atoi(num4);
        number5 = atoi(num5);
        value = (number1 + number2 + number3 + number4 + number5) % num_lists;
        if(lists[value] == NULL)
        {
            head = NULL;
            append(&head, data, count, value);
            lists[value] = head;
        }
        else
        {
            head = lists[value];
            append(&head, data, count, value);
        }
        count++;
    }
// Display
    i = 0;
    while(i < num_lists)
    {
        head = lists[i];
        display(&head, i);
        i++;
    }
// End of Program
    printf("\n");
    return 0;
}

void distribute(char *data, char *num1, char *num2, char *num3, char *num4, char *num5)
{
// Variables
    int i = 0;
    int count = 0;
// Distribute
    while(i < 4)
    {
        num1[count] = data[i];
        count++;
        i++;
    }
    count = 0;
    while(i < 8)
    {
        num2[count] = data[i];
        count++;
        i++;
    }
    count = 0;
    while(i < 12)
    {
        num3[count] = data[i];
        count++;
        i++;
    }
    num3[4] = '\0';
    count = 0;
    while(i < 16)
    {
        num4[count] = data[i];
        count++;
        i++;
    }
    count = 0;
    while(i < 20)
    {
        num5[count] = data[i];
        count++;
        i++;
    }
}
