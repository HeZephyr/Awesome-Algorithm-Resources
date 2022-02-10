/**
  *@filename:A
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-08 19:00
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;
const ll inf = 0x3f3f3f3f3f;

ll n,x,p[maxn];
bool cmp(int i,int j){
    return p[i]<p[j];
}
ll gcd(ll n,ll m){
    return n%m?gcd(m,n%m):m;
}
void solve(){
    ll up=0,down=1, maxx=-1,minn=inf,idx1=-1,idx2=-1;
    int l=1,r=2;
    while(l<n){
        while(l>=r)r++;
        if(minn>p[l]){
            minn=p[l];
            idx1=l;
        }
        if(maxx<p[r]){
            maxx=p[r];
            idx2=r;
        }
        if(l>=idx2){
            maxx=p[l+1];
            idx2=l+1;
            for(int i=l+1;i<=r;i++){
                if(maxx<p[i]){
                    maxx=p[i];
                    idx2=i;
                }
            }
        }
        if(r<=idx1){
            minn=p[l+1];
            for(int i=l+1;i<=r;i++){
                if(minn>p[i]){
                    minn=p[i];
                    idx1=i;
                }
            }
        }
        if(maxx*down>minn*up){
            up=maxx,down=minn;
        }
        l++;
    }
    ll temp=gcd(x*up,down);
    cout<<x*up/temp<<"/"<<down/temp<<endl;
}
int main(){
    while(cin>>n>>x){
        for(int i=1;i<=n;i++)cin>>p[i];
        solve();
    }
    return 0;
}