
#include <iostream>
#include<cstdlib>
using namespace std;


struct ListItem {
    unsigned int data;
    struct ListItem *next;
};


int main(){

ListItem *head = NULL; //empty linked list, *next is null
ListItem *temp; //init temp node
temp = (ListItem*)malloc(sizeof(struct ListItem)); //allocate memory for list item
temp->data = 4; //store data
temp->next=head; //store adress of pointer head
head = temp; //transfer adress of 'temp' to 'head'

cout << "blergh!";

}


