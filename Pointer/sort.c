#include <stdio.h>
#include <string.h>

qsort (void *array,
size_t length,
size_t item_size,
int (*compar)(const void *, const void *));
//sort  integer scores, with the smallest first
int compare_scores(const void* score_a, const void* score_b)
{
//cast the void pointer to an integer pointer and take out the value
    int a =*(int*)score_a;
    int b =*(int*)score_b;
    return a-b;
}
//sort integer scores, with the largest first
int compare_scores(const void* score_a, const void* score_b)
{
    int a =*(int*)score_a;
    int b =*(int*)score_b;
    return b-a;
}
//sort the rectangles in area order, smallest first
typedef struct {
    int width;
    int height;
}rectangle;

int compare_areas (const void* a, const void* b)
{
    rectangle* a_1=(rectangle*)a;
    rectangle* b_1=(rectangle*)b;
    int a_2= a_1->width * a_1->height;
    int b_2= b_1->width * b_1->height;
    return a_2-b_2;
}
//sort a list of names in alphabetical order. case0sensitive
int compare_names(const void* a, const void* b)
{
//type casing from void to char array
    char** a_0=(char**) a;
    char** b_0=(char**) b;
    c=strcmp(*a_0,*b_0);
    return c;
}