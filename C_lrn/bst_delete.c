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

struct node *inorderpred(struct node *root){
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}

struct node *delete(struct node *root,int val){
    if(root==NULL)
        return NULL;
    if(root->left==NULL&&root->right==NULL&&root->data==val){
        free(root);
        printf("\ndeletion of %d is complete\n",val);
        return NULL;
    }
    if(val<root->data){
        root->left=delete(root->left,val);
    }
    else if(val>root->data){
        root->right=delete(root->right,val);
    }
    else{
        struct node *ipre=inorderpred(root);
        root->data=ipre->data;
        root->left=delete(root->left,ipre->data);
    }
    return root;
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
    // if(isbst(p))
    // printf("\nThe tree is a BST");
    // else
    // printf("\nThe tree is not a BST");
    int x;
    printf("\nenter the value you want to remove\n");
    scanf("%d",&x);
    delete(p,x);
    printf("\npreorder traverse \n");
    preorder(p);
    printf("\npostorder traverse \n");
    postorder(p);
    printf("\ninorder traverse \n");
    inorder(p);
    return 0;
}