#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*link;
};
void insert_anode(struct node* head, int data);
int main()
{
    struct node*head=malloc(sizeof(struct node));
    head->data=56;
    head->link=NULL;

    struct node*mak=malloc(sizeof(struct node));
    mak->data=63;
    mak->link=NULL;
    head->link=mak;

    struct node*nak=malloc(sizeof(struct node));
    nak->data=23;
    nak->link=NULL;
    mak->link=nak;

    insert_anode(head,67);

    struct node*current=head;
    while(current!=NULL)
    {
        printf("%d\n",current->data);
        current=current->link;
    }
    return 0;

}
void insert_anode(struct node*head,int data)
{
    struct node*ptr,*temp;
    ptr=head;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;

    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;
    
}