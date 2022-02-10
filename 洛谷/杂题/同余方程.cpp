/**
  *@filename:同余方程
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-29 12:31
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

ll a,b;
ll x,y;//存储解。
ll exGcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int gcd=exGcd(b,a%b,x,y);
    int temp=x;//temp=x2;
    x=y;//x1=y2;
    y=temp-a/b*y;//y1=x2-a/b*y2;
    return gcd;
}
void solve(){
    int gcd=exGcd(a,b,x,y);
    //此时我们得到了x,y。利用公式求解最小值。
    cout<<((x%(b/gcd)+(b/gcd))%(b/gcd))<<endl;
}
int main() {
    while(cin>>a>>b){
        solve();
    }
    return 0;
}