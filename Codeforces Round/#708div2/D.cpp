/**
* @filename:D.cbp
* @Author : pursuit
* @Blog:unique_pursuit
* @email: 2825841950@qq.com
* @Date : 2021-03-18-11.04.27
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn=1e5+5;
const int mod=1e9+7;

int t,n;
void solve(){
    vector<ll> s(n),tag(n),dp(n,0);//dp[i]表示以问题i结尾的最大分数。
    for(int i=0;i<n;i++){
        cin>>tag[i];
    }
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int j=1;j<n;j++){
        //这里我们枚举状态点。我们从低到高枚举状态点这样保证了我们的IQ是永远满足条件的。
        for(int i=j-1;i>=0;i--){
            if(tag[i]==tag[j]){
                //标记相同，不能解决问题。
                continue;
            }
            ll dpi=dp[i],dpj=dp[j],p=abs(s[i]-s[j]);
            dp[i]=max(dp[i],dpj+p);//这个表示我们解决完j后去解决i
            dp[j]=max(dp[j],dpi+p);
        }
    }
    ll maxx=0;
    for(auto x:dp){
        maxx=max(maxx,x);
    }
    cout<<maxx<<endl;
}
int main(){
    while(cin>>t){
        while(t--){
            cin>>n;
            solve();
        }
    }
    return 0;
}
