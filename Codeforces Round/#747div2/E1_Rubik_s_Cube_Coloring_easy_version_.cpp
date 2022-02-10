/**
  *@filename:E1_Rubik_s_Cube_Coloring_easy_version_
  *@author: pursuit
  *@created: 2021-10-09 00:23
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;


ll k;
ll ksm(ll n, ll q){
    ll ans = 1;
    while(q){
        if(q & 1)ans = ans * n % P;
        n = n * n % P;
        q >>= 1;
    }
    return ans;
}
void solve(){
    k = (1LL << k) - 1; 
    cout << ksm(4, k - 1) * 6 % P << endl;
}
int main(){	
    cin >> k;
    solve();
    return 0;
}