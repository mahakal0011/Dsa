#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*left;
    struct node*right;
};
struct node*root=NULL;
struct node*create(int value)
{
    struct node*new=malloc(sizeof (struct node));
    new->data=value;
    new->left=new->right=NULL;
    return new;
}
void preorder(struct node*root)
{
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
}
int main()
{
  struct node*root=create(12);
  root->left=create(8);
  root->right=create(16);
  root->left->left=create(6);
  preorder(root);
  printf("\n");
  
}
void insert(int value)
{
    struct node*temp=malloc(sizeof (struct node));
    temp->data=value;
    temp->left=temp->right=NULL;
    struct node*current=root;
    if(root==NULL)
    {
        root=temp;
    }
    else{
    while(current)
    {
        if(temp->data>current->data)
        {
            current=current->right;
        }
        else
        {
            current=current->right;
        }
    }
    if(temp->data>current->data)
    {
        current->right=temp;
    }
    else{
        current->left=temp;
    }
    }
}