/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-08-15 13:21
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 4e4 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,m,k;
int a[N],b[N],temp[N],cnt;
void solve(){
    //筛除k的因子。
    for(int i = 1; i * i <= k; ++ i){
        if(k % i == 0){
            temp[++cnt] = i;
            if(i * i == k)continue;
            temp[++cnt] = k / i;
        }
    }
    //根据因子遍历数组求解连续段。
    ll res = 0;
    for(int j = 1; j <= cnt; ++ j){
        int x = 0,y = 0,ans = 0,u = temp[j],v = k / temp[j];
        for(int i = 1; i <= n; ++ i){
            if(a[i]){
                ans ++;
            }
            else{
                if(ans >= u){
                    x += ans - u + 1;
                }
                ans = 0;
            }
        }
        if(ans >= u){
            x += ans - u + 1;
        }
        ans = 0;
        for(int i = 1; i <= m; ++ i){
            if(b[i]){
                ans ++;
            }
            else{
                if(ans >= v){
                    y += ans - v + 1;
                }
                ans = 0;
            }
        }
        if(ans >= v){
            y += ans - v + 1;
        }
        //cout << u << " " << x << " " << y << endl;
        res += 1LL * x * y;
    }
    printf("%lld\n", res);
}
int main(){	
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= m; ++ i){
        scanf("%d", &b[i]);
    }
    solve();
    return 0;
}