#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string s, sr;
    string st = "";
    int r;
    string res;
    
    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");
    
    ifs >> st;
    
    r = st.length();
    s = st[0];
    if(s == "="){
        res = "*";
    }
    else if(s == "<"){
        res = "+";
    }
    else{
        res = "-";
    }
    
    for(int i = 1; i < 5; i++){
        s = st[i];
        sr = res[i-1];
        if(s == "="){
            res =res + sr;
        }
        else if(s == "<" && (sr == "*" || sr == "+")){
            res = res + "+";
        }
        else if(s == ">" && (sr == "*" || sr == "-")){
            res = res + "-";
        }
        else{
            res = res + "?";
        }
    }
    
    
    ofs << res;

    return 0;
}