#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*link;
};
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

    print_data(head);

}
void print_data(struct node*head)
{
    if(head==NULL){
        printf("The linked list is empty");
        exit(0);
    }
    struct node*ptr=NULL;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d",ptr->data);
        ptr=ptr->link;
    }
}