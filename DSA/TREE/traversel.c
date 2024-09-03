#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node* createNode(int value) {
  struct node *new = malloc(sizeof(struct node));
  new->data = value;
  new->left = NULL;
  new->right = NULL;
  return new;
}

void preorder(struct node *root) {
  if(root != NULL) {
    printf("%d\n", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(struct node *root) {
  if(root != NULL) {
    postorder(root->left);
    postorder(root->right);
    printf("%d\n", root->data);
  }
}

void inorder(struct node *root) {
  if(root != NULL) {
    inorder(root->left);
    printf("%d\n", root->data);
    inorder(root->right);
  }
}

int main() {
  struct node *root = createNode(2);
  root->left = createNode(4);
  root->right = createNode(6);
  root->left->right = createNode(12);
  root->left->left = createNode(16);

  printf("Pre-order traversal:\n");
  preorder(root);
  printf("Post-order traversal:\n");
  postorder(root);
  printf("In-order traversal:\n");
  inorder(root);

  return 0;
}
