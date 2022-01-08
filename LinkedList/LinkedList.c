// LinkedList
#include <stdio.h>
#include <stdlib.h>

#define print(str) printf("%s", str);
#define printInt(val) printf("%d ", val);

typedef struct LinkedList
{
	int data;
	struct LinkedList *next;
} Node;

int size = 0;
Node *head, *ptr;

void addNodeAtEnd(Node **, Node **);
void addNodeAtStart(Node **, Node **);
void addNodeAtMiddle(Node **, Node **);
void display();
void printDetails();
void choiceSelector();

int main(void)
{
	print("\t\tLinkedList\n");
	head = NULL;
	int input;
	do {
		fflush(stdin);
		ptr = (Node *)malloc(sizeof(Node));
		print("\nEnter a value for the node: ");
		scanf("%d", &ptr->data);
		ptr->next = NULL;

		choiceSelector();

		print("\nWant to continue? [1/0]: ");
		scanf("%d", &input);
	} while(input);
	printDetails();

	return 0;
}

void choiceSelector()
{
	int choice;
	print("\nHow\'d you like to insert the node?\n1. at the beginning\n2. in the middle\n3. at the end");
	print("\nEnter your choice (1/2/3): ");
	scanf("%d", &choice);
	switch(choice) {
		case 1:
			addNodeAtStart(&head, &ptr);
			break;
		case 2:
			addNodeAtMiddle(&head, &ptr);
			break;
		case 3:
			addNodeAtEnd(&head, &ptr);
			break;
		default:
			print("\nWrong Selection!!");
			choiceSelector();
			break;
	}
}

// Display nodes of the LinkedList
void display()
{
	if (size == 0)
	{
		print("\nList is empty.\n");
		return;
	}
	print("\nElements in the LinkedList: ");
	for (Node *temp = head; temp; temp = temp->next)
	{
		printInt(temp->data);
	}
}

// Display the details of the LinkedList
void printDetails()
{
	display();
	print("\nSize of the LinkedList is: ");
	printInt(size);
}

// Add node in the LinkedList
void addNodeAtEnd(Node **start, Node **node)
{
	size++;
	if ((*start) == NULL)
	{
		*start = *node;
	} else
	{
		Node *temp;
		for (temp = *start; temp->next != NULL; temp = temp->next);
		temp->next = *node;
	}
}
void addNodeAtStart(Node **start, Node **node)
{
	size++;
	if ((*start) == NULL)
	{
		*start = *node;
	} else
	{
		(*node)->next = *start;
		*start = *node;
	}
}

void addNodeAtMiddle(Node **start, Node **node)
{
	size++;
	if ((*start) == NULL)
	{
		*start = *node;
	} else
	{
		char choice;
		print("\nHow\'d you like to perform the operation? [V->value / P->position]: ");
		scanf(" %c", &choice);
		if (choice == 'P' || choice == 'p')
		{
			int pos;
			print("\nEnter the position (starting from 0): ");
			scanf("%d", &pos);
			if (pos > size || pos < 0)
			{
				print("\nYou entered position out of bound!!");
				size--;
				return;
			} else
			{
				if (pos == 0)
				{
					addNodeAtStart(&(*start), &(*node));
					return;
				}
				Node **temp = &head;
				for (int i = 1; temp && i < pos; ++i)
				{
					*temp = (*temp)->next;
				}
				if ((*temp)->next == NULL)
				{
					(*temp)->next = *node;
				} else
				{
					(*node)->next = (*temp)->next;
					(*temp)->next = *node;
					return;
				}
			}
		} else
		{
			int val;
			print("\nEnter the value: ");
			scanf("%d", &val);
			Node *temp;
			for (temp = head; temp->next != NULL && temp->data != val; temp = temp->next);
			if (temp->next == NULL)
			{
				temp->next = *node;
			} else
			{
				(*node)->next = temp->next;
				temp->next = *node;
			}
			return;
		}
	}
}
