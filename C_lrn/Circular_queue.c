#include <stdio.h>
#include <stdlib.h>
struct Cirqueue{
    int size;
    int f;
    int r;
    int * arr;
};
int n=0;
int isfull(struct Cirqueue *q){
    if((q->r+1)%q->size==q->f){
        return 1;
    }
    return 0;
}
int isempty(struct Cirqueue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
void enqueue (struct Cirqueue *q){
    if (isfull(q)){
        printf("The queue is full\n");
    }
    else{
        int val;
         printf("enter the value you want to enqueue\n");
         scanf("%d",&val);
        q->r=(q->r+1) % q->size;
        q->arr[q->r]=val;
        printf("The Value is enqueued\n");
        n++;
    }
}
void dequeue (struct Cirqueue *q){
    int a=-1; 
    if (isempty(q)){
        printf("The queue is empty\n");
    }
    else{
        q->f=(q->f+1) % q->size;
        a= q->arr[q->f];
        printf("Your dequeued value is %d\n",a);
        n--;
    }
}

void view(struct Cirqueue *q){
    if(isempty(q)){
        printf("The queue is empty\n");
    }
    else{
        printf("The values in the queue are : \n");
        int i = (q->f+1) % q->size,k=0;
        while ( k < n)
        {
            printf("%d\n",q->arr[i]);
            i=(i+1)%q->size;
            k++;
        }
    }
}

int main(){
    struct Cirqueue q;
    q.size=4;
    q.f=q.r=0;
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