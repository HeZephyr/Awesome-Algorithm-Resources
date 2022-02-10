/**
  *@filename:B_Max_and_Mex
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-30 16:26
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n,k;
int a[N];
bool vis[N];
void solve(){
    int mexx = 0,maxx = 0;
    for(int i = 1; i <= n; ++ i){
        if(a[i] < n)vis[a[i]] = true;
        maxx = max(maxx,a[i]);
    }
    while(vis[mexx])mexx ++;//得到mexx。
    int mid = (mexx + maxx + 1) / 2;
    if(mid > maxx){
        printf("%d\n",n + k);
    }
    else{
        bool flag = true;
        for(int i = 1; i <= n; ++ i){
            if(mid == a[i]){
                //如果该数存在。不存在则新增了一个数。
                flag = false;
            }
        }
        printf("%d\n",n + (flag && k));
    }
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        memset(vis,false,sizeof(vis));
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        solve();
    }
    return 0;
}