/**
* @filename:C.cbp
* @Author : pursuit
* @Blog:unique_pursuit
* @email: 2825841950@qq.com
* @Date : 2021-03-18-08.47.26
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn=1e5+5;
const int mod=1e9+7;

//数学构造类问题。
int t,n,k;
void solve(){
    //和处理C1一样，我们可以先输出k-3个1，这样问题就和C1一样了。
    for(int i=1;i<=k-3;i++){
        cout<<1<<" ";
    }
    n-=(k-3);
    //我们需要对n的奇偶性判断。
    if(n%2){
        //为奇数，我们只要输出1 (n-1)/2 (n-1)/2即可。
        cout<<1<<" "<<(n-1)/2<<" "<<(n-1)/2<<endl;
    }
    else{
        //为偶数的话，我们需要在n/2上做处理
        if(n%4==0){
            //如果n/4也是偶数，那么n/2 n/4 n/4则满足构造条件。
            cout<<n/2<<" "<<n/4<<" "<<n/4<<endl;
         }
         else{
            //如果不是偶数，那么我们就可以构造偶数，其我们易知偶数的因子有2.
            cout<<n/2-1<<" "<<n/2-1<<" "<<2<<endl;
         }
    }
}
int main(){
    while(cin>>t){
        while(t--){
            cin>>n>>k;
            solve();
        }
    }
    return 0;
}
