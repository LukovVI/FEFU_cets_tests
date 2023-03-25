#include <math.h>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    double xa, ya, xb, yb, x0, y0, r;
    double xa1, ya1, xb1, yb1, c, s;
    
    double PI = 3.141592653589793;
    
    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");
    
    ifs >> xa >> ya >> xb >> yb >> x0 >> y0 >> r;
    
    xa -= x0;
    ya -= y0;
    xb -= x0;
    yb -= y0;
    
    c = cos(2*PI/360*r);
    s = sin(2*PI/360*r);
    
    xa1 = xa*c - ya*s;
    ya1 = xa*s + ya*c;
    
    xb1 = xb*c - yb*s;
    yb1 = xb*s + yb*c;
    
    xa1 += x0;
    ya1 += y0;
    xb1 += x0;
    yb1 += y0;
    
    ofs << to_string(xa1) << " " << to_string(ya1) << " " << to_string(xb1) << " " << to_string(yb1);

    return 0;
}
