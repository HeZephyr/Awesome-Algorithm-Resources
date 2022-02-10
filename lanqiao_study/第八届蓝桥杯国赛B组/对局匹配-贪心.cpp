/**
  *@filename:对局匹配-贪心
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-29 20:52
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

//贪心+尺取法，我们知道如果两个人之间积分值相差为k，那么我们随便取一个出来就可以凑出一个答案了。
int n,k,a[maxn];
bool vis[maxn];//vis[i]判断i是否已经被确定了，即存在和别人积分值相差k。
void solve(){
    sort(a+1,a+n+1);
    int ans=0;
    int l=1,r=1;
    while(r<=n){
        if(l==r){
            r++;
            continue;
        }
        if(a[l]==a[r]-k&&!vis[l]&&!vis[r]){
            //说明没有被确认，我们取一个凑答案。
            ans++;
            vis[l]=vis[r]=true;
            l++,r++;
        }
        else if(a[l]<a[r]-k&&!vis[l]&&!vis[r]){
            //说明凑不出，我们需要偏移，让l靠近r。
            l++;
        }
        else if(a[l]>a[r]-k&&!vis[l]&&!vis[r]){
            //说明凑不出，且a[l]>a[r]，我们需要偏移，让r大于它。
            r++;
        }
        else{
            //说明存在l和r有一个是被确认的，我们需要移动被确认的。
            if(vis[l])l++;
            else if(vis[r])r++;
            else if(vis[l]&&vis[r]){
                l++,r++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            //说明无法凑出，我们累加。
            ans++;
        }
    }
    printf("%d\n",ans);
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    solve();
    return 0;
}