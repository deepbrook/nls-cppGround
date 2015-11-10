

#include <iostream>
#include<cstdlib>
#include <iterator>

using namespace std;

const int arraySize = 10;


struct sl_item{
    int value;
    struct sl_item *next;
    struct sl_item *tlevel;
    struct sl_item *nlevel;
};



struct sl_tree{
    sl_item **head;
    sl_item **cache;
    sl_tree(){
    head = new sl_item *[arraySize+1];
    cache = new sl_item *[arraySize+1];
    }


    void fillCache(int nvalue){
        cout<<"Filling cache..";
        int level = 0;

        for(sl_item *item = head[level];level <=arraySize;){

                if(item->next == NULL ||  nvalue <= item->next->value){
                    cache[level]= item; //update cache
                    item = item->nlevel; //move down
                    cout << ",level: " << level;
                    level++; //update level
                }
                else if(item->next != NULL && nvalue > item->next->value){
                    item = item->next;
                    cout << "moving right\n";
                    //move right;
                }


                else{
                cout << "ABORTING!\n";
                abort();
                }


        }
     for(int i = 0; i <= arraySize; i++){
        cout << cache[i]->value <<",";
     }
     cout << "\n";
    }

    bool has(int nvalue){
        cout<<"starting has()..\n";
        fillCache(nvalue);
        cout<<"\nhas() completed.\n";
        return cache[arraySize]->next != NULL && cache[arraySize]->next->value == nvalue;
    }




    void insert(int nvalue){
        cout << "\n\ninserting "<< nvalue << "..";
        //cout << nvalue << " = "<< has(nvalue) << "\n";
        if (has(nvalue) == false){

            //Build new Item


            //add new item to skiplist
            for(int i = arraySize; i >= 0; i--){ //move up through cache from end.
                sl_item *newItem = new sl_item();

                newItem->value = nvalue;
                newItem->next = NULL;
                newItem->tlevel = NULL;
                newItem->nlevel = NULL;

                sl_item *item = cache[i];

                newItem->next = item->next;
                item->next = newItem;
                if(i != arraySize){
                    newItem->nlevel = cache[i+1]->next;
                }

                //cache[arraySize]->next->tlevel = newItem; //update tlevel at bottom


                //flip a coin; return if false;
                if(rand()%2 == 0){
                    cout << "done.\n";
                    return;
                }


            }
        }
    }

};



int main(){
    sl_tree *root = new sl_tree();

    //Add head array items
    for(int i = 0; i<arraySize+1; i++){
        sl_item *newItem = new sl_item();
        newItem->value = -9000;
        newItem->next = NULL;
        newItem->tlevel = NULL;
        newItem->nlevel = NULL;

        root->head[i] = newItem;
        if(i != 0){
            root->head[i-1]->nlevel = root->head[i];
        }
        else if(i == arraySize){
            root->head[i]->tlevel = root->head[0];

        }
    }


    for(sl_item *item = root->head[0]; item->nlevel != NULL; item = item->nlevel){
        cout << item << "\n";
    }

    srand(time(NULL));
    for(int i = 0; i < 100; i++){
        root->insert(rand()% 11);
    }


    for(sl_item *head = root->head[0]; head != NULL; head = head->nlevel){
        cout << "Values for" << head <<" are: ";
        for(sl_item *item = head; item != NULL; item = item->next){
            cout << item->value << ",";
        }
        cout <<"\n";
    }


    delete(root); //I know. I still would have to delete all the items in the array via hand first. Duly noted.
}



