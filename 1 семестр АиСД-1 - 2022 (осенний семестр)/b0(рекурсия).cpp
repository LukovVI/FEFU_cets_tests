#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;


ifstream ifs ("input.txt");
ofstream ofs ("output.txt");

void b2(int n, int p, vector<string> s){
    s[p] = "0";
    if (p == n-1){
        for(int i = 0; i < n; i ++){
            ofs << s[i];
        }
        ofs << endl;
    }
    else{
        b2(n, p+1, s);
    }
    s[p] = "1";
    if (p == n-1){
       for(int i = 0; i < n; i ++){
            ofs << s[i];
        }
        ofs << endl;
    }
    else{
        b2(n, p+1, s);
    }
}

int main()
{
    
    int n;
    int k;
    
    vector<string> s = {};
    
    ifs >> n;
    
    for(int j = 0; j < n; j++){
        s.push_back("0");
    }
    
    b2(n, 0, s);
    

    return 0;
}
