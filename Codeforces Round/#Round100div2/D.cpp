/**
  *@filename:D
  *@author: pursuit
  *@created: 2021-08-17 12:34
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 4e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n,a[N],b[N],vis[N];
int check(int x){
    //分前b个x组。取最小的。
    for(int i = 1; i <= x; ++ i){
        if(a[i] > b[n - x + i])return 1;//说明x太大了。
    }
    //取最大的。
    for(int i = x + 1; i <= n; ++ i){
        if(a[i] < b[i - x])return 2;//说明x太小了。
    }
    return 0;//说明符合。
}
void solve(){
    int cnt = 0;
    for(int i = 1; i <= 2 * n; ++ i){
        //统计未使用的值。
        if(!vis[i]){
            b[++cnt] = i;
        }
    }
    //二分上边界和下边界。
    int l = 0,r = n,lBound = 0;
    while(l <= r){
        int mid = l + r >> 1;
        if(check(mid) != 2){
            //说明符合。
            lBound = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;//说明x太小了。
        }
    }
    l = 0,r = n;
    int ans =0;
    while(l <= r){
        int mid = l + r >> 1;
        if(check(mid) != 1){
            //说明符合。
            ans = max(ans,mid - lBound + 1);
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    printf("%d\n", ans);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        memset(vis,false,sizeof(vis));
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
            vis[a[i]] = true;
        }
        solve();
    }
    return 0;
}