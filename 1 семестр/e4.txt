#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

int sortr(vector<vector<long long>> & v, long long start, long long end){
    long long m = start, k = (start+end)/2;
    vector<long long> p;
    
    if(end-start < 1) return 0;
    
    long long x = v[k][0];
    
    for(long long i = start; i<=end; i++) if(v[i][0] < x) m++;
    
    p = v[m];
    v[m] = v[k];
    v[k] = p;
    
    long long s1 = start, s2 = m+1;
    while(s1<m && s2 <=end){
        if(v[s1][0]>=x){
            while(v[s2][0] >=x && s2 < end) s2++;
            
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
    vector<vector<long long>> citi = {};
    vector<vector<long long>> citi1 = {};
    vector<vector<long long>> shel = {};
    long long n, m, cn, sm, sp = 0;
    
    ifstream ifs ("shelter.in");
    ofstream ofs ("shelter.out");
    
    ifs >> n;
    for(long long i = 0; i < n; i++){
        ifs >> cn;
        citi.push_back({cn, i});
    }
    
    ifs >> m;
    for(long long i = 1; i <= m; i++){
        ifs >> sm;
        shel.push_back({sm, i});
    }
    
    citi1 = citi;
    
    sortr(citi, 0, n-1);
    
    sortr(shel, 0, m-1);
    
    for(long long cp = 0; cp < n; cp++){
        while(sp < m-1 && abs(citi[cp][0] - shel[sp][0]) > abs(citi[cp][0] - shel[sp+1][0])){
            sp++;
        }
        citi1[citi[cp][1]][1] = shel[sp][1];
    }
    
    for(long long i = 0; i < n; i++){
        ofs << citi1[i][1] << " ";
    }
    
    return 0;
}
