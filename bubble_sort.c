#include <stdio.h>
int main (){
    int a[10];
    int i, j, temp;
    for(i=0;i<9;i++)
    {
        scanf("%d", &a[i]);
    }
    
    for(j=9;j>1;j--)
    {

    for(i=0;i<j;i++)
    { 
        if (a[i+1]<a[i])
            { temp=a[i+1];
              a[i+1]=a[i];
              a[i]=temp;
            }

    }
    }
    for(i=0;i<9;i++)
    {
    printf("%d\n",a[i]);
    }
return 0;
}