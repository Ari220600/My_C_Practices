#include <stdio.h>

void printarray(int*a, int k){
    for (int i = 0; i < k; i++)
    {
        printf("%d\n",a[i]);
    }
    
}

void bubblesort(int*a, int k){
    int temp;
    int issorted=0;
    for (int i = 0; i < k-1; i++)
    {   
        issorted=1;
        printf("working on pass number %d\n",i+1);
        for (int j = 0; j < k-1-i; j++)
        {
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                issorted=0;
            }
        }
        if(issorted==1){
            return;
        }
        
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
    printf("before using bubblesort\n");
    printarray(arr,n);
    printf("after using bubblesort\n");
    bubblesort(arr,n);
    printarray(arr,n);

    return 0;
}