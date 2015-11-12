

#include <iostream>
#include<stdlib.h>
using namespace std;
#include <math.h>



# define M_PI           3.14159265358979323846

bool in_circle(double x, double y){
    //Get t first: x = cos(t) == t = acos(x)
    double t;
    t = acos(x);

    //Get Y of circle next: Circle_Y = sin(t)
    double cy; // Y value of circle
    cy = sin(t);
    //Compare y with Circle_Y;
    if(y < cy){return true;}
    else{return false;}
}





int main(){
    srand(time(NULL));
    int yes = 0, no = 0;
    double x = 0.0, y = 0.0;
    for(int i = 0; i < 100000000; i++){
        x = (double)rand()/(double)RAND_MAX;
        y = (double)rand()/(double)RAND_MAX;
        if(in_circle(x,y)){yes++;}
        else{no++;}

        if(i % 10000 == 0){
            cout << yes<< no<<"Loop number: " << i << ". Estimated size is: " << (double)yes / (double)(yes + no) << "\n" << "Actual Size is: " << M_PI/4.0 <<"\n";
        }
    }

}



