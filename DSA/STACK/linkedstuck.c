#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*link;
} *top=NULL;

void push(int data);
void print();
int pop();
int empty();
int peek();
int main()
{
    int ch,data;
    printf("Main manue...\n");
    printf("1 for push..... \n2 for print.....\n3 for pop.....\n4 for empty....\n5 for peek...\n 6 for EXIT....\n");
    while (1)
    {
        printf("Enter what do you want.....\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:printf("Which value you want to add:::::\n");
        scanf("%d",&data);
        push(data);
            break;
        case 2:print();
        break;
        case 3:pop();
        break;
        case 4:empty();
        break;
        case 5:peek();
        break;
        case 6:printf("....+++---Thank You---+++...\n");
        exit(0);
        break;
        default:printf("Wrong choice...\n");
            break;
        }
        /* code */
    }
    
}
void push(int data)
{
    struct node*newnode;
    newnode=malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("memory allocation is failed....\n");
        exit(0);
    }
    newnode->data=data;
    newnode->link=top;
    top=newnode;
    
}
void print()
{
    if(top==NULL)
    {
        printf("No stack.....\n");
        exit (0);
    }
    struct node*current=top;
    while(current!=NULL)
    {
        printf("  %d  \n",current->data);
        current=current->link;
    }
    printf("\n");

}
int pop()
{
    struct node*ui=top;
    if(top==NULL)
    {
        printf("The code is empty...\n");
        exit(0);
    }
    top=top->link;
    free(top);
    
}
int empty()
{
    if(top==NULL)
    {
        printf("There are no stack......\n");
        return 1;
    }
    else
    {
        printf("There are a stack.....\n");
        return 0;
    }
}
int peek()
{
    if(top==NULL)
    {
        printf("There are no stack to seen......\n");
        exit(1);
        
    }
    else{
        return top->data;
    }
}