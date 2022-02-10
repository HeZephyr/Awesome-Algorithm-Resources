/**
  *@filename:第六题
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-15 20:04
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

//总感觉这种模拟赛把我当弱智。
int l,h;
void solve(){
    if(l%2==0||h%2==0)printf("%d\n",l*h/2);
    else printf("%.1f\n",1.0*l*h/2);
}
int main(){
    while(cin>>l>>h){
        solve();
    }
    return 0;
}