
#include <iostream>
#include<cstdlib>
using namespace std;


struct ListItem {
    unsigned int data;
    struct ListItem *next;
};

ListItem* push(int value, ListItem **head)
{
    ListItem *newEntry; // register a name with your machine for a var
    newEntry = (ListItem*)malloc(sizeof(struct ListItem)); // reserve memory for an object with the size of a listItem
    newEntry->data = value;
    newEntry->next = *head;
    *head = newEntry;
    return 0;
}

void push_tail(int value, ListItem **head)
{
    if (*head == NULL){
            push(value, head);
            return;
    }
    for (ListItem *i = *head; i!=0; i = i->next){

        if (i->next == NULL){

            ListItem *newEntry; // register a name with your machine for a var
            newEntry = (ListItem*)malloc(sizeof(struct ListItem)); // reserve memory for an object with the size of a listItem
            newEntry->data = value;
            newEntry->next = NULL;
            i->next = newEntry;
            return;

        };
    };
}

ListItem* pop(ListItem **head)
{
    ListItem* neck = (*head)->next;
    free(*head);
    *head = neck;
    return neck;
}

void pop_tail(ListItem **head)
{
    if (*head == NULL)
    {
        pop(head);
        return;
    };

    for (ListItem *i = *head; i!=0; i = i->next)
    {
        if (i->next->next == NULL){
            ListItem* A = i->next;
            i->next = i->next->next;
            free(A);
            return;
        };
    };

}
#if 0
int main()
{

    ListItem* dllist = NULL;


    for (int i = 0; i < 10; i++){

        for (int y = 0; y <= 10; y++){
            push(y, &dllist);

        };
    };

    for (ListItem *i = dllist; i!=0; i = i->next){

        if (i->next == NULL){

            i->next = dllist->next->next->next;

        };
    };
    for (int i = 0; i<10000; i++){
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

