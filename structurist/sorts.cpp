
#include <iostream>
#include<cstdlib>
#include<string.h>
using namespace std;

void bubbleSortSlow(int *seq, int l){
    int c = 1;//initial value 1 to kick off while loop
    int tmp;
    while(c > 0){
        c = 0;
        //go through this and sort; if change is made, increment c;
        for(int i = 0; i < l-1; i++){

            if(seq[i] > seq[i+1]){
                tmp = seq[i+1];
                seq[i+1]= seq[i];
                seq[i]= tmp;
                c++;
            }
        }
    }

}

void bubbleSortOpt(int *seq, int l){
    int c = 1;//initial value 1 to kick off while loop
    int tmp;

    int p = 1; //tracker for index
    while(c > 0){
		c = 0;
		for (int i = 0; i < l - p; i++)
		{
			if (seq[i] > seq[i + 1])
			{
                tmp = seq[i+1];
                seq[i+1]= seq[i];
                seq[i]= tmp;
                c++;
			}
		}
		p++;
    }
}

static inline void cmp(int *a, int *b)
{
    int tmp;
    if(*a < *b){return;}
    else{tmp = *b; *b = *a; *a = tmp; return;}
}


void sn2(int *input){
    #define CMP(x, y)   cmp(&input[x], &input[y])
    CMP(0,1);
    return;
}

void sn3(int *input){
    #define CMP(x, y)   cmp(&input[x], &input[y])
    CMP(1,2);
    CMP(0,2);
    CMP(0,1);

    return;
}

void sn4(int *input){ //is element of unique items
    #define CMP(x, y)   cmp(&input[x], &input[y])
    CMP(0,1);CMP(2,3);
    CMP(0,2); CMP(1,3);
    CMP(1,2);

    return;
}

void sn5(int *input){
    #define CMP(x, y)   cmp(&input[x], &input[y])
    CMP(0,1);CMP(3,4);
    CMP(2,4);
    CMP(2,3);CMP(1,4);
    CMP(0,3);
    CMP(0,2);CMP(1,3);
    CMP(1,2);

    return;
}

void sn6(int *input){
    #define CMP(x, y)   cmp(&input[x], &input[y])
    CMP(1,2);CMP(4,5);
    CMP(0,2);CMP(3,5);
    CMP(0,1);CMP(3,4);CMP(2,5);
    CMP(0,3);CMP(1,4);
    CMP(2,4);CMP(1,3);
    CMP(2,3);

    return;
}
void sn7(int *input){
    #define CMP(x, y)   cmp(&input[x], &input[y])
    CMP(1,2);CMP(3,4);CMP(5,6);
    CMP(0,2);CMP(3,5);CMP(4,6);
    CMP(0,1);CMP(4,5);CMP(2,6);
    CMP(0,4);CMP(1,5);
    CMP(0,3);CMP(2,5);
    CMP(1,3);CMP(2,4);
    CMP(2,3);

    return;
}
void sn8(int *input){
    #define CMP(x, y)   cmp(&input[x], &input[y])
    CMP(0,1);CMP(2,3);CMP(4,5);CMP(6,7);
    CMP(0,2);CMP(1,3);CMP(4,6);CMP(5,7);
    CMP(1,2);CMP(5,6);CMP(0,4);CMP(3,7);
    CMP(1,5);CMP(2,6);
    CMP(1,4);CMP(3,6);
    CMP(2,4);CMP(3,5);
    CMP(3,4);

    return;
}
void sn9(int *input){
    #define CMP(x, y)   cmp(&input[x], &input[y])
    CMP(0,1);CMP(2,3);CMP(4,5);CMP(7,8);
    CMP(0,2);CMP(1,3);CMP(6,8);
    CMP(1,2);CMP(6,7);CMP(5,8);
    CMP(4,7);CMP(3,8);
    CMP(4,6);CMP(5,7);
    CMP(5,6);CMP(2,7);
    CMP(0,5);CMP(1,6);CMP(3,7);
    CMP(0,4);CMP(1,5);CMP(3,6);
    CMP(1,4);CMP(2,5);
    CMP(2,4);CMP(3,5);
    CMP(3,4);

    return;
}

void sortNetwork(int *a, int l){

    if(l==8){sn8(a);}
    else if(l==6){sn6(a);}
    else if(l==4){sn4(a);}
    else if(l==2){sn2(a);}

}

