#include <stdio.h>
#include <stdlib.h>
struct myarray
{
    int total_size, used_size,*ptr; 
};

void createarray(struct myarray *a, int tsize,int usize)
{
    // (*a).total_size=tsize;
    // (*a).used_size=usize;
    // (*a).ptr=(int*)malloc(tsize*sizeof(int));
    a->total_size=tsize;
    a->used_size=usize;
    a->ptr=(int*)malloc(tsize*sizeof(int));
}

void show (struct myarray *a){
    printf("The numbers are :\n");
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n",(a->ptr)[i]);
    }
}

void showchoice(struct myarray *a){
    int p;
    printf("Insert the position you want to visit\n");
    scanf("%d",&p);
    printf("The value of the position is : %d \n",(a->ptr)[p-1]);
}

void showchoicepos(struct myarray *a){
    int p;
    printf("Insert the element you want to find\n");
    scanf("%d",&p);
    for (int i = 0; i < a->used_size; i++)
    {
        if(p==(a->ptr)[i]){
            printf("position : %d\n",i+1);
        }
        else{
            continue;
        }
    }
    
}

void addelm (struct myarray *a){
    int k,n,j,p;
    for (int i = 0; i > -1; i++)
    {
        printf("please select the process:\n");
        printf("1 for adding at last position\n");
        printf("2 for adding at definite position\n");
        printf("any other number to go back\n");
        scanf("%d",&k);
        if (k==1){
            printf("please enter the number:\n");
            scanf("%d",&n);
            j= a->used_size;
            (a->ptr)[j]=n;
            printf("Your number has been added at the last position\n");
            a->used_size++;
            break;
        }
        else if(k==2){
            printf("Do you want to keep the order of array (1) or put the existing no. in that position at the end of the array (2)?\n");
            scanf("%d",&j);
            if(j==1){
                printf("put the number\n");
                scanf("%d",&n);
                printf("put the position\n");
                scanf("%d",&p);
                for (int l = a->used_size; l >= p ; l--)
                {
                    (a->ptr)[l]=(a->ptr)[l-1];
                }
                (a->ptr)[p-1]=n;
                a->used_size++;
                break;
            }
            else if(j==2){
                printf("put the number\n");
                scanf("%d",&n);
                printf("put the position\n");
                scanf("%d",&p);
                int z,y = a->used_size;
                z= (a->ptr)[p-1];
                (a->ptr)[p-1]=n;
                (a->ptr)[y]=z;
                a->used_size++;
                break;
            }
        }
        else
        break;
    }
    
}

void delelm(struct myarray *a){
    int k;
    for (int i = 0; i < 1; i--)
    {
        printf("Select the process:\n");
        printf("Press 1 Delete the last element\n");
        printf("Press 2 Delete a definite element\n");
        printf("any other number to go back\n");
        scanf("%d",&k);
        if(k==1){
            int n;
            n= a->used_size;
            (a->ptr)[n-1]=(a->ptr)[n];
            a->used_size--;
            break;
        }
        else if(k==2){
            int z;
            printf("press 1 to delete using definite position\n");
            printf("press 2 to delete all positions of a value\n");
            scanf("%d",&z);
            if(z==1){
                int n;
                printf("enter the position:\n");
                scanf("%d",&n);
                for (int i = n; i <= a->used_size; i++)
                {
                    (a->ptr)[i-1]=(a->ptr)[i];
                }
                a->used_size--;
                break;
            }
            else if(z==2){
                int n,m=0;
                printf("enter the value you want to delete:\n");
                scanf("%d",&n);
                for (int l = 0; l < a->used_size; l++)
                {
                    if(n==(a->ptr)[l]){
                        for (int i = l+1; i <= a->used_size; i++)
                {
                    (a->ptr)[i-1]=(a->ptr)[i];
                }
                m++;
                //printf("value of m is %d\n",m);
                l--;
                    }
                    else
                    continue;
                }
                a->used_size= a->used_size-m;
                break;
                
            }
        }else
        break;
    }
    
}

void replace (struct myarray *a){
    int k;
    printf ("select the process:\n");
    printf("press 1 to replace a the value from a position\n");
    printf("press 2 to replace all similar values with another value\n");
    printf("any other number to go back\n");
    scanf("%d",&k);
    if (k==1){
        int p,v;
        printf("enter the position of replacement\n");
        scanf("%d",&p);
        printf("enter the value of replacement \n");
        scanf("%d",&v);
        (a->ptr)[p-1]=v;
    }
    else if(k==2){
        int p,v;
        printf("enter the value that you want to replace\n");
        scanf("%d",&p);
        printf("enter the value that you want to replace with \n");
        scanf("%d",&v);
        for (int i = 0; i < a->used_size; i++)
        {
            if(p==(a->ptr)[i]){
                (a->ptr)[i]=v;
            }
            else
            continue;
        }
        

    }
}

void setval (struct myarray *a){
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Please enter element in the position number %d\n",i+1);
        scanf("%d",&n);
        (a->ptr)[i]=n;
    }
    
}

int main(){
    int m,k,j;
    for ( j = 1; j>0 ; j++)
    {
        printf("please inform the size of array (under 5) :\n");
        scanf("%d",&m);
        if(m>5){
        printf("EROR !! Please enter a valid size!!\n");
        }
        else if(m<=5){
            j=-2;
        }
        else{
            m++;
        }
    }
    struct myarray marks;
    createarray (&marks,10,m);
    printf("We are creating the array now\n");
    setval(&marks);
    do{
    printf ("please select the number according to your action:\n");
    printf("1. Show the array\n");
    printf("2. Show an element in the array\n");
    printf("3. Show the position of an element in the array\n");
    printf("4. add an element in the array\n");
    printf("5. delete an element from the array\n");
    printf("6. replace an element from the array\n");
    printf("7. exit\n");
    printf("Select your choice\n");
    scanf("%d",&k);
    if(k==1){
        show(&marks);
    }
    else if(k==2){
        showchoice(&marks);
    }
    else if(k==3){
        showchoicepos(&marks);
    }
    else if(k==4){
        addelm(&marks);
    }
    else if(k==5){
        delelm(&marks);
    }
    else if(k==6){
        replace(&marks);
    }
    else if(k>7){
        printf("Please enter a valid choice\n");
    }
    }while (k!=7);
    printf("!!THANK YOU!!");
    return 0;
}