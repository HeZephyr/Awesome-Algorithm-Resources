/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-08-17 10:06
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int T,n;
ll x[N],t[N];
void solve(){
    t[n + 1] = 1e15;
    int cnt = 0;
    ll cur = 0,target = 0;
    for(int i = 1; i <= n; ++ i){
        if(cur == target){
            target = x[i];
        }
        ll d = t[i + 1] - t[i],sum = abs(cur - target);
        //说明目标点在当前位置的左端。而当前的任务也在当前位置左端。我们即可判断这期间能不能到达x[i]
        if(target >= cur && cur <= x[i] && min(cur + d,target) >= x[i]){
            cnt ++;
        }
        else if(target <= cur && cur >= x[i] && max(cur - d,target) <= x[i]){
            cnt ++;
        }
        if(target >= cur){
            cur += min(d,sum);
        }
        else{
            cur -= min(d,sum);
        }
    }
    printf("%d\n", cnt);
}
int main(){	
    scanf("%d", &T);
    while(T -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%lld%lld", &t[i], &x[i]);
        }
        solve();
    }
    return 0;
}