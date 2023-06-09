/*��� ������� ������ ����� ������ �� ��������� ������� ���� ��������� ������������ 
����� � ����� ����������� �� ����������� ����.
���������, ��� ��� ����������� ���� ����������� ������ �� B ������ ���������� A ������.
 
������� ����� ����������� � ���������� ��������, �� ������� � ��������� 
����� ������� � ������ ���������, ������� ��� ����� ����� ���������� �����.
������� ���������� ������ � ������� ������ ���� �����, ����� �� ��������� ������������ � ���� �������� ���������� �����.

����� ����, ��� ������� ������� ������� ���������� ���������� ���������� �������� ���� ����� ���������� �����.

��������� �������� ���������, �������, ������� �� ���� ���������� ������ ����������� ������
B � ���� ������ A, ���������� ���������� ��������� ���������� ������ � ������� C � ��������������� ����� ���� D

�������� ���� ���������, ��� ��������� 6-�� ������ ���������� 27 ������,
�� �� ����� ��������� � �������� �� 1-�� ������� ���������� 4.5 ����� � ������ D = 1. ��� ���� ���������, ���
760 ������ ����� 15 ������, �� �� ����� ��������� �� 19 ���� � ������� ���������� 0.375 ������ � ������ D = 3*/

#include <iostream>
#include <fstream>


using namespace std;

int main()
{
    long long n;
    long long s;
    long long r;
    int res = 0;
    
    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");
    ifs >> s >> n;
    
    
    while (s > 0 && s%10 == 0){
        s = s/10;
        res--;
    }
    
    
    while (n%2 == 0){
        n = n/2;
        if (s%2 == 0){
            s = s/2;
        }
        else{
            s = s * 5;
            res++;
        }
    }
    
    
    while (n%5 == 0){
        n = n/5;
        if (s%5 == 0){
            s = s/5;
        }
        else{
            s = s * 2;
            res++;
        }
    }
    
    
    if (s%n ==0){
        s = s/n;
        n = 1;
    }
    
    r = abs(s-n);
    
    for(long long i = 3; (i <= n && i <= s && i <= r); i=i+2){
        while (n%i == 0 && s%i == 0){
            n = n/i;
            s = s/i;
        }
        
    }
    
    
    if (res < 0){
        res = 0;
    }
    
    
    ofs << n << " " << res;

    return 0;
}
