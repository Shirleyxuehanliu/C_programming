island* create(char *name)
{
//i is the pointer that points the memory address used to store name 
    island *i=mallox(sizeof(island));
//copy the name string to the heap 
    i->name=strdup(name);
    i->opens="09:00";
    i->closes="17:00";
// empty pointer for next item
    i->next=NULL;
    return i;
}

//Define *start
island *start=NULL;
island *i=NULL;
island *next=NULL;
char name[80];
//read island name from stdin until no input
//when each iteration is over, reset 
for(; fgets(name,80,stdin)!=NULL;i=next)
{
//next is the malloc point that points to the 
    next=create(name);
    if(start==NULL)
    start=next;
    if(i!=NULL)
    i->next=next;
}
display(start);
void release(island *start)
{
    island *i =start;
    island *next=NULL;
    for (; i!=NULL, i=next)
    {
        next=i->next;
//free the string copied on heap using strup() function
        free(i->name)；
// free the island strucure
        free(i);
//if free(i) before i->name, you could find i->name then
    }
}