#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

int main()
{
    vector<int> v = {0}, v1, v2;
    int n, x, x1, res1 = 0, res2 = 0, res, r;
    
    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");
    
    ifs >> n;
    
    for(int i = 0; i<n; i++){
        ifs >> x;
        v.push_back(x);
    }
    
    v.push_back(0);
    v1 = v;
    v2 = v;
    for(int i = 1; i <n+1; i+=2){
        if(v1[i-1]>=v1[i]||v1[i+1]>=v1[i]){
            r = max(v1[i-1], v1[i+1])+1 - v1[i];
            v1[i] += r;
            res1 += r;
        }
    }
    
    for(int i = 2; i <n+1; i+=2){
        if(v2[i-1]>=v2[i]||v2[i+1]>=v2[i]){
            r = max(v2[i-1], v2[i+1])+1 - v2[i];
            v2[i] += r;
            res2 += r;
        }
    }
    
    if(res1>res2){
        v1 = v2;
    }
    
    for(int i = 1; i <= n; i++){
        ofs << v1[i] << " ";
    }
    
    return 0;
}