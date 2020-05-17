#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

// Function Prototypes
void MenuDisplay(int num1, int num2, char *binary_num1, char *binary_num2, int display_choice);
char* IntToBinary(int num, int choice);
void BitwiseOperation(char *num1, char *num2, int choice);

int main(int argc, char *argv[])
{
// Variables
    int num1 = 0;
    int num2 = 0;
    int display_choice = 1;
    int i = 0;
    char binary_num1[100];
    char binary_num2[100];
    char selection = '0';
    char user_input[100];
// Program Title
    printf("\n\t\tHomework 10\n");
// Check for Insufficient Parameters
    if(argc < 3)
    {
        printf("\nInsufficient Parameters. Please enter two numbers in the command line.\n\n");
        return 1;
    }
// Convert Input to Integers
    num1 = atoi(argv[1]);
    num2 = atoi(argv[2]);
// Convert Integers to Binary
    strcpy(binary_num1, IntToBinary(num1, 1));
    strcpy(binary_num2, IntToBinary(num2, 2)); 
    while(selection != '6')
    {
    // Call MenuDisplay Function
        MenuDisplay(num1, num2, binary_num1, binary_num2, display_choice);
    // Prompt User
        printf("\nPlease select one of the options above(1-6): ");
        scanf("%s", &user_input);
        selection = user_input[0];
    // Input Validation
        while(selection != '1' && selection != '2' && selection != '3' && selection != '4' && selection != '5' && selection != '6')
        {
            printf("\nInvalid Input.\n");
            printf("\nPlease select one of the options above(1-6): ");
            scanf("%s", &user_input);
            selection = user_input[0];
        }
    // Preform Action Selected by User
        switch(selection)
        {
            case '1':
               BitwiseOperation(binary_num1, binary_num2, 1);
               break;
            case '2':
               BitwiseOperation(binary_num1, binary_num2, 2);
               break;
            case '3':
               BitwiseOperation(binary_num1, binary_num2, 3);
               break;
            case '4':
               display_choice = 1;
               break;
            case '5':
               display_choice = 2;
               break;
        }
               
    }
// End of Program
    return 0;
}

void MenuDisplay(int num1, int num2, char *binary_num1, char *binary_num2, int display_choice)
{
// Display Menu with Integer Numbers
    if(display_choice == 1)
    {
        printf("\n1) AND\n");
        printf("2) OR\n");
        printf("3) XOR\n");
        printf("4) Integer\n");
        printf("5) Binary\n");
        printf("6) Exit\n");
        printf("7) %d\n", num1);
        printf("8) %d\n", num2);
    }
// Display Menu with Binary Numbers
    if(display_choice == 2)
    {
        printf("\n1) AND\n");
        printf("2) OR\n");
        printf("3) XOR\n");
        printf("4) Integer\n");
        printf("5) Binary\n");
        printf("6) Exit\n");
        printf("7) %s\n", binary_num1);
        printf("8) %s\n", binary_num2);
    }
}

char* IntToBinary(int num, int choice)
{
// Variable 
    int exp = -1;
    int exp_num = 0;
    int num2 = num;
    int num3 = num;
    int i = 0;
    char binary_num[100];
    char *result1;
    char *result2;
// Convert Int to Binary
    if(num == 0)
    {
        binary_num[0] = '0';
    }
    else if(num == 1)
    {
        binary_num[0] = '1';
    }
    else
    {
        while(num2 != 0)
        {
            num2 /= 2;
            exp++;
        }
        while(exp != -1)
        {
            exp_num = pow(2, exp);
            if(num3 - exp_num >= 0)
            {
                num3 -= exp_num;
                binary_num[i] = '1';
            }
            else
            {
                binary_num[i] = '0';
            }
            exp--;
            i++;
        }
    }
    i = 0;
    while(i < 100)
    {
        if(binary_num[i] != '0' && binary_num[i] != '1')
        {
            binary_num[i] = '\0';
        }
        i++;
    }
    if(choice == 1)
    {
        result1 = strdup(binary_num);
        return result1;
    }
    else
    {
        result2 = strdup(binary_num);
        return result2;
    }
}

void BitwiseOperation(char *num1, char *num2, int choice)
{
// Variables
    int size1 = 0;
    int size2 = 0;
    int smaller_size = 0;
    int difference = 0;
    int i = 0;
// Find Sizes
    while(num1[i] != '\0')
    {
        size1++;
        i++;
    }
    i = 0;
    while(num2[i] != '\0')
    {
        size2++;
        i++;
    }
    i = 0;
// Find Smaller Size
    if(size1 < size2)
    {
        smaller_size = size1;
        difference = size2 - size1;
    }
    else
    {
        smaller_size = size2;
        difference = size1 - size2;
    }
// Preform AND Bitwise Operation
    if(choice == 1)
    {
        printf("\nAND: ");
        if(size1 < size2)
        {
            while(i < smaller_size)
            {
                if(num1[i] == '1' && num2[(i + difference)] == '1')
                {
                    printf("1");
                }
                else
                {
                    printf("0");
                }
            i++;
           }
        }
        else
        {
            while(i < smaller_size)
            {
                if(num1[i + difference] == '1' && num2[i] == '1')
                {
                    printf("1");
                }
                else
                {
                    printf("0");
                }
            i++;
            }
        }
    }
// Preform OR Bitwise Operation
    if(choice == 2)
    {
        printf("\nOR: ");
        if(size1 < size2)
        {
            while(i < smaller_size)
            {
                if(num1[i] == '1' || num2[(i + difference)] == '1')
                {
                    printf("1");
                }
                else
                {
                    printf("0");
                }
                i++;
            }
        }
        else
        {
            while(i < smaller_size)
            {
                if(num1[i + difference] == '1' || num2[i] == '1')
                {
                    printf("1");
                }
                else
                {
                    printf("0");
                }
                i++;
            }
        }
    }
// Preform XOR Bitwise Operation
    if(choice == 3)
    {
        printf("\nXOR: ");
        if(size1 < size2)
        {
            while(i < smaller_size)
            {
                if((num1[i] == '1' && num2[i + difference] == '1') || (num1[i] == '0' && num2[i + difference] == '0'))
                {
                    printf("0");
                }
                else
                {
                    printf("1");
                } 
                i++;
            }
        }
        else
        {
            while(i < smaller_size)
            {
                if((num1[i + difference] == '1' && num2[i] == '1') || (num1[i + difference] == '0' && num2[i] == '0'))
                {
                    printf("0");
                }
                else
                {
                    printf("1");
                }
                i++;
            }  
        }
    }
    printf("\n");    
}
