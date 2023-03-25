#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


int main()
{
    vector<long long> v = {}, vall = {}, vtrak = {0};
    int n, ns, l = 0, r = 0;
    long long res, p, m;
    string ch, st;
    
    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");
    
    ifs >> n;
    
    for(int i = 0; i < n; i++){
        ifs >> p;
        vall.push_back(p);
    }
    
    ifs >> ns;
    ifs >> st;
    v.push_back(vall[0]);
    res = v[0];
    p = 0;
    for(int i = 0; i<ns; i++){
        ch = st[i];
        if(ch == "R"){
            r++;
            m = vall[r];
            v.push_back(m);
            vtrak.push_back(r);
            if(m>=res){
                res = m;
                p = r;
            }
            for(int j = v.size()-2; j > l; j--){
                if(v[j] <= m){
                    v.erase(v.begin()+j);
                    vtrak.erase(vtrak.begin()+j);
                }
                else{
                    break;
                }
            }
            ofs << res << " ";
        }
        else{
            if(vtrak[l+1]-vtrak[l] > 1){
                if(vtrak[l] == p){
                    res = vall[vtrak[l+1]];
                    p = vtrak[l+1];
                }
                vtrak[l]++;
                v[l] = vall[vtrak[l]];
            }
            else{
                l++;
                res = vall[vtrak[l]];
                p = vtrak[l];
            }
            ofs << res << " ";
        }
    }
    return 0;
    
}