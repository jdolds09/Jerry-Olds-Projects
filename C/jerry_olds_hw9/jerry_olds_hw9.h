#ifndef JERRY_OLDS_HW9_H_
#define JERRY_OLDS_HW9_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Linked List
typedef struct listnode
{
    char *data;
    int position;
    int value;
    struct listnode *next;
}Node;

//Function Prototypes
void append(Node **head, char *numbers, int entry, int hash);
void displayList(Node **head, int num);

void append(Node **head, char *numbers, int entry, int hash)
{
// Create Node
    Node *new_node = (Node *)malloc(sizeof(Node));
    Node *last = *head; 
// Assign Values
    new_node->data = strdup(numbers);
    new_node->position = entry;
    new_node->value = hash;
    new_node->next = NULL;
    if(*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        while(last->next != NULL)
        {
            last = last->next;
        }
        last->next = new_node;
    }
}

void display(Node **head, int num)
{
// Variables
    Node *new_node;
    new_node = *head;
// Display
    if(new_node == NULL)
    {
        printf("Linked list for hash value %d was not created\n\n", num);
    }
    while(new_node != NULL)
    {
        printf("Data: %s\n", new_node->data);
        printf("Entry: %d\n", new_node->position);
        printf("Hashed Value: %d\n\n", new_node->value);
        new_node = new_node->next;  
    }
}

#endif