int doSplit(int a){
    int step;
    if(a/2 % 2 == 0 && a/2 <= 8){
        step = a/2;
        return step;
    }
    else if(a/2 % 2 == 0 && a/2 > 8)
        step = doSplit(a/2);
    else{abort();}
}



void mergeSort(int *left, int *right, int size_left, int size_right, int *target){
    #define CMP(x, y)   cmp(&input[x], &input[y])
    int a = 0,b = 0; // index on left and right
    int c = 0; //index on target



    while(true){
        if(b==size_right){
            // add remaining elements of left to target and return;
            while(a < size_left){
                target[c] = left[a];
                a++;
                c++;
            }
            return;
        }
        else if(a==size_left){
            // add remaining elements of left to target and return;
            target[c] = right[b];
            b++;
            c++;
            return;
        }
        else if(left[a] < right[b]){
            // add left & ++
            target[c] = left[a];
            a++;
            c++;
        }
        else if(left[a] > right[b]){
            //add right and ++
            target[c] = right[b];
            b++;
            c++;
        }
        else{
            target[c++] = left[a++];
            target[c++] = right[b++];
        }
    }


}

void mergeThis(int *seq, int l){
    int remaining = l;
    int pos = 0; //is incremented with step, to serve as start index for sortNetwork()
    //figure out split

    int step = 8;
    //Pre Sort Chunks or array first;
    cout<< "Sorting chunks..\n";
    while(l - pos > 1) //while we're not at the end
    {
        if(pos + step <= l){
            sortNetwork(seq+pos, step);
            pos += step;
        }
        else if(step <= 1){ //There are 1 or less items in the list left; break;
            break;
        }
        else{
            step -= 2;
        }
    }

 //   for(int i = 0; i < l; i++){cout << seq[i] << ",";};cout<<"\n";

    //Now MergeSort;
    //traverse list in steps of 8 and merge them to 16 blocks;do this, as long as we do not over
    cout <<"MergeSorting..\n";
    step = 8; //reset step counter;
    pos = 0;
    bool done = false;

    //int target[l];
    int *target = new int [l];

    while(step * 2 <= l){

        while(pos + (step * 2) <= l){
//            if(pos+(step*2) <=l){
                mergeSort(seq+pos, seq+(pos+step),step, step, target);
                pos += step * 2;
 //               cout<<pos << "," << step<<"\n";
        }
        memcpy(seq, target, pos*sizeof(*seq));
  //      for(int i = 0; i < l; i++){cout << target[i] << ",";};cout<<"\n";
        step *= 2;
        pos = 0;
    }
 //   cout<<l-step;
    mergeSort(seq, seq + step, step, l - step, target);



    memcpy(seq, target, sizeof(target));
  //  for(int i = 0; i < l; i++){cout << seq[i] << ",";};cout<<"\n";




}

int main(){
    int sequence[] = {9,65,12,16,7,3,48,0,11,4};
    #define countof(x)  (sizeof(x) / sizeof(*x))
    countof(sequence);

    bubbleSortOpt(sequence, 10);
    for(int i = 0; i < 10; i++){
        cout << sequence[i] << ",";
    }
    cout << "\n";

    bubbleSortSlow(sequence, countof(sequence));
    for(int i = 0; i < 10; i++){
        cout << sequence[i] << ",";
    }
    cout << "\n";

    int seqA[4] = {4,2,8,7};
    sn4(seqA);
    for(int i = 0; i < 4; i++){
        cout << seqA[i] << ",";
    }
    cout << "\n";

    int seqB[4] = {5,3,9,1};

    sn4(seqB);
    for(int i = 0; i < 4; i++){
        cout << seqB[i] << ",";
    }
    cout << "\n";

    int sequence2[] = {9,65,12,16,7,3,48,0,11,4,77,9,8,55,14,19,5,2};
    mergeThis(sequence2, countof(sequence2));
    for(int i = 0; i < countof(sequence2); i++){
        cout << sequence2[i] << ",";
    }
    cout << "\n";



    srand(time(NULL));

    int *arr = new int [100000000];
    int g= 0;
    for(int i = 0; i < 100000000; i++){
        arr[i] = rand();
    }




}
