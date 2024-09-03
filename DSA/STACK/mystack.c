#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int stack_arr [MAX];
int top=-1;
void push();
void print();
int pop();
int main()
{
    int ch ;
    while (-1)
    {
        printf("What do you want to do....\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:push();
            break;
        case 2:print();
        break;
        case 3:pop();
        break;
        case 4:exit(0);
        printf("......Thank you.....\n");
        default:printf("Invalid option.....\n");
         printf("Thank you\n");
        return 1;
            break;
        }
        /* code */
    }
    

}
void push()
{
    int data;
    if(top==MAX-1)
    {
        printf("Overflow...\n");
        exit(0);
    }
    else
    { 
        top=top+1;
        printf("What do you want to add...\n");
        scanf("%d",&data);
        stack_arr[top]=data;

    }
 
}
void print()
{
    int i;
    if(top==-1)
    {
        printf("There are no any number...\n");
        exit(0);
    }
    else{
        for(i=top;i>=0;i--)
        {
            printf("%d\n",stack_arr[i]);
        }
        printf("\n");

    }
}
int pop()
{
    if(top==-1)
    {
        printf("There are no any element to delete...\n");
        exit(0);
    }
    else{
        int value;
        value=stack_arr;
        top=top-1;
        return value;


    }
}