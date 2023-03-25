#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;
string b2(int i, int n){
    string s = "";
    while(i > 0){
        if(i%2 == 1){
            s = "1" + s;
        }
        else{
            s = "0" +s;
        }
        i = i/2;
    }
    while(s.length() < n){
        s = "0" + s;
    }
    return s;
}

int main()
{
    int n;
    int k;
    
    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");
    
    ifs >> n;
    k = pow(2, n);
    for(int i = 0; i < k; i ++){
        ofs << b2(i, n) << endl;
    }
    

    return 0;
}
