// Author: Jerry Olds
// ID: 1001533643
// CSE-2320-001
// Lab 1

// Command line to build: gcc jdo3643_Lab1.c -o lab1
// Command to run: lab1 [Insert input file name here]
// Example run command: lab1 input.txt

#include <stdio.h>
#include <stdlib.h>

// Structure
typedef struct myStruct
{
    int index;
    int count;
}Values;

// Function prototypes
    void counter_output(Values *val, int size);
    void index_output(int *map, Values *val, int size);
    void add_counter(int *map, Values *val, int size, FILE *fptr);
    void subtract_counter(int *map, Values *val, int size, FILE *fptr);
    void counters_between(Values *val, int size, FILE *fptr);

int main(int argc, char *argv[])
{
// Variables
    FILE *fptr;
    int *map;
    Values *val; 
    int array_size;
    int operation;
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

// Read value for size of arrays
    fscanf(fptr, "%d", &array_size);

// Allocate memory for arrays
    map = (int *)malloc(array_size * sizeof(int));
    val = (Values *)malloc(array_size * sizeof(Values));

// Initialize arrays
    for(i = 0; i < array_size; i++)
    {
        map[i] = i;
        val[i].index = i;
        val[i].count = 0;
    }

// Read first operation
    fscanf(fptr, "%d", &operation);

// Preform operations
    do
    {
    // Preform operation
        switch(operation)
        {
        // Output by index
            case 1:
                index_output(map, val, array_size);
                break;
        // Output by counter
            case 2:
                counter_output(val, array_size);
                break;
        // Add one to specific counter and sort
            case 3:
                add_counter(map, val, array_size, fptr);
                break;
        // Subtract one to specific counter and sort
            case 4:
                subtract_counter(map, val, array_size, fptr);
                break;
        // Display amount of counters in a given range
            case 5:
                counters_between(val, array_size, fptr);
                break;
        // Default case should never be used
            default:
                printf("\nSomething went horribly wrong!\n\n");
                return 1;
        }    
    
    // Read next operation
        fscanf(fptr, "%d", &operation);

    }while(operation != 0);

// Close file
    fclose(fptr);

// Free array memory
    free(map);
    free(val);

// End of program
    return 0;
}


void index_output(int *map, Values *val, int size)
{
// Variable
    int i;

// Output
    printf("\nprint by index\n");
    for(i = 0; i < size; i++)
        printf("%d %d\n", i, val[map[i]].count);
    printf("-----------\n");
}

void counter_output(Values *val, int size)
{
// Variable
    int i;

// Output
    printf("\nprint by count\n");
    for(i = 0; i < size; i++)
        printf("%d %d\n", val[i].index, val[i].count);
    printf("-----------\n");
}

void add_counter(int *map, Values *val, int size, FILE *fptr)
{
// Variables
    Values temp;
    int map_temp;
    int map_index;
    int map_swap;
    int i;
    int index_increase;
    int index_position;
    int last_occurrence;
    int low = 0;
    int high = size - 1;
    int mid;
    int swap = 0; // Boolean

// Read index of counter to be increased
    fscanf(fptr, "%d", &index_increase);

// Find index value
    for(i = 0; i < size; i++)
         if(val[i].index == index_increase)
              index_position = i;

// Swap if new count is more than succeeding count
    if(index_position != (size - 1) && (val[index_position].count == val[index_position + 1].count))
    {
    // Find first occurrence of preceeding count
        while(low <= high)
        {
            mid = (low + high) / 2;
            if(val[mid].count == val[index_position + 1].count)
            {
                last_occurrence = mid;
                low = mid + 1;
            }

            else if(val[index_position - 1].count < val[mid].count)
                high = mid - 1;

            else
                low = mid + 1;
        }

    // Swap
        map_index = val[index_position].index;
        map_swap = val[last_occurrence].index;
        map_temp = map[map_swap];
        map[map_swap] = map[map_index];
        map[map_index] = map_temp;
        temp = val[last_occurrence];
        val[last_occurrence] = val[index_position];
        val[index_position] = temp;
        swap = 1;
    }

// Increment counter
    if(swap == 1)
        val[last_occurrence].count++;
    else
        val[index_position].count++;
}

void subtract_counter(int *map, Values *val, int size, FILE *fptr)
{
// Variables
    Values temp;
    int map_temp;
    int i;
    int index_decrease;
    int index_position;
    int first_occurrence;
    int map_index;
    int map_swap;
    int low = 0;
    int high = size - 1;
    int mid;
    int swap = 0; // Boolean

// Read index of counter to be increased
    fscanf(fptr, "%d", &index_decrease);

// Find index value
    for(i = 0; i < size; i++)
         if(val[i].index == index_decrease)
              index_position = i;

// Swap if new count is less than preceeding count
    if(index_position != 0 && (val[index_position].count == val[index_position - 1].count))
    {
    // Find first occurrence of preceeding count
        low = 0;
        high = size - 1;
        while(low <= high)
        {
            mid = (low + high) / 2;

            if(val[mid].count == val[index_position - 1].count)
            {
                first_occurrence = mid;
                high = mid - 1;
            }

            else if(val[index_position - 1].count < val[mid].count)
                high = mid - 1;

            else
                low = mid + 1;
        }    

    // Swap
        map_index = val[index_position].index;
        map_swap = val[first_occurrence].index;
        map_temp = map[map_swap];
        map[map_swap] = map[map_index];
        map[map_index] = map_temp;
        temp = val[first_occurrence];
        val[first_occurrence] = val[index_position];
        val[index_position] = temp;
        swap = 1;
    }
   
// Decrement count
    if(swap == 1)
        val[first_occurrence].count--;
    else
        val[index_position].count--;
    
}

void counters_between(Values *val, int size, FILE *fptr)
{
// Variables
    int i;
    int lower_bound;
    int upper_bound;
    int result = 0;

// Read lower and higher bound
    fscanf(fptr, "%d%d", &lower_bound, &upper_bound);

// Find result
    for(i = 0; i < size; i++)
        if(val[i].count >= lower_bound && val[i].count <= upper_bound)
            result++;

// Output result
    printf("%d counters valued between %d and %d\n", result, lower_bound, upper_bound);
}
