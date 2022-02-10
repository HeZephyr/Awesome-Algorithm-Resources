#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
//混合背包即01背包+完全背包+多重背包。
//我们可以将多重背包转化为01背包。利用二进制优化来解决。即分组成01背包和完全背包。
const int maxn=1e4+10;
int n,m;
vector<pii> p1,p2;//p1存储01背包，p2存储多重背包。
int dp[maxn];
int main(){
    cin>>n>>m;
    int v,w,s;
    for(int i=1;i<=n;i++){
        cin>>v>>w>>s;
        if(s==-1){
            //说明只能用一次，我们直接放入01背包即可。
            p1.push_back({v,w});
        }
        else if(s==0){
            //说明可以用无限次，我们放入完全背包。
            p2.push_back({v,w});
        }
        else{
            int k=1;
            while(k<=s){
                p1.push_back({k*v,k*w});
                s-=k;
                k*=2;
            }
            if(s>0)p1.push_back({s*v,s*w});
        }
    }
    //分完组之后就可以进行处理了。
    for(int i=0;i<p1.size();i++){
        for(int j=m;j>=p1[i].first;j--){
            dp[j]=max(dp[j],dp[j-p1[i].first]+p1[i].second);
        }
    }
    for(int i=0;i<p2.size();i++){
        for(int j=p2[i].first;j<=m;j++){
            dp[j]=max(dp[j],dp[j-p2[i].first]+p2[i].second);
        }
    }
    cout<<dp[m]<<endl;
    return 0;
}