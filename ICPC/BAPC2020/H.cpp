/**
  *@filename:H
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-30 17:23
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int n,a[N],b[N];
int pos[N],vis[N];
void print(){
    int cnt = 0;
    for(int i = 1; i <= n; ++ i){
        if(vis[i])cnt ++;
    }
    for(int i = 1; i <= n && cnt < n / 2; ++ i){
        if(!vis[i]){
            vis[i] = true;
            cnt ++;
        }
    }
    int sz = 0;
    for(int i = 1; i <= n; ++ i){
        if(vis[i]){
            printf("%d ",i);
            b[++ sz] = a[i];
        }
    }
    sort(b + 1, b + sz + 1);
    sz = 0;
    for(int i = 1; i <= n; ++ i){
        if(vis[i])a[i] = b[++ sz];
        pos[a[i]] = i;
    }
    printf("\n");
    memset(vis,false,sizeof(vis));
}
void solve(){
    printf("3\n");
    for(int i = n / 4 * 3 + 1; i <= n; ++ i){
        vis[pos[i]] = true;
        vis[i] = true;
    }
    print();
    for(int i = n / 4 * 2 + 1; i <= n / 4 * 3; ++ i){
        vis[pos[i]] = true;
        vis[i] = true;
    }
    print();
    for(int i = 1; i <= n / 2; ++ i){
        vis[i] = true;
    }
    print();
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        pos[a[i]] = i;//记录a[i]的位置。
    }
    solve();
    return 0;
}