#include<stdio.h>
#include<string.h>
#include<math.h>

// Structure
    struct info
    {
        int whole_num1;
        float dec_num1;
        int whole_num2;
        float dec_num2;
        char name[50];
    };

// Function Prototype
    void modify(struct info *s1);

int main(int argc, char *argv[])
{
// Initialize Values in Structure
    struct info obj = {50, 4.5, 265, 5.00005, "Jerry"};
// Varibales
    int num;
    int original_num;
    int exp = -1;
    int exp_num;
    int swap = 1;
    int length = sizeof(obj.name) / sizeof(obj.name[0]);
    int i;
    int remainder;
    int octal;
    char temp;
// Program Title
     printf("\n\t\tHomework 4\n"); 
// Call Modify Function
     modify(&obj);
// Output First Value
    printf("\n%d\t\t ", obj.whole_num1);
// Output First Value in Binary
    num = obj.whole_num1;
    original_num = num;
    if(num == 0)
    {
        printf("%d", num);
    }
    while(num != 0)
    {
        num /= 2;
        exp++;
    }
    while(exp != -1)
    {
        exp_num = pow(2, exp);
        if(original_num - exp_num >= 0)
        {
            original_num -= pow(2, exp);
            printf("1");
        }
        else
        {
            printf("0");
        }
        exp--;
    }
// Output Second Value
    printf("\n%.1f", obj.dec_num1);
    printf("\t\t %.1f", obj.dec_num1);
// Output Third Value
    printf("\n%s\t", obj.name);
// Output Third Value Sorted According to ASCII Table
    num = 0;
    for(i = 0; i < length; i++)
    {
        if(obj.name[i] != '\0')
        {
            num++;
        }
    }
    while(swap == 1)
    {
        swap = 0;
        for(i = 0; i < (num - 1); i++)
        {
            if(obj.name[i] > obj.name[i + 1])
            {
                temp = obj.name[i];
                obj.name[i] = obj.name[i + 1];
                obj.name[i + 1] = temp;
                if(swap == 0)
                {
                    swap = 1;
                }
            }
        }
    }
    printf("%s", obj.name);
// Output Fourth Value
    printf("\n%d\t\t ", obj.whole_num2);
// Output Fourth Value in Octal
    num = obj.whole_num2;
    original_num = num;
    exp = 0;
    while(num >= 8)
    {
       num /= 8;
       exp++;
    }
    while(exp > 0 && original_num >= 8)
    {
        exp_num = pow(8, exp);
        octal = original_num / exp_num;
        printf("%d", octal);
        original_num %= exp_num;
        exp--;
    }
    remainder = original_num;
    printf("%d", remainder);
// Output Fifth Value
    printf("\n%.1f\t\t ", obj.dec_num2);
// Output Fifth Value As Decimal
    num = (int)obj.dec_num2;
    printf("%d\n\n", num);

// End of Program
    return 0;
}

void modify(struct info *s1)
{
// Variables
    int inum1 = 0;
    int inum2 = 0;
    float fnum = 0.0;
    char last_name[50];
// Modify First Value
    printf("Please enter a value to be added to %d: ", s1->whole_num1);
    scanf("%d", &inum1);
    s1->whole_num1 += inum1;
// Modify Second Value
    printf("Please enter a value to be divided by %.1f: ", s1->dec_num1);
    scanf("%f", &fnum);
    s1->dec_num1 = fnum / s1->dec_num1;
// Modify Third Value
    printf("Hello %s, please enter your last name: ", s1->name);
    scanf(" %[^\n]%*c", last_name);
    strcat(s1->name, " ");
    strcat(s1->name, last_name);
// Modify Fourth Value
    printf("Please enter a value to be multiplied by %d: ", s1->whole_num2);
    scanf("%d", &inum2);
    s1->whole_num2 *= inum2;
// Modify Fifth Value
    s1->dec_num2 *= s1->dec_num1;  
}

