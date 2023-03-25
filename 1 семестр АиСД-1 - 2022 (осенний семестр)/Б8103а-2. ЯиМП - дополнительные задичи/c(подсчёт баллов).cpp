#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v {};
    int a, n, res = 0;
    char ch;
    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");
    
    ifs >> n;
    
    for (int i = 0; i < n; i ++){
        ifs >> a;
        v.push_back(a);
    }
    
    for (int i = 0; i < n; i ++){
        ifs >> ch;
        if (ch == '+') res += v[i];
    }
    
    ofs << res;
    return 0;
}
