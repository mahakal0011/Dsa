#include<stdio.h>
#include<conio.h>
typedef struct node{
    int data;
    struct node*link;
};
int main(){
    int i ;
    struct node*head=NULL,*mk;
    for(i=1;i<5;i++)
    {
        mk=(struct node*)malloc(sizeof(struct node));
        printf("Enter the node");
        scanf("%d",&mk->data);
        if(head==NULL)
        {
            haed->link=head;
            head=mk;
        }
        else{
            head->link=mk;
            head=mk;
        }
        struct node*print=head;
        while(print!=NULL)
        {
            printf("%d",print->data);
            print=print->link;
        }

    }
    return 0;
}