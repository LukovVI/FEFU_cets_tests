#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>


using namespace std;


int main()
{   
    unsigned long long p, k, n, r, melem, sum2 = 0, nm = 0;
    map<int, int[ 2 ]> m;
    map<int, int[ 2 ]> :: iterator it, it_r;
    unsigned long long res = 0;
    
    ifstream ifs ( "game.in" );
    ofstream ofs ( "game.out" );
    
    ifs >> n >> k;
    
    for ( int i = 0; i < n; i++ ){
        ifs >> p;
        it = m.find( p );
        if ( it == m.end() ){
            m[ p ][ 0 ] = 1;
            nm++;
        }
        else{
            it->second[ 0 ]++;
        }
    }
    
    it = m.begin();
    for ( int i = 0; i < nm; i++ ){
        if ( it->second[ 0 ] >= 2 ){
            sum2++;
        }
        it->second[ 1 ] = sum2;
        it++;
    }
    
    it = m.begin();
    it_r = m.begin();
    r = 0;
    for ( int i = 0; i < nm; i++ ){
        while( ( it_r->first <= it->first * k ) && ( r < nm ) ){
            it_r++;
            r++;
        }
        it_r--;
        r--;
        melem = it->second[ 0 ];
        res += 3 * ( it_r->second[ 1 ] - it->second[ 1 ] );
        if ( r - i >= 2 ){
            res += 3 * ( r - i ) * ( r - i - 1 );
        }
        if ( melem > 1 ){
            res += 3 * ( r - i );
            if ( melem > 2 ){
                res += 1;
            }
        }
        it++;
    }
    ofs << res;
    return 0;
}
