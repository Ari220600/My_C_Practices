#include <stdio.h>

void printarray(int*a, int k){
    for (int i = 0; i < k; i++)
    {
        printf("%d\n",a[i]);
    }
    
}

void selectionsort(int *a ,int n){
    int min,j,temp;
    printf("\nRunning selection sort........\n\n");
    for (int i = 0; i <n; i++)
    {
        min=i ;
        j=i+1;
        while(j<n && a[j]<a[min])
            {
                min=j;
                j++;
            }
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
    }
    
}

int main(){
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
    printf("before using selection sort\n");
    printarray(arr,n);
    selectionsort(arr,n);
    printf("after using selection sort\n");
    printarray(arr,n);

    return 0;
}