#include <stdio.h>
int main(){
    int answer=4, count=0;
    int guess;
    printf("please enter your guess:\n");
    scanf("%d", &guess);
        while(guess!=answer){
            if(guess>answer){
                printf("too large!\n");
            }
            else
                printf("too small!\n");
            count=count+1 ;
            printf("please enter your guess:\n");
            scanf("%d", &guess);         
        }
    }
    return 0;
}