#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*left;
    struct node*right;
    int height;
};

int get_height(struct node*n)
{
    if(n==NULL)
    {
        return 0;
    }
    return n->height;
}

struct node* balanced_factor(struct node*n)
{
    if(n==NULL)
    {
        return 0;
    }
    return (get_height(n->left)-get_height(n->right));
}

struct node*create(int data)
{
    struct node*new=malloc(sizeof(struct node));
    new->data=data;
    new->left=new->right=NULL;
    new->height=1;
    return new;
}
int max(int a, int b)
{
     return (a>b)?a:b;
}

struct node*right_rotation(struct node* y)
{
    struct node*x=y->left;
    struct node*t2=x->right;

    x->right=y;
    y->left=t2;

    y->height=1+max(get_height(y->left),get_height(y->right));
    x->height=1+max(get_height(x->left),get_height(x->right));

    return x;
}

struct node*left_rotataion(struct node* x)
{
    struct node*y=x->right;
    struct node*t2=y->left;

    y->left=x;
    x->right=t2;

    y->height=1+max(get_height(y->left),get_height(y->right));
    x->height=1+max(get_height(x->left),get_height(x->right));
    return y;
}

struct node*insert(struct node* n,int data)
{
    if(n==NULL)
    {
        return create(data);
    }
    if(data<n->data)
    {
        n->left=insert(n->left,data);
    }
    else if(data>n->data)
    {
        n->right=insert(n->right,data);
    }
    else{
    return n;
    }
    n->height=1+max(get_height(n->left),get_height(n->right));
    int balanced=balanced_factor(n);
    //left- left case
    if(balanced>1 && data<n->left->data)
    {
        return right_rotation(n);
    }
    //right -0 right case
    if(balanced>-1 && data>n->right->data)
    {
        return left_rotataion(n);
    }
    // left - right case
    if(balanced>1 && data>n->left->data)
    {
       n->left=left_rotataion(n->left);
       return right_rotation(n);
    }
    // right right case
    if(balanced>-1 && data<n->right->data)
    {
        n->right=right_rotation(n->right);
        return left_rotataion(n);
    }
    return n;

}

int preorder(struct node*n)
{
    if(n!=NULL)
    {
        printf("%d",n->data);
        preorder(n->left);
        preorder(n->right);

    }
   
}

int main()
{
    struct node*n=NULL;
    int ch,data;

    do
    {
        printf("What value you want to add\n");
        scanf("%d",&data);
        n=insert(n,data);
        printf("Are you want to add something (1 for add 0 for exit)");
        scanf("%d",&ch);
    } while (ch==1);

    preorder(n);
    printf("\n");
    return 0;
    
}