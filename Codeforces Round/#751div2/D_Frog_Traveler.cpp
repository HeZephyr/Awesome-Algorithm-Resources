/**
  *@filename:D_Frog_Traveler
  *@author: pursuit
  *@created: 2021-10-25 15:52
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 3e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, a[N], b[N];
void solve(){
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &b[i]);
    }
    solve();
    return 0;
}