#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int sortr3(vector<double> & v, vector<string> & st, vector<int> & in, int start, int end){
    int m = start;
    double p;
    string str;
    int ind;
    if(end-start < 1) return 0;
    
    double x = v[start];
    
    for(int i = start+1; i<=end; i++){
        if(v[i] > x) m++;
    }
    if(m != start){
        p = v[m];
        v[m] = v[start];
        v[start] = p;
        
        str = st[m];
        st[m] = st[start];
        st[start] = str;
        
        ind = in[start];
        in[start] = in[m];
        in[m] = ind;
    }
    
    int s1 = start, s2 = m+1;
    while(s1<m && s2 <=end){
        if(v[s1]<=x){
            while(v[s2] <=x && s2 < end) s2++;
            
            p = v[s1];
            v[s1] = v[s2];
            v[s2] = p;
            
            str = st[s1];
            st[s1] = st[s2];
            st[s2] = str;
            
            ind = in[s1];
            in[s1] = in[s2];
            in[s2] = ind;
        }
        s1++;
    }
    sortr3(v, st, in, start, m-1);
    sortr3(v, st, in, m+1, end);
    return 0;
}

int sortr2(vector<int> & v, vector<string> & st, int start, int end){
    int m = start;
    int p;
    string str;
    if(end-start < 1) return 0;
    
    int x = v[start];
    
    for(int i = start+1; i<=end; i++){
        if(v[i] < x) m++;
    }
    
    p = v[m];
    v[m] = v[start];
    v[start] = p;
    
    str = st[m];
    st[m] = st[start];
    st[start] = str;
    
    int s1 = start, s2 = m+1;
    while(s1<m && s2 <=end){
        if(v[s1]>=x){
            while(v[s2] >=x && s2 < end) s2++;
            
            p = v[s1];
            v[s1] = v[s2];
            v[s2] = p;
            
            str = st[s1];
            st[s1] = st[s2];
            st[s2] = str;
        }
        s1++;
    }
    sortr2(v, st, start, m-1);
    sortr2(v, st, m+1, end);
    return 0;
}


int main()
{
    vector<string> stv = {};
    vector<double> dov = {};
    vector<int> inv = {};
    int n;
    double d;
    string name;
    
    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");
    
    ifs >> n;
    
    for(int i = 0; i < n; i++){
        ifs >> d >> name;
        dov.push_back(d);
        stv.push_back(name);
        inv.push_back(i);
    }
    
    sortr3(dov, stv, inv, 0, n-1);
    int l = 0;
    
    for(int i = 1; i < n; i++){
        if(dov[i] == dov[i-1]) l++;
        if(l > 0){
            if(dov[i] != dov[i-1]){
                sortr2(inv, stv, i-l-1, i-1);
                l = 0;
            }
            else if(i == n-1){
                sortr2(inv, stv, i-l, i);
                l = 0;
            }
        }
    }
    
    for(int i = 0; i < n; i++) ofs << stv[i] << '\n';

    return 0;
}
