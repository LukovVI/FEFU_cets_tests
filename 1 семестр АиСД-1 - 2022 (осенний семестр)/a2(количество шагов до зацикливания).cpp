#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n;
    int a;
    int k = 2;
    ifstream Fin ("input.txt");
    Fin >> a;
    
    if (a<0){
        a = (a-100)* -1;
        k += 1;
    }
    n = a;
    k += a/100;
    a = a%100;
    if ((a == 0 && n > 0) || a == 50){
        k-= 1;
    }
    
    
    ofstream Fout ("output.txt");
    Fout << k;
    return 0;
}