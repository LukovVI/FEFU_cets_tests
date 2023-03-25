#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

int sortr(vector<long long> & v, long long start, long long end){
    long long m = start, p;
    if(end-start < 1) return 0;
    
    long long x = v[start];
    
    for(int i = start+1; i<=end; i++) if(v[i] < x) m++;
    
    p = v[m];
    v[m] = x;
    v[start] = p;
    long long s1 = start, s2 = m+1;
    while(s1<m && s2 <=end){
        if(v[s1]>=x){
            while(v[s2] >=x && s2 < end) s2++;
            p = v[s1];
            v[s1] = v[s2];
            v[s2] = p;
        }
        s1++;
    }
    sortr(v, start, m-1);
    sortr(v, m+1, end);
    return 0;
}

int main()
{
    long long n, p;
    vector<long long> v {};
    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");
    
    ifs >> n;
    
    for(int i = 0; i < n; i++){
        ifs >> p;
        v.push_back(p);
    }
    
    sortr(v, 0, n-1);
    
    for(int i = 0; i < n; i++) ofs << v[i] << " ";
    return 0;
}
