#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    long long w, h, a;
    
    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");
    
    ifs >> w >> h >> a;
    
    if ((w*h)%(a*a) != 0) ofs << (w*h)/(a*a)+1;
    else ofs << (w*h)/(a*a);
    
    
    
    return 0;
}
