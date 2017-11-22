/*
Pig Latin – Pig Latin is a game of alterations played on the English language game.
To create the Pig Latin form of an English word the initial consonant sound is transposed to the end of the word and an ay is affixed (Ex.: "banana" would yield anana-bay). 
Read Wikipedia for more information on rules.
*/
#include <stdio.h>
#include <string.h>
int main()
{
/*Enter a string*/
char a[100];
printf("Enter a word\n");
scanf("%s",a);
printf("Your string: %s\n", a);
/*Calculating the length of the string*/
int length, new_len;
length=strlen(a);
printf("%d\n", length);
/*take out the first char of the string*/
char b=a[0];
int i;
for(i=1;i<length; i++)
{
/*replace the previous one with one position behind*/
    a[i-1]=a[i];
   
}
    a[length-1]=b;
    a[length]='a';
    a[length+1]='y';
    a[length+2]='\0';
    printf("Pig Latin: %s\n", a);
    return 0;

}
/*need terminator to end char a at a[length+1]*/
