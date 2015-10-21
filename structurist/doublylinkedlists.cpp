

#include <iostream>
#include<cstdlib>
using namespace std;


struct ListItem {
    unsigned int data;
    struct ListItem *next;
    struct ListItem *previous;
};

struct List{
    struct ListItem *head;
    struct ListItem *tail;

};

void push(int value, ListItem **head)
{
    ListItem *newEntry; // register a name with your machine for a var
    newEntry = (ListItem*)malloc(sizeof(struct ListItem)); // reserve memory for an object with the size of a listItem
    newEntry->data = value;
    newEntry->next = *head;
    newEntry->previous = NULL;
    *head->previous = newEntry;
    head = newEntry;
    return;
}


unsigned int pop(ListItem **tail)
{
    ListItem* newTail = *tail->previous;
    unsigned int val = *tail->data;
    *tail->previous->next = NULL;
    free(*tail);
    tail = newTail;
    return val;
}

int main()
{

    ListItem *head = NULL; //empty linked list, *next is null


    push_tail(4,&head);
    push_tail(17,&head);
    push_tail(19,&head);
    pop_tail(&head);
    push_tail(27,&head);

    for (ListItem* i = head; i!=0; i = i->next){
        cout << i->data;
    }


}


