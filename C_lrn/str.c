#include <stdio.h>
#include <string.h>
int main(){
    char c[20],n;
    scanf("%s",c);
    int s=0,j=0;
    while(c[j]!=0){
        s=s+c[j];
        j++;
    }
    printf("\n%d",s);
    return 0;
}