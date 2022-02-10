/**
  *@filename:D1_Up_the_Strip_simplified_version_
  *@author: pursuit
  *@created: 2021-08-25 00:40
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//选择1-(x-1)的整数y。将x移动到x-y。选择一个介于2-x的整数z.将x移动到x/z。
int n,m;
int dp[N];//dp[u]表示移动到u的方案数。
void solve(){
}
int main(){	
    cin >> n >> m;
    solve();
    return 0;
}