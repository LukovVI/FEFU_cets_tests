#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int finder(vector<long long> & v, vector<int> & vi, int x){
    long long start = 0, end = vi.size();
    while(start < end){
        long long f = start + (end - start)/2;
        if(v[vi[f]] < v[x]) end = f;
        else start = f+1;
    }
    return start;
}

int main()
{
    vector<long long> v {};
    vector<int> vi {};
    long long a;
    int n;
    
    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");
    
    ifs >> n;
    
    ifs >> a;
    v.push_back(a);
    
    for(int i = 1; i < n; i++){
        ifs >> a;
        v.push_back(a);
        vi.insert(vi.begin() + finder(v, vi, i-1), i-1);
        for(int j = vi.size()-1; j>=0; j--){
            if (v[vi[j]] < a){
                v[vi[j]] = a;
                vi.erase(vi.begin()+j);
            }
            else break;
        }
    }
    
    for(int i = 0; i < n; i++){
        ofs << v[i] << " ";
    }
    
    return 0;
}
