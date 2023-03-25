#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> v {-1};
    int a, si;
    string st, res = "";
    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");
    
    getline(ifs, st);
    
    for(int i = 0; i < st.size(); i++) if(st[i] == ' ') v.push_back(i);
    v.push_back(st.size());
    
    si = v.size()-1;
    
    ifs >> a;
    
    if(a > si) a = si;
    
    for(int i = v[a-1]+1; i < v[a]; i++) res += st[i];
    
    ofs << res;
    
    return 0;
}
