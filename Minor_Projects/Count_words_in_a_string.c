/*Count Words in a String – Counts the number of individual words in a string. For added complexity read these strings in from a text file and generate a summary.*/
#include <stdio.h>
#include <string.h>
int main(){
// array to store data//
    char a[100];
//Define a file ptr//
    FILE *fp;
//Open a local file//
    fp=fopen("/Users/liushirley/Dropbox/Course/C_language/Array/Minor_Projects/text.txt", "r+");
//Get data from ptr and store into array// 
    fscanf(fp,"%s",a);
    printf("%s\n", a);
//While loop to count length//
    int i=0;
    int count=0;
    while(a[i]!=0){
        i++;
        count++;
    }
    printf("%d\n",count);
//Close the file//
    fclose(fp);
    return 0;
    
}