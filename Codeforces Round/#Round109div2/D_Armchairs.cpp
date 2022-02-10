/**
  *@filename:D_Armchairs
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-16 16:26
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 5010;
const int P = 1e9+7;

int n,a[N];
int s[N];//前缀和判断。
void solve(){
    vector<int> pos;
    for(int i=1;i<=n;i++){
        if(a[i])pos.push_back(i);//存好位置之后直接暴力枚举。如果遇到占用，那就前面的往前移即可。
    }
    ll ans=0;
    for(int i=0;i<pos.size();i++){
        int x1=0,minn1=N;
        for(int j=pos[i]-1;j>=1;j--){
            if(a[j]!=1){
                if(j+a[j]-s[j]>0){
                    //a[j]*(-1)为这里需要往后移的。如果填这的话，需要多少的差值。
                    
                    minn1=pos[i]-j;
                    x1=j;
                    break;
                }
            }
        }
        int x2=0,minn2=N;
        for(int j=pos[i]+1;j<=n;j++){
            if(a[j]!=1){
                if(j-a[j]<=n){
                    //说明空间够用。
                    minn2=j-pos[i];
                    x2=j;
                    break;
                }
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],s[i]=s[i-1]+a[i];
    solve();
    return 0;
}