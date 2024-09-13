#include <stdio.h>

void printarray(int*a, int k){
    for (int i = 0; i < k; i++)
    {
        printf("%d\n",a[i]);
    }
    
}

void insertionsort(int*a, int k){
    int key;
    int j;
    for (int i = 1; i <= k-1; i++)
    {   
        key=a[i];
        j=i-1;
        printf("pass number %d\n",i);
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            printf("comp no.%d\n",j); 
            j--;
        }
        a[j+1]=key;
    }
    
}

int main()
{
    int arr[100], k=0,n=1,l;
    for(int j=0;j>-1;j++){
        printf("enter the size of the array under 99\n");
        scanf("%d",&k);
        if(k<100)
        {
        break;
        }
        else
        {
            printf("enter a valid number");
        }
    }   
    printf("enter the 1st element in the array\n");
    scanf("%d",&arr[0]);
    for(int i=1; i<k ;i++)
    {
        printf("enter your choice\n1.Keep pushing value\n2.exit\n");
        scanf("%d",&l);
        if (l==1)
        {
            printf("enter new value\n");
            scanf("%d",&arr[i]);
            n++;
        }
        else if(l==2)
        {
            break;
        }
        else
        {
            printf("enter a valid choice\n");
        }
        
    }
    printf("before using insertion sort\n");
    printarray(arr,n);
    printf("after using insertion sort\n");
    insertionsort(arr,n);
    printarray(arr,n);

    return 0;
}