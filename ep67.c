# include <stdio.h>
int main(){
    int a, sum, count;
    float average;
    sum=0;
    count=0;
    printf("Please enter the numbers(quit: 0): \n");
    while(a!=0){
        scanf("%d",&a);
        sum=sum+a;
        count=count+1;
    }
    if(count==1){
        printf("The sum is 0\n The average is 0\n");
    } 
    else{
        average=(float)sum/(count-1);
        printf("The sum is %d\n",sum);
        printf("The average is %f\n", average);
    }
    
    return 0;
}