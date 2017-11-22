#include <stdio.h>
#include <string.h>

char s0[]='Shirley went to school this morning.';
char s1[]= "Jeff went to work by a car.";

//Concatenate tow strings

char  a0= strcat (s0, s1);

// Fing the location of a string inside another string

strstr(s0, "Shirley");

//Find the location of a character inside a string

strchr(s1, 'J');

//Fing the length of a string

strlen(s);

//Compare two strings
strcmp(s0,s1);

//copy one string to another

char s2=strcpy(s1);


void print_reverse (char *s)
{
//size_t is just an integer used to store the sizes of things
    size_t len=strlen(s);
    char *t= s+len -1;
    while (t >= s){
        print ("%c", *t);
        t=t-1;
    }
    puts("");



}