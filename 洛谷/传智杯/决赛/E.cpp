/**
  *@Author: pursuit
  *@Created: 2021-03-28 16:46
**/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1e5+5;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;

int n,m;
ll w[maxn],c[maxn];
void solve(){
    int ans=0;
    int cnt1=0,cnt2=0;
    while(cnt1<n){
        if(w[cnt1]>=c[cnt2]){
            cnt1++;
            cnt2++;
            ans++;
        }
        else{
            cnt1++;
        }
    }
    cout<<ans<<endl;
}
int main(){
    while(cin>>n>>m){
        for(int i=0;i<n;i++){
            cin>>w[i];
        }
        for(int i=0;i<m;i++){
            cin>>c[i];
        }
        sort(c,c+m);
        sort(w,w+n);
        solve();
    }
    return 0;
}