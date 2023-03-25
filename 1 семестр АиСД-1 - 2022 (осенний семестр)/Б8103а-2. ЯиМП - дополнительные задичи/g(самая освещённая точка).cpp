#include <vector>
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    
    long long n, x, y, res = 0, lol;
    vector<vector<long long>> vv {};
    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");
    
    ifs >> n;
    for(int i = 0; i < n; i++){
        ifs >> x >> y;
        vv.push_back({x, y});
    }
    
    for(int i = -1; i <= 101; i++){
        lol = 0;
        for(int j = 0; j < n; j++){
            if(vv[j][0] - vv[j][1] <= i && vv[j][0]+vv[j][1] > i) lol++;
        }
        if(lol > res) res = lol;
    }
    
    ofs << res;
    
    return 0;
}
