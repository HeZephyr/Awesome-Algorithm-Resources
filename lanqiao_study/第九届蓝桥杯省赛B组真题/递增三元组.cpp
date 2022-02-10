/**
  *@filename:递增三元组
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-08 20:22
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
    sort(c,c+n);
    ll ans=0;
    ll index1,index2;
    ll l,r,mid;
    for(int i=0;i<n;i++){
        //二分查找数组a中第一个大于等于b[i]的下标。
        l=0,r=n;
        while(l<r){
            mid=(l+r)>>1;
            if(a[mid]>=b[i])r=mid;
            else l=mid+1;
        }
        index1=r;
        //二分查找数组c中第一个大于b[i]的下标。
        l=0,r=n;
        while(l<r){
            mid=(l+r)>>1;
            if(c[mid]>b[i])r=mid;
            else l=mid+1;
        }
        index2=l;
        ans+=index1*(n-index2);
        //cout<<index1<<" "<<i<<" "<<index2<<endl;
    }
    cout<<ans<<endl;
}
int main(){
    while(cin>>n){
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        for(int i=0;i<n;i++)cin>>c[i];
        //排序之后二分寻找答案。
        solve();
    }
    return 0;
}