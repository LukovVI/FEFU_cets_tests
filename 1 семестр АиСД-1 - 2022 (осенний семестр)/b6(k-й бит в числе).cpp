#include <iostream>
#include <fstream>


using namespace std;

int main()
{
    unsigned long long x;
    int y;
    
    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");
    
    ifs >> x >> y;
    
    x = (x>>y) & 1;
    
    ofs << x;
    
    return 0;
}
