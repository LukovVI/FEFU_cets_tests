#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n;
    int A;
    int res = 0;
    
    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");
    
    ifs >> n;
    
    for (int i = 0; i < n; i ++){
        ifs >> A;
        res = res + A;
    }
    
    ofs << res;

    return 0;
}
