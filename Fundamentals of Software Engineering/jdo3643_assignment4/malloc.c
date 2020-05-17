#include "malloc.h"

// the big cheat
static char X[1048576];

void *_malloc(size_t size)
{
// Variables
    short free = 0; // Boolean variable
    int free_contiguous = 0;
    int position = 0;
    int i;

// Search for free memory
    for(i = 0; i < sizeof(X); i++)
    {
        if (X[i] == '\0')
        {
            if(!(i > 0 && X[i - 1] != '\0'))
        	    free_contiguous++;
        }
        else
            free_contiguous = 0;

        if(free_contiguous == size)
        {
            position = i - (size - 1);
            free = 1;
            break;
        }
    }

// If memory cannot be allocated
    if(free == 0)
    {
        printf("Error: No contiguous memory available for malloc request.\n");
        exit(EXIT_FAILURE);
    }

    return &X + position;
}

void _free(void *ptr)
{
   memset(ptr, '\0', sizeof(*ptr));
}

void *_calloc(size_t nmemb, size_t size)
{
// Variables
    short free = 0; // Boolean variable
    int free_contiguous = 0;
    int position = 0;
    int i;

// Search for free memory
    for(i = 0; i < sizeof(X); i++)
    {
        if (X[i] == '\0')
        {
            if(!(i > 0 && X[i - 1] != '\0'))
        	    free_contiguous++;
        }
        else
            free_contiguous = 0;

        if(free_contiguous == size * nmemb)
        {
            position = i - (size - 1);
            free = 1;
            break;
        }
    }

// If memory cannot be allocated
    if(free == 0)
    {
        printf("Error: No contiguous memory available for malloc request.\n");
        exit(EXIT_FAILURE);
    }

    return &X + position;
}

void *_realloc(void *ptr, size_t size)
{
// Variables
    short free = 0; // Boolean variable
    int free_contiguous = 0;
    int position = 0;
    int i;

// Free pointer before resizing
    _free(ptr);

// Search for free memory
    for(i = 0; i < sizeof(X); i++)
    {
        if (X[i] == '\0')
        {
            if(!(i > 0 && X[i - 1] != '\0'))
        	    free_contiguous++;
        }
        else
            free_contiguous = 0;

        if(free_contiguous == size)
        {
            position = i - (size - 1);
            free = 1;
            break;
        }
    }

// If memory cannot be allocated
    if(free == 0)
    {
        printf("Error: No contiguous memory available for malloc request.\n");
        exit(EXIT_FAILURE);
    }

    return &X + position;
}
