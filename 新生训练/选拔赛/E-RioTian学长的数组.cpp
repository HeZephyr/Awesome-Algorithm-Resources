#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = 1000 + 5;
 
int t,n,k;
int a[maxn];
void solve(){
    //前+后-。
    int l=1,r=n;
    while(k){
        while(a[l]==0&&l<r)l++;
        if(l>=r)break;
        a[l]--,a[r]++;
        k--;
    }
    for(int i=1;i<=n;i++){
        cout<<a[i];
        i==n?cout<<endl:cout<<" ";
    }
}
int main(){
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)cin>>a[i];
        solve();
    }
    return 0;
}