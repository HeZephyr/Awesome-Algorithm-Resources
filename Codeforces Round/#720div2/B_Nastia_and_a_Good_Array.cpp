/**
  *@filename:B_Nastia_and_a_Good_Array
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-07 23:32
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;
const int inf = 0x3f3f3f3f;

int t,n,a[maxn];
void solve(){
    //每次选择最小的a和b。
    //gcd(a,a+1)=1
    int minn=inf,pos;
    for(int i=1;i<=n;i++){
        if(a[i]<minn){
            minn=a[i];
            pos=i;
        }
    }
    //接下来开始更改，和i同性质的放a[i]，反之放a[i]+1.
    printf("%d\n",n-1);
    for(int i=1;i<=n;i++){
        if(i!=pos){
            if(i%2==pos%2){
                printf("%d %d %d %d\n",i,pos,a[pos],a[pos]);
            }
            else{
                printf("%d %d %d %d\n",i,pos,a[pos]+1,a[pos]);
            }
        }
    }
}
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        solve();
    }
    return 0;
}