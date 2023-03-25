#include <iostream>
#include <vector>

using namespace std;

class huge{
    private:
        vector<long long> v;
        long long s;
        long long siz;
        
        huge summ(huge a, huge b){
            a.v.push_back(0);
            for(int i = 0; i < b.siz; i++) a.v[i] += b.v[i];
            for(int i = 0; i < a.siz; i++){
                a.v[i+1] += a.v[i]/10;
                a.v[i] = a.v[i]%10;
            }
            if(a.v[a.siz] == 0) a.v.erase(a.v.begin()+a.siz);
            a.siz = a.v.size();
            return a;
        }
        huge razn(huge a, huge b){
            for(int i = 0; i < b.siz; i++){
                a.v[i] -= b.v[i];
                if(a.v[i] < 0){
                    a.v[i] += 10;
                    a.v[i+1]--;
                }
            }
            for(int i = a.siz-1; i > 0; i--) {
                if(a.v[i] == 0) a.v.erase(a.v.begin()+i);
                else break;
            }
            a.siz = a.v.size();
            if(a.siz == 1 && a.v[0] == 0) a.s = 1;
            return a;
        }
        
        
    public:
        huge(long long x){
            s = (x<0)? -1:1;
            x = abs(x);
            if(x == 0) v = {0};
            while(x>0){
                v.push_back(x%10);
                x = x/10;
            }
            siz = v.size();
        }
        void out(){
            if(this->s == -1) cout << "-";
            for(int i = this->siz-1; i >= 0; i--) cout << this->v[i];
        }
        huge mod(huge a){
            a.s = 1;
            return a;
        }
        huge operator+ (huge & b){
            if(this->s == b.s) return (mod(*this) > mod(b))? summ(*this, b) : summ(b, *this);
            else return (mod(*this) > mod(b))? razn(*this, b) : razn(b, *this);
        }
        void operator+= (huge & b){
            *this = *this + b;
        }
        bool operator> (huge b){
            huge a = *this;
            if(a.s != b.s) return (a.s > b.s)? true : false;
            else if(a.siz != b.siz) return (a.siz*a.s > b.siz*b.s)? true : false;
            else{
                for(int i = a.siz; i >=0; i--){
                    if(a.v[i] > b.v[i]) return true;
                    else if(a.v[i] < b.v[i]) return false;
                }
            }
            return false;
        }
        
};

int main()
{
    huge a(0);
    huge res(0);
    
    for(long long x; cin >> x; ){
        if(x == -1){
            break;
        }
        a = (huge)x;
        res += a;
        res.out();
        cout << "\n";
    }
    
    return 0;
}
