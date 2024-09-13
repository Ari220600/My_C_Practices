#include<stdio.h>
#include<stdlib.h>
 
struct Node{
    int data;
    struct Node * next;
};
 
struct Node* top = NULL;
 
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next; 
    }
}
 
int isEmpty(struct Node* top){
    if (top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
 
int isFull(struct Node* top){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
 
struct Node* push(struct Node* top, int x){
    if(isFull(top)){
        printf("Stack Overflow\n");
    }
    else{
        struct Node* n = (struct Node*) malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}
 
int pop(struct Node* tp){
    if(isEmpty(tp)){
        printf("Stack Underflow\n");
    }
    else{
        struct Node* n = tp;
        top = (tp)->next;
        int x = n->data;
        free(n);
        return x; 
    }
}
 
int main(){
    int elm , k ,n ;
    printf("Enter first element\n");
    scanf("%d",&elm);
    top = push(top, elm);
    for (int i = 0; i >= 0; i++)
    {
        printf("press 1 to add more 0 to stop\n");
        scanf("%d",&k);
        if(k==0){
            break;
        }
        else{
            printf("enter the element\n");
            scanf("%d",&elm);
            top = push(top, elm );
        }
    }

    for (int j = 0; j >= 0; j++)
    {

        printf("enter your choice\n 1.see the stack\n 2.push element\n 3.pop element\n 4. exit\n");
        scanf("%d",&n);
        if(n==1){
            linkedListTraversal(top);
        }
        else if(n==2){
            printf("enter the element to push\n");
            scanf("%d",&elm);
            top = push(top, elm );
        }
        else if(n==3){
            int element = pop(top);
            printf("popped element is %d\n ",element);
        }
        else if(n==4){
            printf("Thank You!!");
            break;
        }
        else{
            printf("Please enter a valid choice\n");
        }
    }
    return 0;
}
