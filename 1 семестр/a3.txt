#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

int main()
{
    int k;
    int yd = 0;
    int p = 0;
    int pi = 0;
    int res = 0;
    int del = 1;
    
    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");
    ifs >> k;
    while (k%del != k){
        del = del * 10;
        p++;
    }
    for (int i = 0; i< k ; i++){
        yd = 0;
        pi = 0;
        del = 1;
        while(i%del != i){
            del = del * 10;
            pi++;
        }
        for (int j = 0; j < pi; j++){
            yd = yd + ((i/(int)pow(10, j))%10)*pow(10, pi-j-1);
        }
        if (yd + i == k){
            res++;
        }
    }
    ofs << res;
}
