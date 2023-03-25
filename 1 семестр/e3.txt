#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    vector<unsigned long long> inv = {};
    long long n, r, c;
    long long nol = 0;
    
    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");
    
    ifs >> n >> r;
    
    for(long long i = 0; i < n; i++) inv.push_back(0);
    
    c = n / 2 + n % 2;
    
    if(r <= c) {
        inv[r-1] = (n - (r-1)*2)*(n - (r-1)*2);
        for(long long i = max(r-2, nol); i <= n-r; i++) inv[i] = inv[r-1] + (r - i - 1);
    }
    else {
        inv[r-1] = (n - (r-1)*2 - 1)*(n - (r-1)*2 - 1) + 1;
        for(long long i = r-2; i >= n-r; i--) inv[i] = inv[r-1] - r + i + 1;
    }
    for(long long i = 0; i < c; i++) {
        if(inv[i] == 0) inv[i] = (n-i*2)*(n-i*2)-((n-i*2)-1)*4+r-1-i;
        else break;
    }
    
    for(long long i = 0; i < c; i++) {
        if(inv[n-1-i] == 0) inv[n-1-i] = (n-i*2)*(n-i*2)-(n-i*2)-r+i+2;
        else break;
    }
    
    for(long long i = 0; i < n; i++) ofs << inv[i] << " ";

    return 0;
}
