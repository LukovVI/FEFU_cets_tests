#include <iostream>
#include <fstream>


using namespace std;


int main()
{
    int n;
    
    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");
    
    ifs >> n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                ofs << (i+j+k)%n + 1 << " ";
                
            }
            ofs << endl;
        }
    }
    
    return 0;
}
