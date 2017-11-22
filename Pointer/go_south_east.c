# include <stdio.h>

void go_sourth_east(int *lat, int *lon)
{
    *lat-=1;
    *lon+=1;
}
int main()
{
    int latitude =32;
    int longitude =-64;

    go_sourth_east(&latitude, &longitude);
    printf ("Avast! Now ar [%i,%i] \n", latitude, longitude);
    return 0;
}