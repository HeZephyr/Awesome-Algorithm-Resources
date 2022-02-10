/**
  *@filename:A_Phoenix_and_Gold
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-05 14:55
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100 + 5;
const int mod = 1e9+7;

int t,n,x,w[maxn];
int ans;
void solve(){
    //我们的想法是不让能凑成相等的w。
    if(ans==x)cout<<"NO"<<endl;
    else{
        ans=0;
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++){
            ans+=w[i];
            if(ans==x){
                ans-=w[i];
                swap(w[i],w[i+1]);
                ans+=w[i];
            }
            cout<<w[i]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    cin>>t;
    while(t--){
        cin>>n>>x;
        ans=0;
        for(int i=0;i<n;i++){
            cin>>w[i];
            ans+=w[i];
        }
        solve();
    }
    return 0;
}