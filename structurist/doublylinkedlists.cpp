

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
    (*list)->tail->previous->next = NULL;
    free((*list)->tail);
    (*list)->tail = newTail;
    return val;
}

int main()
{

    List *dllist;
    dllist= (List*)malloc(sizeof(struct List));
    dllist->head = NULL;
    dllist->tail = NULL;

    push(4,&dllist);
    push(17,&dllist);
    push(19,&dllist);
    pop(&dllist);
    push(27,&dllist);

    for (ListItem2* i = dllist->head; i!= NULL; i = i->next){
        cout << i->data;
    }
    for (ListItem2* i = dllist->tail; i!= NULL; i = i->previous){
        cout << "\n" <<i->data;
    }


}


