#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

long long nod(long long a, long long b){
    long long mi = min(a, b);
    long long ma = max(a, b);
    if(!(ma%mi)) return mi;
    return nod(ma%mi, mi);
}

int main()
{
    long long a, b, nd;
    
    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");
    
    ifs >> a >> b;
    
    nd = nod(a, b);
    
    ofs << nd << " " << a*b/nd;
    
    
    
    return 0;
}
