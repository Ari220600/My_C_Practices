#include <stdio.h>
#include <stdlib.h>
struct node *f=NULL;
struct node *r=NULL;
struct node{
    int data;
    struct node *next;
};


void enqueue(){
    struct node *n= (struct node *)malloc(sizeof(struct node));
    if (n==NULL){
        printf("The queue is full\n");
    }
    else{
        int val;
        printf("enter the value\n");
        scanf("%d",&val);
        n->data = val;
        n->next= NULL;
        if(f==NULL){
            f=n;
            r=n;
        }
        else{
            r->next=n;
            r=n;
        }
    }
}

void dequeue(){
    struct node * ptr;
    ptr=f;
    if(f==NULL){
        printf("The queue is empty\n");
    }
    else{
        printf("dequeued element : %d\n",ptr->data);
        f=f->next;
        free(ptr);
    }
}

void traversal(struct node * ptr)
{   if(ptr==NULL){
        printf("The queue is empty\n");
    }
    while(ptr!=NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }
}

int main(){
    int k;
    for (int i = 0; i < 1; i--)
    {
        printf ("Choose your option\n1. enqueue\n2. dequeue\n3. view\n4. Exit\n");
        scanf("%d",&k);
        if(k==1){
            enqueue();
        }
        else if(k==2){
            dequeue();
        }
        else if(k==3){
            traversal(f);
        }
        else if(k==4){
            printf("Thank You!!");
            break;
        }
        else{
            printf("Please enter a valid option\n");

        }
    }
    
    return 0;
}