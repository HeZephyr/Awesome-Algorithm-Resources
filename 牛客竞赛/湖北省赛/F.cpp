/**
  *@filename:F
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-05 20:14
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n;
queue<ll> q;
ll x[maxn];
bool vis[maxn];//vis[i]代表i已经出队。
ll cal(ll x,ll k){
    //x代表的为其耐力值，k代表是每次减少的耐力值，返回的即是需要进行的操作数。
    return x/k+(x%k!=0);
}
void solve(){
    //我们肯定不是一次一次的模拟，而是模拟能将最小的x变为0的操作。
    int t=1;//t为计数操作。
    ll s=0;//当前需要减少的耐力值。
    vector<int> result;
    while(t<=n){
        //找到最小的那个。
        ll idx=0,temp=0;//idx保存的即是最小耐力值的下标。temp保存的即是每次减少的耐力值。
        for(int i=1;i<=n;i++){
            if(vis[i])continue;
            s+=1;
            if(!idx||cal(x[idx],temp)>cal(x[i],s)){
                idx=i;
                temp=s;
            }
        }
        s=0;
        ll k=cal(x[idx],temp);//计算最小操作次数，开始更改所有的x。
        temp=0;//temp为弥补值，即当有一个已经出队了，那么temp需要弥补上s加上的1.
        for(int i=1;i<=n;i++){
            if(vis[i])continue;
            s+=1;
            ll dict=(k-1)*s+(s-temp);
            x[i]-=dict;
            if(x[i]<=0){
                vis[i]=true;
                result.push_back(i);
                temp++;
                t++;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<result[i];
        i==n?cout<<endl:cout<<" ";
    }
}
int main(){
    scanf("%d",&n);
    ll temp;
    for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
    solve();
    return 0;
}