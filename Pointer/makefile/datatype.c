#include <stdio.h>
#include "add_with_tax.h"
float total_1=0.0;
short count_1=0;
int main()
{
    float val;
    printf("Price of item: ");
//take price from stdin
    while (scanf("%f", &val)==1){
        printf("Total so far: %.2f\n", add_with_tax(val));
        printf("Price of item: ");
        count_1+=1;
        total_1=add_with_tax(val);
    }
    printf("\n Final total: %.2f\n",total_1);
    printf("Number of items: %hi\n", count_1);
    return 0;
}