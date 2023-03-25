#include <iostream>
#include <fstream>


using namespace std;


int main()
{
    int n;
    int k;
    int res1, res2;
    
    ifstream ifs ("a.in");
    ofstream ofs ("a.out");
    
    ifs >> k >> n;
    res1 = n/k+ 1;
    
    res2 = n%k;
    
    if (res2 == 0){
        res1--;
        res2 = k;
    }

    ofs << res1 << " " << res2;
    return 0;
}
