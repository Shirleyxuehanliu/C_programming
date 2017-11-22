/*Count Vowels – Enter a string and the program counts the number of vowels in the text. 
For added complexity have it report a sum of each vowel found.*/
#include <stdio.h>
#include <string.h>
int main()
{
    char a[100];
    printf("Enter your string: \n");
    scanf ("%s",a);
    int length;
/*calculate length of the string*/
    length=strlen(a);
    int i;
/*define an array to store each vowel numbers*/
    int b[5]={0};

    for(i=0;i<length;i++)
    {
/*convert capital letter to numeric*/
        if (64<a[i]&&a[i]<91)
        {
             a[i]=a[i]-64;
        }
 /*convert small letter to numeric*/
       if (96<a[i]&&a[i]<123)
        {
            a[i]=a[i]-96;
        }
 /*set original numeric numbers and special symbols to 0*/
        if (a[i]<64 && a[i]>123)
        {
            a[i]=0;
         }
        switch(a[i])
        {
            case 1:
            b[0]++;
            break;
            case 5:
            b[1]++;
            break;
            case 9:
            b[2]++;
            break;
            case 15:
            b[3]++;
            break;
            case 21:
            b[4]++;
            break;
        } 

    }
    printf("a: %d\n e: %d\n i: %d\n o: %d\n u: %d\n", b[0],b[1],b[2],b[3],b[4]);
    return 0;
}
