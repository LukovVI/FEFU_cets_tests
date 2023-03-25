#include <iostream>
#include <fstream>
#include <vector>


using namespace std;


int main()
{
    int n;
    int k;
    int rev;
    vector<int> mas = {};
    
    
    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");
    
    ifs >> n;
    
    for (int i = 0; i<n; i++){
        ifs >> k;
        mas.push_back(k);
    }

    for (int j = 0; j<n-1; j++){
        if (mas[j]> mas[j+1]){
            rev = mas[j];
            mas[j]= mas[j+1];
            mas[j+1] = rev;
        }
    }
    
    ofs << mas[n-1];
    return 0;
}
