#include<stdio.h>
#include<stdlib.h>
#define MAX 2
int queue[MAX];
int front=-1;
int rear=-1;
void enqueue();
int dequeue();
void print();
int main()
{
      printf(">>>>.....MAIN MANUE.....<<<<\n");
      printf("1 for insert>>>\n2 for delete>>>\n3 for print>>>\n");

    while (1)
    {
        int ch;
        printf("what do you want...\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:enqueue();
            break;
        case 2:dequeue();
        break;
        case 3:print();
        break;
        default:printf("Wrong choice....\n");
        exit(0);
            break;
        }
        /* code */
    }
}
void enqueue()
{
    int item;
    printf("What do you want to add..\n");
    scanf("%d",&item);

    if((rear==front-1 && rear>-1) || (rear==MAX-1 && front==0))
    {
        printf("Over flow..\n");
        exit(0);
    }
    else if (front==-1 )
    {
        front=0;
        rear=0;
    }
    else if (rear==MAX-1)
    {
        rear=0;
    }
    else
    {
        rear++;
    }
    queue[rear]=item;
    
    
}
void print()
{
    int i;
    if(front==-1)
    {
        printf("under flow..\n");
    }
    else
    {
        for(i=front;i<=rear;i++)
        {
            printf("%d\n",i);
        }
    }
}
int dequeue()
{
    if(front==-1)
    {
        printf("Underflow..\n");
        return -1;
    }
    else if (front == rear)
    {
        front=rear=-1;
    }
    else if (front==MAX-1)
    {
        front=0;
        /* code */
    }
     else
    {
        front =front+1;
       
    }
     return queue[front];
}