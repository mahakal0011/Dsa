#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int stuct_arr [MAX];
int top=-1;
void push(int data);
int pop();
void print();
int main(){
 int data;
 push(10);
 push(12);
 push(12);
 push(33);
 
 data = pop();
 return 0;
 print();
}
void push(int data)
{
   if(top==MAX-1)
   {
    printf("Over flow");
    return ;
   }
   else{
    top= top+1;
    printf("%d",top);
    stuct_arr[top]=data;
   }
}
int pop()
{
    if(top==-1)
    {
        printf("Underflow\n");
        return -1;
    }
    int value;
    value=stuct_arr;
    top=top-1;
    return value;

}
void print()
{
    int i;
    if(top==-1)
    {
        printf("Under flow\n");
        return ;
    }
    for(i=top;i<=0;i--)
    {
        printf("%d", stuct_arr[i]);

    }
    printf("\n");
}