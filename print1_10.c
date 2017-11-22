#include<stdio.h>
int main(){
    int count, sum=0;
    for(count=1;count<=100;count++)
    {
        sum=sum+count;
    }
    printf("%d\n", sum);
    
    return 0;
}
