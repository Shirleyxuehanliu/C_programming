#include <stdio.h>

typedef struct island
{
    char *name;
    char *opens;
    char *closes;
    struct island *next; 
}island;


void display (island *start)
{
    island *i=start;
    for (;i!=NULL; i=i->next)
    {
        printf("Name: %s\n open: %s-%s\n",i->name , i->opens ,i->closes );
    }
}
int main()
{
    //can not put &craggy in this line without declare it
    island craggy;
    island Amity={"Amity", "9AM","5PM",&craggy};
    craggy.name="Craggy";
    craggy.opens="8AM";
    craggy.closes="4pm";
    craggy.next=NULL;
    // craggy={"Craggy","8AM","4PM",NULL}; 
    display(&Amity);
    return 0;
}




char *opens;
opens="shirley"

island i;
i.opens

island *i;
i -> opens or (*i).opens

