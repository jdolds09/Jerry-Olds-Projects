#include<stdio.h>
#include<string.h>

int main()
{
// Variables
    char name[6] = "JERRY";
    int women = 0;
    int men = 0;
    int rice_women2;
    int rice_men2;
    int total_rice2;
    int women_remainder;
    int men_remainder;
    int total_remainder;
    int i;
    double rice_women;
    double rice_men;
    double total_rice;

// Program Title
    printf("\n\tHOMEWORK 2\n");

// Output Name
    printf("\nName: %s\n", name);

// Calculate amount of women and men at wedding
    for(i = 0; i < 5; i++)
    {
        if(name[i] < 'M')
           women++;
        else
           men++;
    }

// Output amount of men and women at wedding
    printf("\nNumber of men at wedding: %3d\n", men);
    printf("Number of women at wedding: %d\n", women);

// Calculate how many grams of rice will be thrown
    rice_women = women * 1.2;
    rice_men = men * 2.4;
    total_rice = rice_women + rice_men;

// Output amount of rice needed to be purchased
    printf("\nAmount of rice needed: %4.1f\n", total_rice);
    printf("Amount thrown by men: %5.1f\n", rice_men);
    printf("Amount thrown by women: %.1f\n", rice_women);

// Calculate how many grams of rice will be thrown using integers
    rice_women2 = women;
    women_remainder = women * 2;
    rice_women2 += (women_remainder / 10);
    women_remainder %= 10;

    rice_men2 = men * 2;
    men_remainder = men * 4;
    rice_men2 += (men_remainder / 10);
    men_remainder %= 10;

    total_rice2 = rice_men2 + rice_women2;
    total_remainder = men_remainder + women_remainder;
    total_rice += (total_remainder / 10);
    total_remainder %= 10;

// Output amount of rice needed to be purchased
    printf("\nAmount of rice needed: %2d.%d\n",total_rice2, total_remainder);
    printf("Amount thrown by men: %3d.%d\n", rice_men2, men_remainder);
    printf("Amount thrown by women: %d.%d\n\n", rice_women2, women_remainder);

// End of program
    return 0;  
}
