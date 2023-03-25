#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    float a;
    int b;
    int k = 255;
    int res;
    
    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");
    
    ifs >> a;
    
    
    
    b = (*(int*)&a);
    
    
    
    res = ((b>>23) & k) - 127;
    if (res < -126){
        res = -126;
    }
    
    if (b == 0){
        res = 0;
    }
    ofs << res;

    return 0;
}
