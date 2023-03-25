#include <iostream>
#include <fstream>
#include <map>


using namespace std;


int main()
{
    int n, a;
    map <int, int> ma;
    map <int, int> :: iterator chek;
    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");
    
    ifs >> n;
    
    for(int i = 0; i<n; i++){
        ifs >> a;
        chek = ma.find(a);
        if(chek != ma.end()){
            ma[a]++;
        }
        else{
            ma[a] = 1;
        }
    }
    for(chek = ma.begin(); chek != ma.end(); chek++){
        ofs << chek->first << " " << chek->second << endl;
    }
    
    return 0;
}
