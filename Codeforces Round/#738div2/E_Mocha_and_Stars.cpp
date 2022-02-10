/**
  *@filename:E_Mocha_and_Stars
  *@author: pursuit
  *@created: 2021-08-16 00:13
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,m;
int l[N],r[N];
void solve(){
}
int main(){	
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++ i){
        scanf("%d%d", &l[i], &r[i]);
    }
    solve();
    return 0;
}