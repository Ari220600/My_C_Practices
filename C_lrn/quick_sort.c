#include <stdio.h>

void printarray(int*a, int k){
    for (int i = 0; i < k; i++)
    {
        printf("%d\n",a[i]);
    }
    
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    // Swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}


void quickSort(int A[], int low, int high)
{
    int partitionIndex; // Index of pivot after partition

    if (low < high)
    {
        partitionIndex = partition(A, low, high); 
        quickSort(A, low, partitionIndex - 1);  // sort left subarray 
        quickSort(A, partitionIndex + 1, high); // sort right subarray
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
    printf("before using quick sort\n");
    printarray(arr,n);
    quickSort(arr,0,n-1);
    printf("after using quick sort\n");
    printarray(arr,n);
    return 0;
}