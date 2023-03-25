#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

vector<long long> v = {0};

int finder(int start, int end, long long x){
    int f = (start + end)/2;
    long long y;
    y = v[f]-v[start];
    if(v[f] == x){
        return f;
    }
    else if(start == end){
        return 0;
    }
    else if(v[f] > x){
        return finder(start, f, x);
    }
    else{
        return finder(f+1, end, x);
    }
    return 0;
}

int main()
{   
    int p, l, r, g, n;
    long long s = 0, ms, res = 0, m;
    bool br = false;
    
    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");
    
    ifs >> n;
    
    for(int i = 0; i < n; i++){
        ifs >> p;
        s += p;
        v.push_back(s);
    }
    
    p = 0;
    for(int j = 1; j<=n-1; j++){
        br = false;
        p = max(p, j);
        for(int i = n-1; i >= p; i--){
            ms = v[i]-v[j-1];
            if(res >= ms){
                break;
            }
            if(ms <= v[n]/2){
                g = finder(i+1, n, v[i]+ms);
                if(g != 0){
                    res = ms;
                    l = j;
                    m = i;
                    r = g;
                    br = true;
                    p = i+1;
                    break;
                }
            }
            if(br){
                break;
            }
        }
        
    }

    if(res > 0){
        ofs << l << " " << m << " " << r;
    }
    else{
        ofs << -1;
    }
    return 0;
}
