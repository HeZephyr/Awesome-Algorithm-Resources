/**
  *@filename:B
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-18 14:28
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

ll n;
void solve(){
}
int main(){
    while(cin>>n){
        int cnt0=0,cnt1=0,cnt2=0;//cnt0统计所有情况，cnt1统计两个数相等的情况，cnt2统计三个数相等的情况
        for(ll i=1;i*i*i<=n;i++){
            if(n%i)continue;
            for(ll j=i;i*j*j<=n;j++){
                if(n%j)continue;
                ll k=n/(i*j);
                if(i*j*k==n){
                    cnt0++;
                    if(i==j&&j==k){
                        cnt2++;
                    }
                    else if(i==j||j==k||i==k){
                        cnt1++;
                    }
                }
            }
        }
        cout<<cnt0<<" "<<cnt1<<" "<<cnt2<<endl;//406 2 0
        //不相等6种排列，只有两个相等三种排列，三个相等一种排列。
        cout<<cnt0*6-cnt1*3-cnt2*5<<endl;//2430
    }
    solve();
    return 0;
}