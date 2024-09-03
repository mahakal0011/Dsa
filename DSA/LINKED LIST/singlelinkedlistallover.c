#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*link;
};
void create();
void insert_end();
void insert_beg();
void print();
void insert_any();
void delete();
void delete_end();
struct node*head=NULL; //decleard head as a gloabal variable

int main()
{
    int ch;
    printf("...Hi This is the main manue...\n");
    printf("What do you want....\n 1 for create..\n 2 for print..\n 3 for insert at end...\n 4 for insert in begain\n  ");
    printf("5 for insert in any position..\n 6 for exit..\n");
    while (1)
    {
        printf("\n Enter what do you want.. \n ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:create();
        break;
        case 2:print();
        break;
        case 3:insert_end();
        break;
        case 4:insert_beg();
        break;
        case 5:insert_any();
        break;
        case 6:delete();
        break;
        case 7:delete_end();
        break;      
        case 8:printf("...Thank You...\n"); exit(0);
        
        default:
                printf("...Thank you...\n");
                return 0;
        }
        
    }
    

}
void create()
{
    int i,n;
    struct node*tmp,*q;
    printf("How many node you want to create\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        tmp=malloc(sizeof(struct node));
        printf("enter a value\n");
        scanf("%d",&tmp->data);
        tmp->link=NULL;
        if(head==NULL)
        {
            head=tmp;
            
        }
        else
        {
            while(head->link!=NULL)
            {
                head=head->link;
            }
            head->link=tmp;
        }
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
void insert_end()
{
    struct node*mk=head,*kl;
    kl=malloc(sizeof(struct node));
    printf("Enter which value you want to add\n");
    scanf("%d",&kl->data);
    kl->link=NULL;
    if(mk->link==NULL)
    {
      head=kl; 
      
    }
    else{
        mk=head;
        while (mk->link!=NULL)
        {
           mk=mk->link;
        }
        mk->link=kl;
        
    }
}
void insert_beg()
{
    struct node*hg=head,*temp;
    temp=malloc(sizeof(struct node));
    printf("Wbat you want into begain:\n");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(hg==NULL)
    {
        head=temp;
    }
    else{
        temp->link=hg;
        head=temp;
    }
}
void insert_any()
{
    int pos,i;
    struct node*nk=head,*kj;
    kj=malloc(sizeof(struct node));
    printf("Enter a new value\n");
    scanf("%d",&kj->data);
    kj->link=NULL;
    if(head==NULL)
    {
        head=kj;
    }
    else{
    printf("Enter where you want to add\n");
    scanf("%d",&pos);

        for(i=1;i<=pos-1;i++)
        {
          nk=nk->link;
        }
        kj->link=nk->link;
    }
}
void delete()
{
    struct node*ui=head;
    if(head==NULL)
    {
        return;
    }
    else
    {
       head=head->link;
       free(ui);
    }
}
void delete_end()
{
    struct node*pre=head,*ty;
    ty=pre->link;
    if(pre==NULL)
    {
        printf("Here no any node to delete...\n");
        return;
    }
   while (ty==NULL)
   {
     pre=pre->link;
    /* code */
   }
   pre->link=NULL;
   free(ty);
}