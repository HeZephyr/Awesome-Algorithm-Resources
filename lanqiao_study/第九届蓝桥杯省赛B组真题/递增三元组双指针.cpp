/**
  *@filename:递增三元组双指针
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-09 11:10
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n;
int a[maxn],b[maxn],c[maxn];
void solve(){
    sort(a,a+n);
    sort(b,b+n);
    sort(c,c+n);
    ll ans=0;
    int index1=0,index2=0;
    for(int i=0;i<n;i++){
        //双指针移动。
        while(index1<n&&a[index1]<b[i])index1++;
        while(index2<n&&c[index2]<=b[i])index2++;
        ans+=(ll)index1*(n-index2);
    }
    cout<<ans<<endl;
}
int main(){
    while(cin>>n){
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        for(int i=0;i<n;i++)cin>>c[i];
        solve();
    }
    return 0;
}