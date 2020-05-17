#ifndef JERRY_OLDS_HW7_H_
#define JERRY_OLDS_HW7_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Linked List
typedef struct listnode
{
    char *data;
    struct listnode *next;
}Node;

//Function Prototypes
void insert(Node **head, char *word);
void sort(Node **head);
void display(Node **head);

void insert(Node **head, char *word)
{
// Create New Node
    Node *new_node = (Node *)malloc(sizeof(Node));
// Insert
    new_node->data = strdup(word);
    new_node->next = NULL;
    if(head == NULL)
    {
        *head = new_node;
    }
    else
    {
        new_node->next = *head;
        *head = new_node;
    }
}

void sort(Node **head)
{
// Variables
    Node *ptr1;
    Node *last_ptr = NULL;
    int swapped = 0;
    int i = 0;
    char *word1;
    char *word2;
    char *temp;
// Sort
    do
    {
        swapped = 0;
        ptr1 = *head;
        while(ptr1->next != last_ptr)
        {
            word1 = ptr1->data;
            word2 = ptr1->next->data;
            if(strcmp(word1, word2) > 0)
            {
                temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        last_ptr = ptr1;
    }while(swapped);
}

void display(Node **head)
{
// Variables
    Node *new_node;
    new_node = *head;
    int position = 1;
// Display
    while(new_node != NULL)
    {
        printf("%d.\t%s\n", position, new_node->data);
        new_node = new_node->next;
        position++;
    }
    printf("\n\n");
}

#endif
