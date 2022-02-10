/**
  *@filename:C1
  *@author: pursuit
  *@created: 2021-08-27 10:55
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n,power[10], minn;
void init(){
    power[0] = 1;
    for(int i = 1; i < 10; ++ i){
        power[i] = power[i - 1] * 3;
    }
}
void dfs(int x,int step){
    //x为当前的值。
    if(x >= n){
        minn = min(minn, x);
        return;
    }
    if(step >= 10)return;
    for(int i = step; i < 10; ++ i){
        dfs(x + power[i], i + 1);
    }
}
void solve(){
    minn = INF;
    dfs(0,0);
    cout << minn << endl;
}
int main(){	
    cin >> t;
    init();
    while(t -- ){
        cin >> n;
        solve();
    }
    return 0;
}