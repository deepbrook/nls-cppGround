
#include <iostream>
#include <string>
#include<cstdlib>
#include<cstdint>
using namespace std;

#define HASH_DEFAULT_LENGTH 128
#define WIDTH  (8 * sizeof(crc))
#define TOPBIT (1 << (WIDTH - 1))
#define POLYNOMIAL 0xD8  /* 11011 followed by 0's */
typedef uint8_t crc;

//Start of hashing magic
crc  crcTable[256];
void
crcInit(void)
{
    crc  remainder;


    /*
     * Compute the remainder of each possible dividend.
     */
    for (int dividend = 0; dividend < 256; ++dividend)
    {
        /*
         * Start with the dividend followed by zeros.
         */
        remainder = dividend << (WIDTH - 8);

        /*
         * Perform modulo-2 division, a bit at a time.
         */
        for (uint8_t bit = 8; bit > 0; --bit)
        {
            /*
             * Try to divide the current data bit.
             */
            if (remainder & TOPBIT)
            {
                remainder = (remainder << 1) ^ POLYNOMIAL;
            }
            else
            {
                remainder = (remainder << 1);
            }
        }

        /*
         * Store the result into the table.
         */
        crcTable[dividend] = remainder;
    }

}   /* crcInit() */

crc
crcFast(uint8_t const message[], int nBytes)
{
    uint8_t data;
    crc remainder = 0;


    /*
     * Divide the message by the polynomial, a byte at a time.
     */
    for (int byte = 0; byte < nBytes; ++byte)
    {
        data = message[byte] ^ (remainder >> (WIDTH - 8));
        remainder = crcTable[data] ^ (remainder << 8);
    }

    /*
     * The final remainder is the CRC.
     */
    return (remainder);

}

int hashString(string my_string){

    return crcFast((const uint8_t*)my_string.c_str(), my_string.length());
};

//end of hashing magic.


struct hst_item{
    string data;
    hst_item *next; //stores hash%table_size of next item in list;
};

struct hashstack{
    int table_size;
    hst_item *table; //an array of hash table items
    hst_item *head;
};

string getWithId(const hashstack *table,int id){
    return table->table[id].data;
};





int isInTable(const hashstack *table, string a){
    if(table->table[hashString(a) % table->table_size].data == a){
        return hashString(a)% table->table_size;
    }
    else{
        return 0;
    }
};

int pushHashStack(hashstack *my_hashstack, string data){
    int hash = hashString(data) % my_hashstack->table_size; //string = CRC'd % int - ?

    if (my_hashstack->head == NULL){
        //cout << "Head is NULL! Adding item and setting new head \n" << "Filling it with \'" <<data<<"\'..\n";;

        my_hashstack->table[hash].data = data;
        my_hashstack->table[hash].next = NULL;
        my_hashstack->head = &my_hashstack->table[hash];
        return hash;
    }
    else{
        if (my_hashstack->table[hash].data == string()){
            //cout << "Bucket is empty! Filling it with \'" <<data<<"\'..\n";
        }
        else{
            //cout << "Bucket not empty; overwriting previous entry!";
        };

        my_hashstack->table[hash].data = data; //store the address of the hash table item
        my_hashstack->table[hash].next = my_hashstack->head;
        my_hashstack->head = &my_hashstack->table[hash];
        return hash;
    }
};
string popHashStack(hashstack *my_hashstack){


    if(my_hashstack->head == NULL){
        return string();
    }
    else{
        string data = my_hashstack->head->data;
        int hash = hashString(data) % my_hashstack->table_size;

        if(my_hashstack->table[hash].next == NULL){
            my_hashstack->head = NULL;

        }
        else{

            hst_item *newHead = my_hashstack->table[hash].next;
            my_hashstack->head = newHead;

        }
        my_hashstack->table[hash].data = string();
        my_hashstack->table[hash].next = NULL;
        return data;
    };
};


#if 0
int main(){
    //do stuff.
    crcInit();

    hashstack my_table;
    my_table.table_size = HASH_DEFAULT_LENGTH;
    my_table.head = NULL;
    my_table.table= (hst_item*)malloc(my_table.table_size*sizeof(hst_item));
    my_table.table= new hst_item[HASH_DEFAULT_LENGTH];
    string a = string();
    for (int i = 0; i < my_table.table_size; i++){
        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     my_table.table[i] = new ht_item();
        my_table.table[i].data=a;
    };


    int id_this;
    pushHashStack(&my_table, "This");
    pushHashStack(&my_table, "That");
    pushHashStack(&my_table, "notThis");
    pushHashStack(&my_table, "notThat");
    cout << hashString("This")%my_table.table_size << "\n";
 //   cout <<"Retrieving using getWithID(): "<< getWithId(&my_table, id_this)<< "\n";
    cout << isInTable(&my_table, "This")<< "\n";
    cout << isInTable(&my_table, "That")<< "\n";

    for (hst_item *x = my_table.head; x!=NULL; x = x->next){
        cout << x->data << "," << x->next << "\n";

    };
    cout << popHashStack(&my_table);
    cout << popHashStack(&my_table);
    cout << popHashStack(&my_table);
    cout << popHashStack(&my_table);
    cout << popHashStack(&my_table);

    for (int i = 0; i<100000; i++){
        for(int a = 0; a<50; a++){
            pushHashStack(&my_table, "String");
        };
        for(int a = 0; a<25; a++){
            popHashStack(&my_table);
        };
        for(int a = 0; a<50; a++){
            pushHashStack(&my_table, "String");
        };
        for(int a = 0; a<75; a++){
            popHashStack(&my_table);
        };
    };
}
#endif

