#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct hw5_struct 
{
    char f_name[12];
    char l_name[12];
    int age;
    float height;

}HW_struct;

int main(int argc, char *argv[])
{
// Variables
    FILE *fptr;
    HW_struct info[10];
    int count = 0;
    int size = 0;
    char data[100];
// Open File
    fptr = fopen("/home/f/fl/floodw/HW5", "r");
// Check To See If File Opened
    if(fptr == NULL)
    {
        printf("File did not open.\n");
        EXIT_FAILURE;
    }
// Program Title
    printf("\n\tHomework 5\n\n");
// Read In Data In File
    while(info[count].f_name != EOF)
    {
        fscanf(fptr, "%s", &info[count].f_name);
        if(info[count].f_name != EOF)
        {
            fscanf(fptr, "%s", &info[count].l_name);
            fscanf(fptr, "%d", &info[count].age);
            fscanf(fptr, "%f", &info[count].height);
            count++;
        }
    }
// Close File
    fclose(fptr);
// End Of Program 
    return 0;
// FILE HAS CORRUPTED DATA AND SYMBOLS IN IT. 
}
