/**
  *@filename:Stacks
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-23 20:02
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

struct node{
    int l,r;
}list[N];
int head[N],end[N],next[N],tot;
int x,
void solve(){
    int a,b;
    tot = 0;
    while(m -- ){
        cin >> a >> b;
        while(list[a].l && list[b].l){
            //说明a和b都非空。
            
        }
    }
}
int main(){
    while(cin >> n >> m){
        for(int i = 1; i <= n; ++ i){
            list[i].l = list[i].r = i;
        }
        solve();
    }
    return 0;
}