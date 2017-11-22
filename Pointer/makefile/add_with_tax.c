#include <stdio.h>


float total =0.0;
short tax_percent=6;

float  add_with_tax(float f)
{
float tax_rate=1+(float)tax_percent/100       ;
    total=total+(f*tax_rate);
    return total;
}