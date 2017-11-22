#include <stdio.h>
#include <unistd.h>

//oderpizza -d now -t pineapple blueberry
//-t needs to be followed by an extra argument,  getopt()will point to that argument with optarg variable
//optind stores the number of strings read from the command line
int main (int argc, char *argv[])
{
    char delivery ="";
    int thick =0;
    int count=0;
    char ch;
//argc is the string lenth= file name + number of arguments
//getopt function read in one string at a time and pass it to ch
    while ((ch=getopt(argc, argv, "d:t"))!=EOF)
        switch(ch)
        {  case 'd':
            delivery=optarg;
            break;
           case 't':
            thick=1;
           default:
            fprint(stderr, "Unknow option: %s\n", optarg);
            return 1;
        }
//optind stores number of options matches "d:t"
        argc-=optind;
        argv+=optind;
        if (thick)
            puts("Thick crust.");
        if (delivery[0])
            printf("To be delivered %s.\n", delivery);
            puts ("Ingredients:");
        for(count=0 ; count< argc ; count++)
        puts(argv[count]);
        return0;
}