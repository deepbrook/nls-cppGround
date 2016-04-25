#include <studio.h>

int gdc(int u, int v)
    {
        int t;
        while(u > 0){
            if (u < v)
            { t = u; u = v; v = t;}
            u = u-v;
        }
        return v;
    }