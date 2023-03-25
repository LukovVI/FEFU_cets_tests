#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>

using namespace std;



int main()
{
    int k;
    int rev;
    int p = 0;
    int del = 1;
    vector<int> mas = {};
    
    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");
    ifs >> k;
    
    while (k%del != k){
        del = del * 10;
        p++;
    }
    
    for (int i = 0; i< p; i++){
        mas.push_back((k/(int)pow(10, i))%10);
    }
    for (int i = 0; i <p-1; i++){
        for (int j = 0; j<p-i-1; j++){
            if (mas[j]< mas[j+1]){
                rev = mas[j];
                mas[j]= mas[j+1];
                mas[j+1] = rev;
            }
        }
    }
    for (int i = 0; i < p-1; i ++){
        ofs << mas[i];
    }
    ofs << endl << mas[p-1];
    
    return 0;
}
