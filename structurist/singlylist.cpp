
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


