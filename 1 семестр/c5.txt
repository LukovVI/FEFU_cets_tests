#include <vector>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

bool razm(int s, vector<int> & v, int gl, int itr, string & st){
    int k;
    if(gl == 0 && s > 0){
        return false;
    }
    if(s == 0){
        return true;
    }
    for(int i = itr; i>=0; i--){
        k = v[i];
        if(k*gl >= s){
            if(k <= s){
                if(razm(s-k, v, gl-1, i, st)){
                    st = st + to_string(i+1) + " ";
                    return true;
                }
            }
        }
        else return false;
    }
    return false;
    
    
}

int main()
{
    vector<int> qv = {};
    int n, k;
    string st = "";
    
    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");
    
    ifs >> n >> k;
    
    for(int i = 1; i < 317; i++){
        if( i * i > n) break;
        qv.push_back(i * i);
    }
    
    if(razm(n, qv, k, qv.size()-1, st)){
        ofs << "YES\n" << st;
    }
    else ofs << "NO";


    return 0;
}
