
#include <stdio.h>
#include <string.h>

char* reverse_string(char b[100]);

int main ()
{
    char string[100];
    printf("please enter a string: \n");
    scanf ("%s", string);
    int length, temp, i;
    length=strlen(string);
    char new_string[100];
    strcpy(new_string, string);
    reverse_string(string);
    for(i=0;i<length;i++)
    {
        if(new_string[i]==string[i])
        {
           temp++; 

        }

    }
    if(temp==length)
    {
        printf("This is a palindrome string!\n");
  
    }
    else
        printf("This is not a palindrome string!\n");
    return 0;

}




/* Reverse a String – Enter a string and the program will reverse it and print it out.*/

char* reverse_string(char a[100])
{   
/*calculate number of char in the string*/
    int length;
    length=strlen(a); 
/* char array*/
    int imme, i;
    imme=length/2;
/*exchange content*/
    for(i=0;i<imme;i++)
    {
    int c;
    c=a[i];
    a[i]=a[length-1-i];
    a[length-1-i]=c;
    }
    return a;
}

/*when reverse string, a[length+1]='\0', and while exchange content, a[length+1]='\0'does not change.
Therefore, I am able to print the correct answer*/