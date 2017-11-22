#include <stdio.h>
/*display the error status like 
$ echo $?
2*/

int main()
{
    float latitude;
    float longitude;
    char info[80];
    int started = 0;

    puts("Data=[");
    // [^\n] collect every character up to the end of the line
    //scanf function returns the number of values it was able to read
    while (scanf("%f ,%f, %79s[^\n]", &latitude,&longitude, info)==3)
    {
        if (started)
            printf(",\n");
        else 
            started= 1;
            if (latitude<-90 || latitude>90 )
            {
                printf("Invalid latitude: %t\n", latitude);
                return2;
            }
            else if (longitude<-180 || longitude>180)
            {
                printf("Invalid longitude: %t\n", longitude);
/*The first return statement that is executed will 
terminate the function and its value will be used.
However, there can obviously be multiple execution 
paths - and they can return different values. Actually in 
a non-void function every possible execution path has to return something. 
The easiest way to achieve this is obviously having a return statement 
at the very end of the function.*/
                return 2;
            }
            printf("{latitude : %f, longitude: %f, info: '%s'}", latitude,longitude,info);
    }
    puts("\n]");
    return 0;
    
}

