/**
  *@Author: pursuit
  *@Created: 2021-03-28 16:34
**/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1e5+5;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;

int n;
ll a[maxn];
ll k;
void solve(){
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]*a[j]<=k){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    while(cin>>n>>k){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        solve();
    }
    return 0;
}