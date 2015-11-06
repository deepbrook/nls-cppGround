#include <iostream>
#include <string>
#include<cstdlib>
#include<cstdint>
using namespace std;
#if 0
#define HASH_DEFAULT_LENGTH 128
#define WIDTH  (8 * sizeof(crc))
#define TOPBIT (1 << (WIDTH - 1))
#define POLYNOMIAL 0xD8  /* 11011 followed by 0's */
typedef uint8_t crc;

//Start of hashing magic
crc  crcTable[256];

void crcInit(void){
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

crc crcFast(uint8_t const message[], int nBytes){
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


struct ht_item{
    int id;
    string data;
};

int getId(ht_item **item){
    return (*item)->id;
}

struct hashtable{
    int table_size;
    ht_item *table; //an array of hash table items

};

string getWithId(const hashtable *table,int id){
    return table->table[id].data;
};
int isInTable(const hashtable *table, string a){
    if(table->table[hashString(a) % table->table_size].data == a){
        return hashString(a);
    }
    else{
        return 0;
    }
};

int addToTable(const hashtable *my_hashtable, string data){
    int hash = hashString(data) % my_hashtable->table_size; //string = CRC'd % int - ?

    if (my_hashtable->table[hash].data == string()){
        cout << "Bucket is empty! Filling it with \'" <<data<<"\'..\n";
    }
    else{
        cout << "Bucket not empty; overwriting previous entry!";
    };

    my_hashtable->table[hash].data = data; //store the address of the hash table item

    return hash;
};

#endif
#if 0

int main(){
    //do stuff.
    hashtable my_table;
    crcInit();
    my_table.table_size = HASH_DEFAULT_LENGTH;
    //my_table.table= (ht_item*)malloc(my_table.table_size*sizeof(ht_item));
    my_table.table= new ht_item[HASH_DEFAULT_LENGTH];
    string a = string();
    for (int i = 0; i < my_table.table_size; i++){
        //                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     my_table.table[i] = new ht_item();
        my_table.table[i].data=a;
    };
    int id_this;
    id_this = addToTable(&my_table, "This");
    cout << hashString("This") << "\n";
    cout <<"Retrieving using direct method.."<< my_table.table[id_this].data<< "\n";
    cout <<"Retrieving using getWithID().."<< getWithId(&my_table, id_this)<< "\n";
    cout <<"Retrieving using hashString() as ID"<< my_table.table[hashString("This")%my_table.table_size].data<< "\n";
    cout << isInTable(&my_table, "This")<< "\n";
    cout << isInTable(&my_table, "NotThis")<< "\n";
}

#endif

