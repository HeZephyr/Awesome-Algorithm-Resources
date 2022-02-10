/**
  *@filename:K倍区间
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-31 15:38
**/
/*
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

//立马想到利用前缀和去写。
ll pre[maxn];
int n,k;
void solve(){
    //枚举起点和长度，统计。
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j+i<=n;j++){
            if((pre[i+j]-pre[j])%k==0){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}
int main() {
    while(cin>>n>>k){
        int temp;
        memset(pre,0,sizeof(pre));
        for(int i=1;i<=n;i++){
            cin>>temp;
            pre[i]=pre[i-1]+temp;//初始化前缀和。
        }
        solve();
    }
    return 0;
}*/
/**
  *@filename:K倍区间
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-31 16:21
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int pre[maxn];//存储前缀和。
map<int,int> p;//标记余数的出现次数。
int n,k;
int main() {
    while(cin>>n>>k){
        int temp;
        ll ans=0;
        p[0]=1;//由于余数为0的可以自己凑成，所以我们这里考虑将这里标记为1.
        pre[0]=0;
        for(int i=1;i<=n;i++){
            cin>>temp;
            pre[i]=(pre[i-1]+temp)%k;
            ans+=p[pre[i]];//两个余数相等的前缀和就可以凑成一个k倍区间。
            p[pre[i]]++;
        }
        cout<<ans<<endl;
    }
    return 0;
}