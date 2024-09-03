#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*prev;
    struct node*next;
    };
void insert(struct node*km,int data);
void print(struct node*mkv);
int main(){
    struct node*head=malloc(sizeof(struct node));
    head->data=12;
    head->prev=NULL;
    head->next=NULL;

    struct node*current=malloc(sizeof(struct node));
    current->data=56;
    current->prev=head;
    current->next=NULL;
    head->next=current;

    insert(head,53);
    print(head);

 
}
void insert(struct node*head,int data){
   
struct node*km=malloc(sizeof(struct node));
km->data=data;
km->prev=NULL;
km->next=NULL;
while (head->prev!=NULL)
{
  head=head->prev;  
}
head->prev=km;
}
void print(struct node*head){
    
        if(head==NULL){
            printf("The linked list is empty");
        }
        while (head!=NULL)
        {
            printf("%d",mkv->data);
            mkv=mkv->next;
        }
        
    }