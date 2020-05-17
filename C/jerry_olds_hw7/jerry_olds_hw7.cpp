#include<stdio.h>
#include<string.h>

// Linked List
typedef struct listnode
{
	char *pointer;
	struct listnode *next;
}Node;

// Function Prototypes
void push(char *data, Node** head, Node* tail);
void sort(char *data, Node* tail);

int main(int argc, char *argv[])
{
	// Variables
	FILE fptr;
	Node** head = NULL;
	Node* tail;
	char *user_input;
	char *data;
	char ch = '\0';
	int i = 0;
	int file = 1;
	// Program Title
	printf("\tHomework 7\n\n");
	if (argc == 1)
	{
		// End Program if There are no Files Entered
		printf("\nPlease enter at least 1 file.\n\n");
		return 0;
	}
	if (argc == 2)
	{
		// Have User Enter a String if Only 1 File is Entered 
		printf("Only one file has been entered. Please enter a string: ");
		while (ch != '\n')
		{
			ch = getchar();
			user_input = (char *)realloc(sizeof(char) * (i + 1));
			user_input[i] = ch;
			i++;
		}
		user_input[i] = '\0';
		// Open File
		fptr = fopen(argv[2], "r");
		i = 0;
		while (ch != NULL)
		{
			fscanf(fptr, "%c", ch);
			data = (char *)realloc(sizeof(char) * (i + 1));
			data[i] = ch;
			if (ch == ' ')
			{
				data[i] = '\0';
				push(data, head, tail);
			}
			i++;
		}
		// Send User Input to Linked List
		push(user_input, head, tail);
		// Close File
		fclose(fptr);
		// Free Memory
		free(user_input);
		free(data);
	}
	else
	{
		// Open File
		fptr = fopen(argv[2], "r");
		i = 0;
		// Read Data in to Linked List
		while (ch != NULL)
		{
			fscanf(fptr, "%c", ch);
			data = (char *)realloc(sizeof(char) * (i + 1));
			data[i] = ch;
			if (ch == ' ')
			{
				data[i] = '\0';
				push(data, head, tail);
			}
			i++;
		}
		// Close File
		fclose(fptr);
		// Open File
		fptr = fopen(argv[3], "r");
		i = 0;
		// Read Data in to Linked List
		while (ch != NULL)
		{
			fscanf(fptr, "%c", ch);
			data = (char *)realloc(sizeof(char) * (i + 1));
			data[i] = ch;
			if (ch == ' ')
			{
				data[i] = '\0';
				push(data, head, tail);
			}
			i++;
		}
	}
	return 0;
}

void push(char *data, Node** head, Node* tail)
{
	// Variables
	Node* new_node = (Node *)malloc(sizeof(Node));
	// Put Data in List
	new_node->pointer = data;
	if (*head == NULL)
	{
		*head = new_node;
		new_node->next = NULL;
	}
	else
	{
		new_node->next = *head;
		*head = new_node;
		tail = new_node;
	}
	sort(data, tail);
}

void sort(char *data, Node* tail)
{
	// Variables
	int swap;
	char *temp;
	Node *ptr1;
	Node *last_ptr = NULL;
	// Swap
	do
	{
		swap = 0;
		ptr1 = tail;
		while (ptr1->next != last_ptr)
		{
			if (ptr1->pointer > ptr1->next->pointer)
			{
				temp = ptr1->pointer;
				ptr1->pointer = ptr1->next->pointer;
				ptr1->next->pointer = temp;
				swap = 1;
			}
			ptr1 = ptr1->next;
		}
	} while (swap);
}