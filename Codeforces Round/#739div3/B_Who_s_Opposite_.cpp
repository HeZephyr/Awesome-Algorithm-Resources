/**
  *@filename:B_Who_s_Opposite_
  *@author: pursuit
  *@created: 2021-08-18 22:39
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,a,b,c,d;
void solve(){
    int n = (b - a) * 2;
    if(n % 2 || a > n || b > n || c > n){
        cout << - 1 << endl;
    }
    else{
        n /= 2;
        //abs(c - d) * 2 = n,
        int d = c - n > 0 ? c - n : c + n;
        cout << d << endl;
    }
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> a >> b >> c;
        if(a > b)swap(a,b);
        solve();
    }
    return 0;
}