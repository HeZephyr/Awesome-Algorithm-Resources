/**
  *@filename:分巧克力
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-30 19:08
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n,k;
struct node{
    int h,w;
};
node chocolate[maxn];
//二分法枚举我们的最大边长。
bool check(int a){
    //判断是否满足条件。
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=(chocolate[i].h/a)*(chocolate[i].w/a);
        if(ans>=k)return true;
    }
    return false;
}
void solve(){
    int l=1,r=maxn;
    while(l<r){
        //cout<<l<<" "<<r<<endl;
        int mid=(l+r+1)>>1;//注意这里一定要+1，再进行除2，避免减小mid的值。
        if(check(mid)){
            l=mid;//往右区间枚举。
        }
        else{
            r=mid-1;//往左区间枚举。
        }
    }
    cout<<l<<endl;
}
int main() {
    while(cin>>n>>k){
        for(int i=0;i<n;i++){
            cin>>chocolate[i].h>>chocolate[i].w;
        }
        solve();
    }
    return 0;
}