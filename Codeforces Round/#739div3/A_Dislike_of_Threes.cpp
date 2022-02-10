/**
  *@filename:A_Dislike_of_Threes
  *@author: pursuit
  *@created: 2021-08-18 22:35
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,k;
int dp[N];
void init(){
    int cnt = 1;
    for(int i = 1;; ++ i){
        if(i % 3 == 0 || i % 10 == 3)continue;
        dp[cnt++] = i;
        if(cnt == 1001)break;
    }
}
void solve(){
    cout << dp[k] << endl;
}
int main(){	
    cin >> t;
    init();
    while(t -- ){
        cin >> k;
        solve();
    }
    return 0;
}