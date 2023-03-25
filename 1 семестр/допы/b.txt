#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    long long a, b, t;
    
    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");
    
    ifs >> a >> b;
    
    if (a > b){
        t = a;
        a = b;
        b = t;
    }
    
    
    
    if ((b-a)%4-(a%2*2) == 1) ofs << b+a-1;
    else ofs << 0;
    
    
    return 0;
}
