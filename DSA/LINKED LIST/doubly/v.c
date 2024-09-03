// Doubly linked list
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
    struct node*prev,*next;
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
    node*tmp,*q=head;
    int i,n,val;
    printf("Enter The No of Nodes You Want To Create.");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        tmp=(node*)malloc(sizeof(node));
        printf("Enter A Value: ");
        scanf("%d",&val);
        tmp->info=val;
        tmp->next=NULL;
        if(head==NULL)
        {
            tmp->prev;
            head=tmp;
            q=head;
        }
        else
        {
            tmp->prev=q;
            q->next=tmp;
            q=q->next;
        }
    }
}
void ins_beg()
{
    node*tmp,*q=head;
    int val;
    if(head==NULL)
    {
        printf("No List Created!!");
        exit(0);
    }
    printf("Enter A Value: ");
    scanf("%d",&val);
    tmp=(node*)malloc(sizeof(node));
    tmp->info=val;
    tmp->prev=NULL;
    tmp->next=q;
    q->prev=tmp;
    head=tmp;
}
void ins_end()
{
    node*tmp,*q=head;
    int val;
    if(head==NULL)
    {
        printf("No List Created!!");
        exit(0);
    }
    while(q->next!=NULL)
    {
        q=q->next;
    }
    tmp=(node*)malloc(sizeof(node));
    printf("Enter A Value: ");
    scanf("%d",&val);
    tmp->info=val;
    tmp->next=NULL;
    tmp->prev=q;
    q->next=tmp;
}
void ins_pos()
{
    node*tmp,*q=head;
    int val,pos,i;
    if(head==NULL)
    {
        printf("No List Created!!");
        exit(0);
    }
    printf("Enter Where You Want To Add: ");
    scanf("%d",&pos);
    for(i=1;i<=pos-1;i++)
    {
        q=q->next;
    }
    tmp=(node*)malloc(sizeof(node));
    printf("Enter A Value To A: ");
    scanf("%d",&pos);
    tmp->info=val;
    tmp->prev=q;
    tmp->prev=q->next;
    tmp->next->prev=tmp;
    q->next=tmp;
}
void del_beg()
{
    node*q=head,*tmp;
    int val;
    if (head==NULL)
    {
        printf("No list Exits!!");
        exit(0);
    }
    else
    {
        head=q->next;
        q->next->prev=NULL;
        free(q);
    }
}
void del_end()
{
    node*q=head,*tmp;
    if(head==NULL)
    {
        printf("No list Exits!!");
        exit(0);
    }
    else
    {
        while(q->next->next!=NULL)
        {
            q=q->next;
        }
    }
    tmp=q->next;
    free(tmp);
    q->next=NULL;
}
void del_pos()
{
    node*tmp,*q=head;
    int pos,i;
    if (head==NULL)
    {
        printf("No list exits!!");
        exit(0);
    }
    else
    {
        printf("Enter The Number Where you want to delet the value:");
        scanf("%d",&pos);
        while (i<=pos-2)
        {
            q=q->next;
            i++;
        }
        tmp=q->next;
        q->next=tmp->next;
        tmp->next->prev=tmp;
        free(tmp);
    }
}
void display()
{
    if(head==NULL)
    {
        printf("Nothing To Be Display!!");
        exit(0);
    }
    node*q=head;
    while(q!=NULL)
    {
        printf("%d\t",q->info);
        q=q->next;
    }
}
void scearch()
{
    node*q=head;
    int val,pos=0;
    if (head==NULL)
    {
        printf("No list Exits!!");
        exit(0);
    }
    else
    {
        printf("Enter The value to scearch:");
        scanf("%d",&val);
        while (q->info!=val)
        {
            q=q->next;
            pos++;
        }
        printf("Scearch Succfull.");
        printf("The element fond in: %d");
    }
}
void count()
{
    int count=0;
    node*q=head;
    if(head==NULL)
    {
        printf("No list exits!!");
        exit(0);
    }
    else
    {
        while (q!=NULL)
        {
            q=q->next;
            count++;
        }
        printf("%d Nodes found in this linked list",count);
    }
}