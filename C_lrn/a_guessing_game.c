#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    int number, player=1,guess,newguess1=1,newguess2=1;
    srand(time(0));
    number = rand()%100 + 1;
    //printf("the number is %d\n",number);
    do{
        printf("Turn of player %d\n", player);
        printf("Guess the number between 1-100\n");
        scanf("%d", &guess);
        if(guess>number){
        printf("Lower the number please\n");
        }
        else if(guess<number){
        printf("Higher number please\n");
        }
        else{
        if(newguess1>newguess2){
        printf("Congrats player 2 You've guessed it in %d guesses!!\n",newguess2);}
        else{
        printf("Congrats player 1 You've guessed it in %d guesses!!\n",newguess1);
        }
        }
        if(player<2){
        player++;
        newguess1++;
        }
        else{
        player--;
        newguess2++;
        }
    }while(guess!=number);
    return 0;
}