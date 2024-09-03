#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*link;
};
void print();
int main()
{
    int i,n;
    struct node*temp,*head=NULL;
    printf("Enter your choice how many node you want to add");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter a value");
        scanf("%d",&temp->link);
        if(head==NULL)
        {
            temp->link=NULL;
            head=temp;

        }
        else
        {
            head->link=temp;
            temp->link=NULL;
            head=head->link;

        }
    }
    
print();
}
void print()
{
    struct node*head;
    while(head!=NULL)
    {
        printf("%d",head->data);
        head=head->link;
    }
}
