#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

int main()
{
    int n, l, r, s;
    vector<int> v = {0};
    
    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");
    
    ifs >> n;
    
    s = 0;
    
    for(int i = 0; i<n; i++){
        ifs >> l;
        s += l;
        v.push_back(s);
    }
    
    ifs >> n;
    
    for(int i = 0; i<n; i++){
        ifs >> l >> r;
        ofs << v[r]-v[l-1] << " ";
    }
    
    return 0;
}
