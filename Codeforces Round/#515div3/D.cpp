/**
  *@filename:D
  *@author: pursuit
  *@created: 2021-08-23 21:06
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//从集合中扔掉最左边的元素。说明右边的一定是连续装满的。
int n,m,k,a[N];
void solve(){
    int cnt = 0, i;
    for(i = n; i >= 1; -- i){
       if(cnt + a[i] <= k){
           cnt += a[i];
       } 
       else{
           cnt = a[i], -- m;
       }
       if(!m){
           //如果没有盒子用了。
           break;
       }
    }
    printf("%d\n", n - i);
}
int main(){	
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    solve();
    return 0;
}