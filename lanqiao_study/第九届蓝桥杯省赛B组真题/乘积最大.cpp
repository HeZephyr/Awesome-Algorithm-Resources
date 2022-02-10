/**
  *@filename:乘积最大
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-10 19:49
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const ll mod = 1000000009;

int n,k;
ll a[maxn];
void solve(){
    sort(a,a+n); 
    ll result=1;
    int sign=1;//符号标志。
    if(k%2){
        result=a[n-1],k--,n--;
        if(result<0){
            sign=-1;
        }
    }
    int l=0,r=n-1;
    while(k){
        ll temp1=a[l]*a[l+1],temp2=a[r]*a[r-1];
        if(temp1*sign>=temp2*sign){
            result=temp1%mod*result%mod;
            l+=2;
        }
        else{
            result=temp2%mod*result%mod;
            r-=2;
        }
        k-=2;
    }
    cout<<result%mod<<endl;
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