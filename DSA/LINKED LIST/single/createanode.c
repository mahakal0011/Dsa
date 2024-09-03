#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node*link;
};
int main()
{
    int i,n;
    struct node*head=NULL,*temp;
    printf("Enter how many node you want to create\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        temp=malloc(sizeof(struct node));
        printf("Which valu\n");
        scanf("%d",&temp->data);
        temp->link=head;
        head=temp;
    }
    struct node*ptr=head;
    while (ptr!=NULL)
    {
        printf("%d",ptr->data);
        ptr=ptr->link;
        /* code */
    }
    
}