#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

int main()
{
    vector<vector<int>> nap = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}};
    vector<int> napr;
    int x1, y1, x2, y2, x, y;
    bool a, b, c, d;
    
    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");
    
    ifs >> x1 >> y1 >> x2 >> y2;
    
    for(int i = 0; i < 4; i++){
        napr = nap[i];
        for(int j = 1; j<8; j++){
            x = x1+napr[0]*j;
            y = y1+napr[1]*j;
            a = abs( x2 - x ) == abs( y2 - y );
            b = x > -1 && y > -1 && x < 8 && y < 8;
            c = abs( x1 - x2 ) != abs( y1 - y2 );
            d = abs( x2 - x ) < abs( x2 - x1 ) && abs( x1 - x ) < abs( x1 - x2 );
            if((a) && (b) && (c || d)){
                ofs << x << " " << y;
                return 0;
            }
        }
    }
    
    ofs << 0;
    return 0;
    
}