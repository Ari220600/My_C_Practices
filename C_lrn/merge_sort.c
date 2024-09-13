#include <stdio.h>

void printarray(int*a, int k){
    for (int i = 0; i < k; i++)
    {
        printf("%d\n",a[i]);
    }
}

void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void mergesort(int A[], int low, int high){
    int mid; 
    if(low<high){
        mid = (low + high) /2;
        mergesort(A, low, mid);
        mergesort(A, mid+1, high);
        merge(A, mid, low, high);
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
    printf("before using merge sort\n");
    printarray(arr,n);
    mergesort(arr,0,n-1);
    printf("after using merge sort\n");
    printarray(arr,n);
    return 0;
} 