#include <stdio.h>

float total =0.0;
short count=0;
short tax_percent=6;
//define a function to calculate the total cost
float  add_with_tax(float f);
{
float tax_rate=1+float(tax_percent)/100       ;
    total=total+(f*tax_rate);
    count=count+1;
    return total;
}
int main()
{
    float val;
    printf("Price of item: ");
//take price from stdin
    while (scanf("%f", &val)==1){
        printf("Total so far: %2f\n", add_with_tax(val));
        printf("Price of item: ");
    }
    printf("\n Final total: %.2f\n",total);
    printf("Number of items: %hi\n", count);
    return 0;
}