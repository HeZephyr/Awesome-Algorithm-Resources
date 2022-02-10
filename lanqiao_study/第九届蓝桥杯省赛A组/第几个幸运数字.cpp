/**
  *@filename:第几个幸运数字
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-03 23:57
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

set<ll> t;
ll maxx=59084709587505;
ll a[]={3,5,7};
void solve(){
    ll now,head=1;
    while(true){
        for(int i=0;i<3;i++){
            now=head*a[i];
            if(now<=maxx){
                t.insert(now);
            }
        }
        //更新起点。
        head=*t.upper_bound(head);
        if(head==maxx){
            break;
        }
    }
    cout<<head<<endl;
    cout<<t.size()<<endl;//1905
}
int main(){
    solve();
    return 0;
}