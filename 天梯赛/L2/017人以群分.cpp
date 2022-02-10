/**
  *@filename:017人以群分
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-20 21:52
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n;
ll a[maxn];
ll ans1=0,ans2=0;
void solve(){
    sort(a,a+n);
    int n1=n/2,n2=n-n1;
    for(int i=0;i<n1;i++)ans1+=a[i];
    for(int i=n1;i<n;i++)ans2+=a[i];
    printf("Outgoing #: %d\n",n2);
    printf("Introverted #: %d\n",n1);
    printf("Diff = %lld\n",ans2-ans1);
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    solve();
    return 0;
}