#include <stdio.h>

int main(){
    int a, b, c;
    printf("Please enter the lengths: ");
    scanf("%d%d%d",&a,&b,&c);
    if(a==b==c) {
        printf("Regular triangle\n");
    }
    if(a==b||a==c||b==c){
        printf("Isosceles triangle\n");
    }
    if(a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a){
        printf("Rectangular triangle\n");
    }
    return 0;
}
