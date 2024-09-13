#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create(int val)
{
    struct node *k = (struct node *)malloc(sizeof(struct node));
    k->data = val;
    k->left = k->right = NULL;
}

void preorder(struct node *root)
{
    if (root!= NULL)
    {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root!= NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}

void inorder(struct node *root)
{
    if (root!= NULL)
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct node *p = create(6);
    struct node *p1 = create(3);
    struct node *p2 = create(8);
    struct node *p3 = create(1);
    struct node *p4 = create(4);
    struct node *p5 = create(7);
    struct node *p6 = create(10);
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;
    printf("\npreorder traverse \n");
    preorder(p);
    printf("\npostorder traverse \n");
    postorder(p);
    printf("\ninorder traverse \n");
    inorder(p);
    return 0;
}