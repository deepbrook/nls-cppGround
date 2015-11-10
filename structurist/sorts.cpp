
#include <iostream>
#include<cstdlib>

using namespace std;

void bubbleSort(int *seq, int l){
    int c = 1;//initial value 1 to kick off while loop
    int tmp;
    while(c > 0){
        c = 0;
        //go through this and sort; if change is made, increment c;
        for(int i = 0; i < l; i++){
            cout<<seq[i] <<","<<seq[i+1]<<"\n";
            if(seq[i] > seq[i+1]){
                tmp = seq[i+1];
                seq[i]= seq[i+1];
                seq[i+1]= tmp;
                c++;
            }
        }
    }

}

int main(){
    int sequence[10] = {9,65,12,16,7,3,48,0,11,4};

    bubbleSort(sequence, 9);
    for(int i = 0; i < 10; i++){
        cout << sequence[i] << ",";
    }

}
