#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int sortr(int v[], int start, int end){
    int m = start, p;
    if(end-start < 1) return 0;
    
    int x = v[start];
    
    for(int i = start+1; i<=end; i++){
        if(v[i] < x) m++;
    }
    
    p = v[m];
    v[m] = x;
    v[start] = p;
    int s1 = start, s2 = m+1;
    while(s1<m && s2 <=end){
        if(v[s1]>=x){
            while(v[s2] >=x && s2 < end) s2++;
            p = v[s1];
            v[s1] = v[s2];
            v[s2] = p;
        }
        s1++;
    }
    sortr(v, start, m-1);
    sortr(v, m+1, end);
    return 0;
}

int main()
{   
    string str;
    int n, l, res = 0;
    
    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");
    
    ifs >> n >> l;
    
    int list[n];
    
    for(int i = 0; i < n; i++) ifs >> list[i];
    
    sortr(list, 0, n-1);
    
    for(int i = 0; i < n; i++)
    {
        if(res < list[i]) res = list[i];
        res += l;
    }
    ofs << res;
    return 0;
}

