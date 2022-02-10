/**
  *@filename:P2357
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-26 18:23
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 200000 + 5;
const ll mod = 1e9+7;

int n,f;//n块墓碑，f次世界末日。
//由于设计到区间修改和区间修改，所以我们需要利用差分数组来实现。
//由于我们利用差分数组，那么我们如何完成区间查询呢？区间查询的基础是快速求出数组a[1:n]的前缀和。
//而显然数组a[1:n]的前缀和为a[1]+a[2]+...+a[i]=d[1]*i+d[2]*(i-1)+...+d[i]*1;
//则右侧可以化为：d[1]*(i+1)+d[2]*(i+1)+...+d[i]*(i+1)-(d[1]*1+d[2]*2+...+d[i]*i)
//=(i+1)*(d[1]+d[2]+...+d[i])-(d[1]*1+d[2]*2+...+d[i]*i)
//所以我们可以在原来的数组c[i]记录d[i]的基础上。再弄一个数组记录d[i]*i即可。
ll c1[maxn],c2[maxn];
int lowbit(int x){
    return x&(-x);
}
void add(int pos,ll x){
    for(int i=pos;i<=n;i+=lowbit(i)){
        c1[i]+=x;
        c2[i]+=x*pos;
    }
}
void update(int l,int r,ll x){
    add(l,x),add(r+1,-x);
}
ll get(int pos){
    ll ans=0;
    int i=pos;
    while(i>0){
        ans+=c1[i]*(pos+1)-c2[i];
        cout<<ans<<endl;
        i-=lowbit(i);
    }
    cout<<pos<<" "<<ans<<endl;
    return ans;
}
ll range_get(ll l,ll r){
    return get(r)-get(l-1);
}
void solve(){
    int op,l,r;
    ll k;
    while(f--){
        scanf("%d",&op);
        if(op==1){
            scanf("%d%d%d",&l,&r,&k);
            update(l,r,k);
        }
        else if(op==2){
            scanf("%d",&k);
            add(1,k);
        }
        else if(op==3){
            scanf("%d",&k);
            add(1,-k);
        }
        else if(op==4){
            scanf("%d%d",&l,&r);
            printf("%d\n",range_get(l,r));
        }
        else{
            printf("%d\n",range_get(1,1));
        }
    }
}
int main(){
    ll pre=0,cur;
    scanf("%d%d",&n,&f);
    for(ll i=1;i<=n;i++){
        scanf("%d",&cur);
        add(i,cur-pre);
        pre=cur;
    }
    solve();
    return 0;
}