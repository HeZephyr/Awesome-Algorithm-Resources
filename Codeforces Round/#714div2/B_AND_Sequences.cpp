/**
  *@filename:B_AND_Sequences
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-15 19:06
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 200000 + 5;
const int mod = 1e9+7;

int t,n;
ll a[maxn], p[maxn];//阶乘。
void init(){
    p[0]=1,p[1]=1;
    for(int i=2;i<maxn;i++){
        p[i]=p[i-1]*i%mod;
    }
}
void solve(){
    ll minn=a[0];//将a数组中的数字相与得到结果。
    for(int i=1;i<n;i++){
        minn=minn&a[i];
    }
    //cout<<"minn:"<<minn<<endl;
    //接下来去寻找有没有两个或两个以上的minn值。
    ll cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]==minn)cnt++;
    }
    //cout<<"cnt:"<<cnt<<endl;
    //至少需要有两个。
    if(cnt<2)puts("0");
    else{
        //全排列问题。左右两边固定填放minn值，中间n-2全排列。
        cout<<cnt*(cnt-1)%mod*p[n-2]%mod<<endl;
    }
}
int main(){
    init();
    while(cin>>t){
        while(t--){
            cin>>n;
            for(int i=0;i<n;i++)cin>>a[i];
            solve();
        }
    }
    return 0;
}