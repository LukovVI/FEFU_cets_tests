#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{   
    bool chek = true;
    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");
    
    for(char ch; ifs >> ch; )
    {
        if (chek && ch >= 'A' && ch <= 'Z') chek = false;
        else if (!chek && ch >='a' && ch <='z') 
        {
            ofs << "NO";
            return 0;
        }
    }
    
    ofs<<"YES";

    return 0;
}
