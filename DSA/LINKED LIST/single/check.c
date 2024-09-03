// Single Linked_list
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
void create();
void ins_beg();
void ins_end();
void ins_pos();
void del_beg();
void del_end();
void del_pos();
void display();
void count();
void scearch();
struct node
{
    int info;
    struct node*next;
};
typedef struct node node;
node *head=NULL;
int main()
{
    int ch;
    printf("\n*********Main Menu*********\n          ---------\n");
    printf("1.Create For The Node.\n2.Insert In The Beging.\n3.Insert In The Last.\n4.Insert Any Position.\n5.Delet In The Beigning.\n6.Delet In Last.\n7.Delet Any position.\n8.Display.\n9.Count.\n10.Scearch A Value.\n11.Exit.\n");
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1: create();
            break;
            case 2: ins_beg();
            break;
            case 3: ins_end();
            break;
            case 4: ins_pos();
            break;
            case 5: del_beg();
            break;
            case 6: del_end();
            break;
            case 7: del_pos();
            break;
            case 8:display();
            break;
            case 9:count();
            break;
            case 10:scearch();
            break;
            case 11:printf("Exit from loop");
            break;
            default :printf("Wrong Choise!");
        }
    }while(ch!=11);
    return 0;
}
void create()
{
    int val,i,n;
    struct node *tmp,*q;
    printf("How Many Node You Want To Create:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        tmp=(struct node*) malloc(sizeof(struct node));
        printf("Enter A Value:");
        scanf("%d",&val);
        tmp->info=val;
        tmp->next=NULL;
        if (head==NULL)
        {
            head=tmp;
            tmp->next=NULL;
            q=head;
        }
        else
        {
            q->next=tmp;
            tmp->next=NULL;
            q=q->next;
        }
    }
}
void ins_beg()
{
    node *q=head,*tmp;
    int val;
    tmp=(struct node*) malloc(sizeof(struct node));
    printf("Enter A Value: ");
    scanf("%d", &val);
    tmp->info=val; 
    tmp->next=q->next;
    head=tmp;
}
void ins_end()
{
    node *tmp,*q=head;
    int val; 
    tmp=(struct node*) malloc(sizeof(struct node));
    printf("Enter A Value: ");
    scanf("%d",&val); 
    tmp->info=val;
    tmp->next=NULL;
    while(q->next!=NULL)
    {
        q=q->next;
    }
    q->next=tmp;
}
void ins_pos()
{
    node*tmp,*q=head;
    int i,val,pos;
    tmp=(struct node*) malloc(sizeof(struct node));
    printf("Enter A Value: ");
    scanf("%d",&val);
    tmp->info=val;
    // tmp->next=NULL;
    printf("Enter The Index Where You Want To Add Value: ");
    scanf("%d",&pos);
    for(i=1;i<=pos-2;i++)
    {
        q=q->next;
    }
    tmp->next=q->next;
    q->next=tmp;
}
void del_beg()
{
    node*q=head;
    if(head==NULL)
    {
        printf("No List Exit!!");
        exit(0);
    }
    head=q->next;
    free(q);
}
void del_end()
{
    node*q=head,*tmp;
    if(head==NULL)
    {
        printf("No List Exit!!");
        exit(0);
    }
    while (q->next->next!=NULL)
    {
        q=q->next;
    }
    tmp=q->next;
    free(tmp);
    q->next=NULL;
}
void del_pos()
{
    node*q=head,*tmp;
    int i,pos;
    if(head==NULL)
    {
        printf("No List Exit!!");
        exit(0);
    }
    printf("Enter A Position Where You Want To Delet: ");
    scanf("%d",&pos);
    for(i=1;i<=pos-2;i++)
    {
        q=q->next;
    }
    tmp=q->next;
    q->next=tmp->next;
    free(tmp);
}
void display()
{
    if(head==NULL)
    {
        printf("Nothing To Be Display!!");
        // exit(0);
    }
    node*q=head;
    while(q!=NULL)
    {
        printf("%d\t",q->info);
        q=q->next;
    }
}
void count()
{
    node*q=head;
    int count=0;
    if(head==NULL)
    {
        printf("Nothing To Be Display!!");
        // exit(0);
    }
    else
    {
        while (q!=NULL)
        {
            count++;
            q=q->next;
        }
        printf("%d\n",count);
    }
}
void scearch()
{
    node*q=head;
    int sv;
    if(head==NULL)
    {
        printf("Nothing To Be Display!!");
        exit(0);
    }
    printf("Enter A Scearch Value: ");
    scanf("%d",&sv);
    
    {
        while (q!=NULL)
        {
            if (q->info==sv)
            {
                printf("Scearch Succefull.\n");
                break;
            }
            q=q->next;
        }
        if (q==NULL)
        {
            printf("Scearch Un-Succefull!!\n");
        }
    }
}