#include <iostream>
#include <fstream>


using namespace std;


int main()
{
    int ch, min;
    
    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");
    
    ifs >> ch >> min;
    
    if (min > 0){
        ch = ch + 1;
    }
    else{
        min = 60;
    }
    
    ofs << 24 - ch<< " " << 60 - min;
    return 0;
}
