#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    int n, actk = 0;
    vector<vector<int>> vv = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    string st;
    
    ifstream ifs ("function.in");
    ofstream ofs ("function.out");
    
    ifs >> n >> st;
    
    if((int)st[3] - 48){
        for(int i = 0; i < n; i++) ofs << 1;
    }
    else if((int)st[1] - 48){
        ofs << n%2;
        for(int i = 1; i < n; i++) ofs << 1;
    }
    else if((int)st[0] - 48){
        for(int i = 1; i < n; i++) ofs << 1;
        ofs << 0;
    }
    else if((int)st[2] - 48){
        ofs << 1;
        for(int i = 1; i < n; i++) ofs << 0;
    }
    else ofs << "No solution";
    
    return 0;
}
