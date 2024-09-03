#include<stdio.h>/*header*/
#include<stdlib.h>
typedef struct node /*Defines a structure for a linked list node:*/
{
    int data;
    struct node*link;
};
int main()/*The main function is where the program starts:*/
{
    int i;
    struct node *n1=NULL,*p;
    for(i=0;i<3;i++)/*A 'for' loop is used to create and populate the linked list with three nodes:*/
    {
        p=(struct node *)malloc(sizeof(struct node));/*Memory is allocated for a new node using malloc, and its address is stored in p*/
        printf("Enter the data");/*The user is prompted to enter data for the new node, and the value is stored in p->data.*/
        scanf("   %d",&p->data);
    if (n1==NULL)
    {
        /* code */
        p->link=NULL;
/*Depending on whether the linked list is empty (n1 == NULL), one of the two cases is executed:

If the list is empty, the new node's link is set to NULL, 
and n1 is updated to point to the new node.
If the list is not empty, the new node's link is set to point to the current head of the list (which is n1), 
and n1 is updated to point to the new node. This effectively adds the new node to the beginning of the list.*/
        
        n1=p;/*After the loop, p is reset to n1 for traversing the list,*/
    }
    else{
        p->link=n1;
        n1=p;
    }
    }
    p=n1;
/* 
and a while loop is used to print the data from each node in the linked list:

*/
    while (p!=NULL)/*The while loop continues as long as p is not NULL.*/
    {
     printf("%d\n",p->data);
     /*Inside the loop, it prints the data of the current node and moves p to the next node using p->link.
     */
     p=p->link;   /* code */
    }
    
    

}