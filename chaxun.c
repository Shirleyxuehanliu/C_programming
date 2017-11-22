#include <stdio.h>
int main()
{
    int a[5];
    int i, Q;
    for(i=0,i<=4,i++)
    {
        printf("%d: ",i+1);
        scanf("%d", &a[i]);

    }
    printf("Q: ");
    scanf ("%d ",&Q);
    printf("%d ", a[Q]);
    
   
}