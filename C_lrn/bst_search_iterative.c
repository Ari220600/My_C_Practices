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

int isbst(struct node *root)
{   
    static struct node *prev=NULL;
    if (root!= NULL)
    {
        if(!isbst(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data<=prev->data){
            return 0;
        }
        prev=root;
        return isbst(root->right);
    }
    else{
        return 1;
    }
}

struct node*search(struct node*root,int key){
    while(root!=NULL){
        if(root->data==key){
            return root;
        }
        else if(root->data>key){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return NULL;
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
    if(isbst(p))
    printf("\nThe tree is a BST");
    else
    printf("\nThe tree is not a BST\n");
    int x;
    printf("\nthe number you want to search\n");
    scanf("%d",&x);
    struct node*n = search(p,x);
    if(n!=NULL){
        printf("\nFound : %d\n",n->data);
    }
    else{
        printf("\nnumber not found\n");
    }
    return 0;
}