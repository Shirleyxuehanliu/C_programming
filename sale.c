#include <stdio.h>

int main(){
    int a, b;
    printf("please enter the number of people in this table: \n");
    scanf("%d", &a);
    if(a>=10){
        b=a*300*0.8;
        printf("Total is %d", b);
    }
    if (a<10){
        b=a*300;
        printf("Total is %d", b);
    }
    return 0;

}
