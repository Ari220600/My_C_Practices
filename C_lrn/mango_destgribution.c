#include <stdio.h>
int fact(int a){
    int k=1;
    for (int i = 1; i <=a ; i++)
    {
        k=k*i;
    }
    return k;
    
}
int main(){
    int m,n;
    printf ("Enter the number of men\n");
    scanf("%d",&m);
    printf ("Enter the nimber of mangoes\n");
    scanf("%d",&n);
    int l =fact(m+n-1)/(fact(m)*fact(n-1));
    printf ("The number of ways are %d",l); 

    return 0;
}