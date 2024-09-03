#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*prev;
    struct node*next;
};
void insert_a_node(struct node*mnv,int data);
int main()
{
    struct node*head=malloc(sizeof(struct node));
    head->data=56;
    head->next=NULL;
    head->prev=NULL;

    struct node*current=malloc(sizeof(struct node));
    current->data=63;
    current->next=NULL;
    current->prev=head;
    head->next=current;
 insert_a_node(head,52);
    struct node*mkv=head;
    while(mkv!=NULL){
        printf("%d\n",mkv->data);
        mkv=mkv->next;
    }
}
void insert_a_node(struct node*head,int data){
    struct node*ptr,*mnv;
    ptr=head;
    mnv=(struct node*)malloc(sizeof(struct node));
    mnv->data=data;
    mnv->prev=NULL;
    mnv->next=NULL;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    }

