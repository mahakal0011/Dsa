#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node*link;
}node;
struct node*head=NULL;
 void create();
 void print();
int main()
{ 
    int ch,i;
    printf("Main Manu...\n");
    printf("1 for create .....\n 5 for print...\n");
    printf("What can you do");
    scanf("%d",&ch);
    while (1)
    {
        switch (ch)
        {
        case 1: create();
            break;
        case 2:
        break;
        case 3:
        break;
        case 4:
        break;
        case 5:print();
        break;

        default:printf("Thank you...\n");
        exit(0);
            break;
        }
        /* code */
    }
    
}
void create()
{
    int i,n;
    struct node*p=head,*t;
    printf("How many node you want to ceeate...\n");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        t=malloc(sizeof(struct node));
        printf("What value you want to create");
        scanf("%d",&t->data);
        t->link=head;
        head=t;
    }
}
void print()
{
    struct node*k=head;
    if(head==NULL)
    {
        printf("The code is empty ...\n");
        exit(0);
    }
    while(head!=NULL)
    {
        printf("%d",&k->data);
        k=k->link;
    }
}