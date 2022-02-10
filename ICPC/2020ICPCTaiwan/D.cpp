/**
  *@filename:D
  *@author: pursuit
  *@created: 2021-08-10 16:24
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int p,q,r;
void solve(){
    //x + y = 2p / (p + r),x - y = (p + r - 2q) / (p + r);
    pii x,y;
    //x = (3p + r - 2q) / 2 * (p + r);
    x.first = 3 * p + r - 2 * q;
    x.second = 2 * (p + r);
    int gcd = __gcd(x.first,x.second);
    x.first /= gcd, x.second /= gcd;
    if(x.first < 0){
        x.first = - x.first;
        x.second = -x.second;
    }
    y.first = p - r + 2 * q;
    y.second = 2 * (p + r);
    gcd = __gcd(y.first,y.second);
    y.first /= gcd,y.second /= gcd;
    if(y.first < 0){
        y.first = -y.first;
        y.second = -y.second;
    }
    double temp1 = 1.0 * x.first / x.second,temp2 = 1.0 * y.first / y.second;
    //cout << temp1 << " " << temp2 << endl;
    if(temp1 > 0 && temp1 < 1 && temp2 > 0 && temp2 < 1){
        if(x.second == 1){
            cout << x.first << " ";
        }
        else{
            cout << x.first << "/" << x.second << " ";
        }
        if(y.second == 1){
            cout << y.first << " ";
        }
        else{
            cout << y.first << "/" << y.second << endl;
        }
    }
    else{
        cout << -1 << endl;
    }
}
int main(){	
    cin >> p >> q >> r;
    solve();
    return 0;
}