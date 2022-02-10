#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n,k;
int a[N],p[N],ans;//ans统计得分。
void solve(){
    //此题易知用双指针获取最大值，注意，我们需要时刻更新我们能用的次数。
    int l = 1,r = 1;
    int maxx = 0;
    while(r <= n){
        while(r <= n && r - l  < k){
            if(!p[r]){
                ans += a[r];
            }
            r ++ ;
        }
        maxx = max(ans,maxx);//保存最大值。
        if(!p[l]){
            ans -= a[l];
        }
        l ++;
    }
    printf("%d\n",maxx);
}
int main(){
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &p[i]);
        if(p[i]){
            ans += a[i];
        }
    }
    solve();
    return 0;
}