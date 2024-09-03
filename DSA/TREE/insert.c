#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*left;
    struct node*right;
};
struct node*create(int value)
{
    struct node*new=malloc(sizeof(struct node));
    new->data=value;
    new->left=new->right=NULL;
    return new;
}
struct node*insert(struct node*root,int  value)
{
    if(root==NULL)
    {
        return create(value);
    }
    if(value<root->data)
    {
        root->left=insert(root->left,value);
    }
    else if(value>root->data)
    {
        root->right=insert(root->right,value);
    }
     return root;

}
void preorder(struct node*root)
{
    if(root!=NULL)
    {
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    int value;
    struct node*root=NULL;
    char ch;
    do
    {
        printf("Enter a value to input\n");
        scanf("%d",& value);
        root=insert(root,value);

        printf("Are you want to add some value in tree(y/n)");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
    preorder(root);
    printf("\n");
    return 0;
}