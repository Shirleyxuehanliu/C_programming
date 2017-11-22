/* Reverse a String – Enter a string and the program will reverse it and print it out.*/

#include <stdio.h>
#include <string.h>
int main()
{   char a[100];
    printf("Enter a string: \n");
    scanf("%s", a);
    printf("Your string: %s\n", a);
/*calculate number of char in the string*/
    int length;
    length=strlen(a);
    printf("%d\n", length);
/* char array*/
    int imme, i;
    imme=length/2;
    printf("%d\n", imme);
/*exchange content*/
    for(i=0;i<imme;i++)
    {
    int c;
    c=a[i];
    a[i]=a[length-1-i];
    a[length-1-i]=c;
    }
    printf("%s\n",a);
return 0;

}

/*when reverse string, a[length+1]='\0', and while exchange content, a[length+1]='\0'does not change.
Therefore, I am able to print the correct answer*/