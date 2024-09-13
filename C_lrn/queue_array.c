#include <stdio.h>
#include <stdlib.h>
struct queue{
    int size;
    int f;
    int r;
    int * arr;
};
int isfull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
int isempty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
void enqueue (struct queue *q){
    if (isfull(q)){
        printf("The queue is full\n");
    }
    else{
        int val;
        printf("enter the value you want to enqueue\n");
        scanf("%d",&val);
        q->r++;
        q->arr[q->r]=val;
        printf("The Value is enqueued\n");
    }
}
void dequeue (struct queue *q){
    int a=-1; 
    if (isempty(q)){
        printf("The queue is empty\n");
    }
    else{
        q->f++;
        a= q->arr[q->f];
        printf("Your dequeued value is %d\n",a);
    }
}

void view(struct queue *q){
    if(isempty(q)){
        printf("The queue is empty\n");
    }
    else{
        printf("The values in the queue are : \n");
        for (int i = q->f+1; i <= q->r; i++)
        {
            printf("%d\n",q->arr[i]);
        }
    }
}

int main(){
    struct queue q;
    q.size=4;
    q.f=q.r=-1;
    q.arr=(int*)malloc(q.size*sizeof (int));
    int k;
    printf("Your Queue has been created\n");
    for (int i = 0; i <1; i--)
    {
        printf("Please enter your choice\n1. enqueue\n2.dequeue\n3.view\n4.exit\n");
        scanf("%d",&k);
        if(k==1){
            enqueue(&q);
        }
        else if(k==2){
            dequeue(&q);
        }
        else if(k==3){
            view(&q);
        }
        else if(k==4){
            printf("Thank You!!!");
            break;
        }
        else{
            printf("Please enter a valid option\n");
        }
    }
    
   
    return 0;
}