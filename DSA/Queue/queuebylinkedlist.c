#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int data;
    struct queue*link;
};
int front=NULL;
int rear=NULL;
int main()
{
    struct queue*queue;
    queue=malloc(sizeof(struct queue));
    
}