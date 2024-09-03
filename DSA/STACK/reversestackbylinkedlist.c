#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* link;
};

struct node* top = NULL; // Declare top globally

void push(int data);
int pop();
void reverseStack();
void print();

int main()
{
    int choice, data;

    while (1)
    {
        printf("Main Menu\n");
        printf("1. Push\n");
        printf("2. Reverse Stack\n");
        printf("3 for print...\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                reverseStack();
                printf("Stack reversed.\n");
                break;
            case 3:print();
            break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

void push(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed. Exiting.\n");
        exit(1);
    }
    newnode->data = data;
    newnode->link = top;
    top = newnode;
}

int pop()
{
    if (top == NULL)
    {
        printf("Stack is empty.\n");
        return -1; // Return a sentinel value to indicate an empty stack
    }

    struct node* temp = top;
    int data = temp->data;
    top = temp->link;
    free(temp);
    return data;
}

void reverseStack()
{
    struct node* tempStack = NULL;

    while (top != NULL)
    {
        int data = pop();
        push(data);
    }

    top = tempStack;
}
void print()
{
    struct node*cu=top;
    if(cu==NULL)
    {
        printf("Code is empty\n");
        exit(0);
    }
    else
    {
        printf("%d",cu->data);
        cu=cu->link;
    }
}