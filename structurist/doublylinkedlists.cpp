

#include <iostream>
#include<cstdlib>
using namespace std;


struct ListItem2 {
    unsigned int data;
    struct ListItem2 *next;
    struct ListItem2 *previous;
};

struct List{
    struct ListItem2 *head;
    struct ListItem2 *tail;

};

void push(int value, List **list)
{
    ListItem2 *newEntry; // register a name with your machine for a var
    newEntry = (ListItem2*)malloc(sizeof(struct ListItem2)); // reserve memory for an object with the size of a listItem
    newEntry->data = value;
    newEntry->next = (*list)->head;
    newEntry->previous = NULL;
    if ((*list)->head != NULL){
            (*list)->head->previous = newEntry;
    }
    if ((*list)->tail == NULL){
        (*list)->tail = newEntry;
    };

   (*list)->head = newEntry;
    return;
}


unsigned int pop(List **list)
{
    if ((*list)->tail == NULL){
        return 0;
    }
    ListItem2* newTail = (*list)->tail->previous;
    unsigned int val = (*list)->tail->data;
    if ((*list)->tail->previous != NULL){
        (*list)->tail->previous->next = NULL;
    }
    else{
        (*list)->head = NULL;
    }
    free((*list)->tail);
    (*list)->tail = newTail;

    return val;
}
#if 0
int main()
{

    List *dllist;
    dllist= (List*)malloc(sizeof(struct List));
    dllist->head = NULL;
    dllist->tail = NULL;


    for (int i = 0; i<100000; i++){
        for(int a = 0; a<50; a++){
            push(a, &dllist);
        };
        for(int a = 0; a<25; a++){
            pop(&dllist);
        };
        for(int a = 0; a<50; a++){
            push(a, &dllist);
        };
        for(int a = 0; a<75; a++){
            pop(&dllist);
        };
    };

}

#endif
