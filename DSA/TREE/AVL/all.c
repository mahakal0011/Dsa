#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *right;
    struct node *left;
    int height;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct node *n) {
    if (n == NULL) {
        return 0;
    }
    return n->height;
}

int balanced_factor(struct node *n) {
    if (n == NULL) {
        return 0;
    }
    return height(n->left) - height(n->right);
}

struct node *create_node(int data) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->left = new->right = NULL;
    new->height = 1;
    return new;
}

struct node *right_rotate(struct node *y) {
    struct node *x = y->left;
    struct node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

struct node *left_rotate(struct node *x) {
    struct node *y = x->right;
    struct node *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

struct node *insert(struct node *node, int data) {
    if (node == NULL) {
        return create_node(data);
    }

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    } else {
        return node; // No duplicate values allowed
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int bf = balanced_factor(node);

    if (bf > 1 && data < node->left->data) {
        return right_rotate(node);
    }
    if (bf < -1 && data > node->right->data) {
        return left_rotate(node);
    }
    if (bf > 1 && data > node->left->data) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }
    if (bf < -1 && data < node->right->data) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

void preorder(struct node *node) {
    if (node != NULL) {
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

int main() {
    int ch, data;
    struct node *root = NULL;

    do {
        printf("Enter value to add: ");
        scanf("%d", &data);
        root = insert(root, data);

        printf("Do you want to add another value? (1 for yes, 0 for no): ");
        scanf("%d", &ch);
    } while (ch == 1);

    printf("Preorder traversal of the tree: ");
    preorder(root);
    printf("\n");

    return 0;
}
