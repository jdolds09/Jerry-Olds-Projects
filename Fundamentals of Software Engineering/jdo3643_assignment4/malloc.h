#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *_malloc(size_t size);

void _free(void *ptr);

void *_calloc(size_t nmemb, size_t size);

void *_realloc(void *ptr, size_t size);
