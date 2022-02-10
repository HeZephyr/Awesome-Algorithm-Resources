/**
  *@filename:D_Walking_Between_Houses
  *@author: pursuit
  *@created: 2021-10-26 19:23
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

ll n, k, s;
void solve(){
    if(k * (n - 1) < s || s < k){
        puts("NO");
    }
    else{
        ll x = s / k, y = s % k;
        puts("YES");
        for(int i = 0; i < y; ++ i){
            if(i & 1)cout << 1 << " ";
            else cout << x + 2 << " ";
        }
        if(y % 2 == 0){
            for(int i = 0; i < k - y; ++ i){
                if(i & 1)cout << 1 << " ";
                else cout << x + 1 << " ";
            }
        }
        else{
            for(int i = 0; i < k - y; ++ i){
                if(i & 1)cout << x + 2 << " ";
                else cout << 2 << " ";
            }
        }
        cout << endl;
    }
}
int main(){	
    cin >> n >> k >> s;
    solve();
    return 0;
}