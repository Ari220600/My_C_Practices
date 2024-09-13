#include <stdio.h>
#include <stdlib.h>

void printarray(int*a, int k){
    for (int i = 0; i < k; i++)
    {
        printf("%d\n",a[i]);
    }
}
int maxelm(int*a,int n){
    int max=a[0];
    for (int i = 1; i < n; i++)
    {
        if(a[i]>max){
            max=a[i];
        }
    }
    printf("the max elm is %d\n\n\n",max);
    return max;
    
}
void countsort(int*a, int n){
    int maximum=maxelm(a,n);
    int *count=(int*)malloc((maximum+1)*sizeof(int));
    int i,j;
    for (i = 0; i <= maximum; i++)
    {
        count[i]=0;
    }
    for (j = 0; j < n; j++)
    {
        i=a[j];
        count[i]++;
    }
    /*int g= maximum+1;
    printf("printing count\n\n\n");
    printarray(count,g);
    printf("printing sorted array\n");*/
    i=j=0;
    while(i<=maximum){
        if (count[i]>0)
        {
            a[j]=i;
            count [i]--;
            j++;
        }
        else{
            i++;
        }
        
    }
    printarray(a,n);
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
    for(int i=1; i>0 ;i++)
    {
        if(n==k){
                printf("array full\n");
                break;
            }
        printf("enter your choice\n1.Keep pushing value\n2.exit\n");
        scanf("%d",&l);
        if (l==1)
        {   
            printf("enter new value\n");
            scanf("%d",&arr[n]);
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
    printf("before using count sort\n");
    printarray(arr,n);
    printf("after using count sort\n");
    countsort(arr,n);
    return 0;
}