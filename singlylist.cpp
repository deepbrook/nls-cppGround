
#include <iostream>
#include<cstdlib>
using namespace std;


struct ListItem {
    unsigned int data;
    struct ListItem *next;
};

ListItem* push(int value, ListItem* head)
{
    ListItem *newEntry; // register a name with your machine for a var
    newEntry = (ListItem*)malloc(sizeof(struct ListItem)); // reserve memory for an object with the size of a listItem
    newEntry->data = value;
    newEntry->next = head;
    head = newEntry;
    return newEntry;
}

int main()
{

    ListItem *head = NULL; //empty linked list, *next is null
    ListItem *A; //init temp node
    A = (ListItem*)malloc(sizeof(struct ListItem)); //allocate memory for list item
    A->data = 4; //store data
    A->next=head; //store adress of pointer head
    head = A; //transfer adress of 'temp' to 'head'

    ListItem *B;
    B = push(17,head);

    cout << B;


}


