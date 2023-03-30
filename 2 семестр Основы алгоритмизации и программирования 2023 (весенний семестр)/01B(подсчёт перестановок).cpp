#include <iostream>
#include <fstream>
#include <string>

using namespace std;

long long mergesort(long double mas[], int start, int end)
{
    long long svich = 0;
    int size = end - start + 1;
    int mid = start + (end - start)/2;
    if (end <= start) return 0;
    
    svich += mergesort(mas, start, mid);
    svich += mergesort(mas, mid+1, end);
    
    long double buf[size];
    
    int i = start, j = mid + 1, k = 0;
    while(i <= mid && j <= end)
    {
        if(mas[i] >= mas[j]) buf[k++] = mas[i++];
        else
        {
            buf[k++] = mas[j++];
            svich += mid + 1 - i;
        }
    }
    while(i <= mid) buf[k++] = mas[i++];
    while(j <= end) buf[k++] = mas[j++];
    for(int i = 0; i < size; i++) mas[start + i] = buf[i];
    return svich;
}

int main()
{   
    string str;
    int n;
    long long res = 0;
    
    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");
    
    ifs >> n;
    
    long double list[n];
    
    for(int i = 0; i < n; i++) ifs >> list[i] >> str;
    
    res = mergesort(list, 0, n-1);
    
    ofs << res;
    return 0;
}

