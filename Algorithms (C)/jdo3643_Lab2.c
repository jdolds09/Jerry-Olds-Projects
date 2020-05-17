// Jerry Olds
// 1001533643
// CSE-2320-001
// Lab 2

// Command line to build: gcc jdo3643_Lab2.c -o lab2
// Command line to run: lab2 [Insert file]
// Example run command: lab2 in.dat

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definitions
    typedef char *Item;
    #define key(A) (A)
    #define greater(A, B) (key(A) > key(B))
    #define exch(A, B) {Item t = A; A = B; B = t; }
    #define compexch(A, B) if (greater(B, A)) exch(A,B)

// Function prototypes
    int parent(int i); 
    int left(int i); 
    int right(int i); 
    void minHeapify(char **a, int k, int N);
    void PQheapsort(char **a, int ell, int r);
    void printArray(char **a, int size);

int main(int argc, char *argv[])
{
// Variables
    FILE *fptr;
    FILE **fptrs;
    char **files;
    char file_name[256];
    char **entries;
    char entry[256];
    char **min_heap;
    char previous[50];
    int *file_end;
    int null_counter = 0;
    int num_entries;
    int num_files;
    int index = 0;
    int count = 0;
    int i;
    int j;

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

// Read in number of files
    fscanf(fptr, "%d", &num_files);

// Dynamically allocate arrays
    files = (char **)malloc(num_files * sizeof(char *));
    entries = (char **)malloc(num_files * sizeof(char *));
    fptrs = (FILE **)malloc(num_files * sizeof(FILE *));
    file_end = (int *)malloc(num_files * sizeof(int *));
    min_heap = (char **)malloc(256 * sizeof(char *));
 
    for(i = 0; i < num_files; i++)
    {
        fscanf(fptr, "%s", &file_name);
        files[i] = (char *)malloc(sizeof(file_name) + 1);
        strcpy(files[i], file_name);
    } 

// Close file
    fclose(fptr);

// Open files
    for(i = 0; i < num_files; i++)
    {
        fptrs[i] = (FILE *)malloc(sizeof(files[i]));
        fptrs[i] = fopen(files[i], "r");
    }

// Read contents of each file and create minHeap
    while(null_counter != num_files)
    {
        memset(&entries[0], 0, sizeof(entries));
        num_entries = 0;
        j = 0;
        
        for(i = 0; i < num_files; i++)
        {
            if(file_end[i] != 1)
            {
                fscanf(fptrs[i], "%s", &entry);
                if(entry[0] == '\0' || (i == 0 && strcmp(entry, "w") == 0))
                {
                    null_counter++;
                    file_end[i] = 1;
                }
                
                else
                {
                    index++;
                    num_entries++;
                    while(entries[i - 1] == NULL)
                    {
                        i--;
                        count++;
                    }
                    entries[i] = (char *)malloc(sizeof(entry));
                    strcpy(entries[i], entry);
                    i += count;
                    count = 0;                }
            }
            memset(&entry[0], 0, sizeof(entry));
        }
        
        if(num_entries != 0)
        {
            for(i = num_entries; i != 0; i--)
            {
                strcpy(entry, entries[j]);
                min_heap[(index + 1) - i] = (char *)malloc(sizeof(entry));
                strcpy(min_heap[(index + 1) - i], entry);
                j++;
            }
            PQheapsort(min_heap, 0, index);
        }
   
    }

// Print array
    printArray(min_heap, index);

// Close files
    for(i = 0; i < num_files; i++)
        fclose(fptrs[i]);

// Free memory
    free(files);
    free(entries);
    free(fptrs);
    free(file_end);
    free(min_heap);

// End of program
    return 0;
}

int parent(int i)
{
    return (i / 2);
}

int left(int i)
{
    return (2 * i);
}

int right(int i)
{
    return (2 * i + 1);
} 

void minHeapify(char **a, int k, int N)
{
// Variable
    int j;

// Create minHeap
    while(left(k) <= N)
    {
        j = left(k);
        if (j < N && greater(a[j], a[j + 1]))
            j = right(k);
        if(!greater(a[k], a[j]))
            break;
        exch(a[k], a[j]);
        k = j;
    }
}

#define pq(A) a[r-1 + A]

void PQheapsort(char **a, int ell, int r)
{
// Variables
    int i;
    int j = 0;
    int k;
    int N = r - ell + 1;

// Convert sub-array to minHeap
    for(k = parent(N); k >= 1; k--)
        minHeapify(&pq(0), k, N);

// Sort
    while(N > 1)
    {
        exch(a[1], a[N]);
        N--;
        minHeapify(&pq(0), 1, N);
    }

}

void printArray(char **a, int size)
{
// Variable
    int i;
    int counter = 1;

// Print array
    for(i = 1; i < size; i++)
    {
        if(a[i - 1] == a[i])
            counter++;
        else
        {
            printf("%s %d\n", a[i]);
            counter = 1;
        }
    } 
}
