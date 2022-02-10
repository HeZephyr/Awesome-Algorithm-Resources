/**
  *@filename:E
  *@author: pursuit
  *@created: 2021-08-21 15:48
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,a[N],nxt[N];//nxt[i]表示至少需要几步可以跳到，若为-1，说明不可能。
//可以从i跳到i - ai或者i + ai。跳的位置必须在[1,n]中。
bool vis[N];
int dfs(int x){
    vis[x] = true;//防止造成循环
    if(nxt[x] > 0)return nxt[x];
    int idx1 = x + a[x],idx2 = x - a[x];
    int temp1 = -1,temp2 = -1;
    if(idx1 >= 1 && idx1 <= n && (a[x] % 2 != a[idx1] % 2))return nxt[x] = 1;
    if(idx2 >= 1 && idx2 <= n && (a[x] % 2 != a[idx2] % 2))return nxt[x] = 1;
    //说明都没有出现下一次就能碰到的解。
    if(idx1 >= 1 && idx1 <= n){
        if(vis[idx1]){
            //说明出现了循环。或者该点已经确定了nxt值。
            temp1 = nxt[idx1];
        }
        else{
            temp1 = dfs(idx1);
        }
    }
    if(idx2 >= 1 && idx2 <= n){
        if(vis[idx2]){
            //说明出现了循环。或者该点已经确定了nxt值。
            temp2 = nxt[idx2];
        }
        else{
            temp2 = dfs(idx2);
        }
    }
    if(temp1 <= 0 && temp2 <= 0)return nxt[x] = -1;
    if(temp1 <= 0)return nxt[x] = temp2 + 1;
    if(temp2 <= 0)return nxt[x] = temp1 + 1;
    return nxt[x] = min(temp1,temp2) + 1;
}
void solve(){
    for(int i = 1; i <= n; ++ i){
        dfs(i);
    }
    for(int i = 1; i <= n; ++ i){
        printf("%d ", nxt[i]);
    }
    puts("");
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }	
    solve();
    return 0;
}