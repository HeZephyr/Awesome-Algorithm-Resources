/**
  *@filename:A_CQXYM_Count_Permutations
  *@author: pursuit
  *@created: 2021-09-30 18:15
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n;
int fac[N];
void init(){
    fac[2] = 1;
    for(int i = 3; i < N; ++ i){
        fac[i] = 1LL * fac[i - 1] * i % P;
    }
}
void solve(){
    //n限定了为2n的排列。
    cout << fac[n * 2] << endl;
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