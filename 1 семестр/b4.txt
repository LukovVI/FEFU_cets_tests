#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    int x, y, z, x1, y1, z1, n, m;
    
    int start, x_y, x_z, y_z, x_y1, x_z1, y_x1, y_z1, z_x1, z_y1, x1_y1, x1_z1, y1_z1;
    
    bool a1, a2, a3, b1, b2, b3, c1, c2, c3;
    
    ifstream ifs ("input.txt");
    ofstream ofs ("output.txt");
    
    ifs >> x >> y >> z >> x1 >> y1 >> z1;
    
    m = z * 2 + x * 4 + 1;
    n = z * 2 + y * 3 + 1;
    
    start = z * 2;
    x_y1 = ( z - z1 ) * 2;
    x_z1 = ( x - x1 ) * 4 + z * 2;
    y_x1 = z * 2 + y1 * 3;
    y_z1 = ( x - x1 ) * 4;
    z_x1 = x * 4 + y1 * 3 + z * 2;
    z_y1 = x * 4 + z1 * 2;
    x1_y1 = ( z- z1 ) * 2 + y1 * 3;
    x1_z1 = ( x - x1 ) * 4 + y1 * 3 + z*2;
    y1_z1 = ( x - x1 ) * 4 + z1 * 2;
    x_y = z * 2;
    x_z = x * 4 + z * 2;
    y_z = x * 4;
    
    
    
    for ( int i = 0; i < n; i++ ){
        for ( int j = 0; j < m; j++ ){
            a1 = ( i <=  start) && ( j + i <= x_z1 );
            a2 = ( i <=  x_y1) && ( i + j <=  x_z);
            a3 = ( i >= x1_y1) && (i <= y_x1) && (i+j >= x1_z1) && (i+j <= z_x1);
            b1 = ( j <= y_z ) && ( i > y_x1 );
            b2 = j <= y_z1;
            b3 = ( i > x_y1 ) && ( i < x1_y1 ) && ( j >= y1_z1 ) && ( j <= z_y1 );
            if ( i + j < z * 2 ){
                ofs << ".";
            }
            else if ( a1 || a2 || a3 ){
                
                if ( a3 ){
                    if ( ( i - x1_y1 ) % 2 == 0 ){
                        if ( ( i + j - x1_z1 ) % 4 == 0 ){
                            ofs << "+";
                        }
                        else{
                            ofs << "-";
                        }
                    }
                    else if ( ( i + j - x1_z1 ) % 4 == 0 ){
                        ofs << "/";
                    }
                    else{
                        ofs << " ";
                    }
                }
                else{
                    if ( i % 2 == 0){
                        if ( ( i + j - z * 2 ) % 4 == 0 ){
                            ofs << "+";
                        }
                        else{
                            ofs << "-";
                        }
                    }
                    else if ( ( i + j - x_y ) % 4 == 0 ){
                        ofs << "/";
                    }
                    else {
                        ofs << " ";
                    }
                }
                
            }
            else if ( b1 || b2 || b3 ){
                if ( b3 ){
                    if( ( i - x_y1 ) % 3 == 0 ){
                        if ( ( j - y1_z1 ) % 4 == 0 ){
                            ofs << "+";
                        }
                        else{
                            ofs << "-";
                        }
                    }
                    else if ( ( j - y1_z1 ) % 4 == 0){
                        ofs << "|";
                    }
                    else{
                        ofs << " ";
                    }
                }
                else{
                    if ( ( i - x_y ) % 3 == 0 ){
                        if ( j % 4 == 0 ){
                            ofs << "+";
                        }
                        else{
                            ofs << "-";
                        }
                    }
                    else if ( j % 4 == 0 ){
                        ofs << "|";
                    }
                    else{
                        ofs << " ";
                    }
                }
            }
            else if ( i + j > x * 4 + y * 3 + z * 2 ){
                break;
            }
            else if ( i + j > x_z && j > y_z ){
                if ( ( i + j - x_z ) % 3 == 0 ){
                    if ( ( j - y_z ) % 2 == 0 ){
                        ofs << "+";
                    }
                    else{
                        ofs << "/";
                    }
                }
                else if ( ( j - y_z ) % 2 == 0 ){
                    ofs << "|";
                }
                else{
                    ofs << " ";
                }
            }
            else{
                if ( ( i + j - x_z1 ) % 3 == 0 ){
                    if ( ( j - y_z1 ) % 2 == 0 ){
                        ofs << "+";
                    }
                    else{
                        ofs << "/";
                    }
                }
                else if ( ( j - y_z1 ) % 2 == 0 ){
                    ofs << "|";
                }
                else {
                    ofs << " ";
                }
            }
        }
        if ( i < n - 1 ){
            ofs << endl;
        }
    }
    
    return 0;
    
}
