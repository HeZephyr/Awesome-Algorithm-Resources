/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-08-31 13:27
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 100 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,k,x,a[N];
void solve(){
    int cnt = 0, ans = 0;
    for(int i = 1; i < N; ++ i){
        cnt += (a[i] != 0);
        ans = max(ans,a[i]);
    }
    //ans需要整分给每个人。
    ans = (ans + k - 1) / k * k;
    printf("%d\n", cnt * ans - n);
}
int main(){	
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &x);
        ++ a[x];
    }
    solve();
    return 0;
}