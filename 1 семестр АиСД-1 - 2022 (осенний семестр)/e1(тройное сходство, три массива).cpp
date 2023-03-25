#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    vector<unsigned long long> inv1 = {}, inv2 = {}, inv3 = {};
    unsigned long long n1, n2, n3, it1, it2, it3;
    unsigned long long res = 0;
    
    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");
    
    ifs >> n1 >> n2 >> n3;
    
    for(int i = 0; i < n1; i++){
        ifs >> it1;
        inv1.push_back(it1);
    }
    for(int i = 0; i < n2; i++){
        ifs >> it2;
        inv2.push_back(it2);
    }
    for(int i = 0; i < n3; i++){
        ifs >> it3;
        inv3.push_back(it3);
    }
    
    it1 = it2 = it3 = 0;
    while(it1 < n1 && it2 < n2 && it3 < n3){
        while(inv1[it1] > inv2[it2] && it2 < n2 -1) it2++;
        if(inv1[it1] == inv2[it2]) {
            while(inv1[it1] > inv3[it3] && it3 < n3-1) it3++;
            if(inv1[it1] == inv3[it3]) res++;
        }
        it1++;
    }
    
    ofs << res;

    return 0;
}
