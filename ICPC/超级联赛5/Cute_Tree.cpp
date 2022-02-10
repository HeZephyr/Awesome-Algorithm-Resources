/**
  *@filename:Cute_Tree
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-08-03 12:13
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n;
unordered_map<ll,ll> p;
ll buildTree(int len){
    if(p[len])return p[len];
    if(len == 1){
        return 1;
    }
    if(len == 2){
        return p[len] = buildTree(len / 2) + buildTree(len - len / 2) + 1;
    }
    else{
        if(len % 3 == 0){
            return p[len] = buildTree(len / 3) + buildTree(len / 3) + buildTree(len / 3) + 1;
        }
        else if(len % 3 == 1){
            return p[len] = buildTree(len / 3) + buildTree(len / 3) + buildTree(len / 3 + 1) + 1;
        }
        else{
            return p[len] = buildTree(len / 3 + 1) + buildTree(len / 3) + buildTree(len / 3 + 1) + 1;
        }
    }
}
void solve(){
    printf("%lld\n", buildTree(n));
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        int x;
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &x);
        }
        solve();
    }
    return 0;
}