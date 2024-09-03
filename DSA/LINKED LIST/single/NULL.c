#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*link;
};
void create();

void print();
struct node*head=NULL; //decleard head as a gloabal variable

int main()
{
    int ch;
    printf("...Hi This is the main manue...\n");
    printf("What do you want....\n 1 for create..\n 2 for print..\n");
    while (1)
    {
        printf("Enter what do you want\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:create();
        break;
        case 2:print();
        break;
    
        
        default:
                printf("...Thank you...\n");
                return 0;
        }
        
    }
    

}
void create()
{
    int i,n;
    struct node*tmp;
    printf("How many node you want to create\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        tmp=malloc(sizeof(struct node));
        printf("enter a value\n");
        scanf("%d",&tmp->data);
        tmp->link=head; // Update the link to point to the current head
        head=tmp;// Update head to the new node
    }



}
void print()
{
    struct node*current=head;
 if(current==NULL)
 {
    printf("There are no linked list\n");
    exit(0);
 }
 while(current!=NULL)
 {
    printf("  %d  ",current->data);
    current=current->link;
 }

}