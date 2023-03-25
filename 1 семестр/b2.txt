#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int x1, y1, x2, y2;
    int x, y;
    int cx, cy;
    int r;
    string res = "CENTER";
    
    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");
    
    ifs >> x1 >> y1 >> x2 >> y2 >> x >> y;
    
    cx = (x1 + x2)/2;
    cy = (y1 + y2)/2;
    
    r = abs(cx - x) +abs(cy - y);
    
    if ((abs(x1-x)+abs(y1-y) < r)|| (abs(x1-x)+abs(y2-y) < r) || (abs(x2-x)+abs(y2-y) < r) || (abs(x2-x)+abs(y1-y) < r)){
        res = "CORNER";
    }
    
    ofs << res;

    return 0;
}
