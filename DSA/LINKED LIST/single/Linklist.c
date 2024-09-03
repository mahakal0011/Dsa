#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*link;
};
struct node* head = NULL;
void create();
void print();
int main()
{
    int ch;
    printf("Main manu");
    while (1)
    {
        printf("Enter 1 for create");
        printf("Enter 2 for print");
    
    
    switch (ch)
    {
    case 1:create();/* constant-expression */
        /* code */
        break;
    case 2:print();
    break;
    
    default:
    printf("Thank You");
        break;
    }
}
}
void create()
{
    int i;
    struct node*head=NULL,*mk;
   
    for(i=0;i<5;i++)
    {
    mk=(struct node*)malloc(sizeof(struct node));
    printf("enter the value");
    scanf("%d",&mk->data);
    mk=mk->link;
    if(head==NULL)
    {
        mk->link=NULL;
       head= mk;
    
    }
    else{
        mk->link=head;
        head=mk;
    }
    }
}
void print()
{
    struct node*current=head;
    while (current!=NULL)
    {
        printf("%d",current->data);
        current=current->link;
        
    }
    
}