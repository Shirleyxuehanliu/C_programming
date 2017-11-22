#include <stdio.h>

int main(){
    int max,a,b;
    printf("Please enter three integers:");
    scanf("%d%d%d", &max, &a, &b);
    if (max<a){
        max=a;
    }
    if(max<b){
        max=b;
    }
    printf("Max is %d\n", max);
    return 0;

}
