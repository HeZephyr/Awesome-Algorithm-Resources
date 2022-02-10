/**
  *@filename:D1_All_are_Same
  *@author: pursuit
  *@created: 2021-10-13 23:11
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, a[N];
int minn;
bool check(){
    for(int i = 2; i<= n; ++ i){
        if(a[i] != a[1])return false;
    }
    return true;
}
void solve(){
    if(check()){
        puts("-1");
    }
    else{
        int gcd = 0;
        for(int i = 1; i <= n; ++ i){
            gcd = __gcd(gcd, a[i] - minn);
        }
        cout << gcd << endl;
    }
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n;
        minn = INF;
        for(int i = 1; i <= n; ++ i){
            cin >> a[i];
            minn = min(minn, a[i]);
        }
        solve();
    }
    return 0;
}