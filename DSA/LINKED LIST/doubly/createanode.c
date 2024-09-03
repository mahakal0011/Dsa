#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert();
void print();
void insert_beg();
void insert_end();
void insert_any();
int delete_beg();
int main()
{
    int ch;
    printf(">>>>Main Menu<<<<\n");
    while (1)
    {
        printf("1=insert>>>\n2=print>>>\n3=insert_begaining>>>\n4=Insert_end>>>\n");
        printf("What do You want to do....\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            print();
            break;
        case 3:
            insert_beg();
            break;
        case 4:insert_end();
            break;
        case 5:insert_any();
        break;
        case 6:delete_beg();
        break;
        case 7:exit(0);
        default:
            printf("Wrong choice...\n");
            exit(0);
            break;
        }
    }
}

void insert()
{
    int i, m;
    printf("How many nodes you want to create..\n");
    scanf("%d", &m);
    
    for (i = 0; i < m; i++) {
        struct node *temp;
        temp = (struct node *)malloc(sizeof(struct node));
        
        if (temp == NULL) {
            printf("Memory allocation failed");
            return;
        }
        
        printf("Enter a value....\n");
        scanf("%d", &temp->data);
        temp->prev = NULL;
        temp->next = NULL;
        
        if (head == NULL) {
            head = temp;
        } else {
            struct node *current = head;
            
            while (current->next != NULL) {
                current = current->next;
            }
            
            current->next = temp;
            temp->prev = current;
        }
    }
}

void print()
{
    if (head == NULL)
    {
        printf("Nothing To Be Display!!");
        return;
    }
    
    struct node *q = head;
    
    while (q != NULL)
    {
        printf("%d\t", q->data);
        q = q->next;
    }
    printf("\n");
}

void insert_beg()
{
    struct node*ptr=head,*mp;
    mp=malloc(sizeof(struct node));
    printf("Enter what value you want to add at begaining..\n");
    scanf("%d",&mp->data);
    mp->prev=NULL;
    mp->next=NULL;
    if(head==NULL)
    {
        head=mp;
    }
    else{
        head->prev=mp;
        mp->next=head;
        head=mp;

    }

}
void insert_end()
{
    struct node*hjk;
    hjk=malloc(sizeof(struct node));
    printf("What do want to insert in end::::::\n");
    scanf("%d",&hjk->data);
    hjk->prev=NULL;
    hjk->next=NULL;
    if(head==NULL)
    {
        printf("No any linked list......\n ");
        exit(0);
    }
    else
    {
        struct node*curr=head;
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next=hjk;
        hjk->prev=curr;
    }
}
void insert_any()
{
    int n,i;
    struct node*b;
    b=malloc(sizeof(struct node));
    printf("Value");
    scanf("%d",&b->data);
    b->next=NULL;
    b->prev=NULL;
    if(head==NULL)
    {
        
        head=b;

    }
    else
    {
        printf("Which position you want to add..\n");
        scanf("%d",&n);
        for(i=1;i<n;i++)
        {
            head=head->next;
        }
        b->next=head->next;
        head->next=b;
        b->prev=head;
    }

}
int delete_beg()
{
    if(head==NULL)
    {
        printf("Their are no llinked list..\n");

    }
    else
    {
        struct node*current=head;
        head=current->next;
        current->next->prev=NULL;
        free(current);
    }

}