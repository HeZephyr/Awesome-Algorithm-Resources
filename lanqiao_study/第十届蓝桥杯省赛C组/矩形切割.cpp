/**
  *@filename:矩形切割
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-13 00:53
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int h=2019,w=324;
void solve(){
    int ans=0;
    while(h>0&&w>0){
        ans++;
        int h_temp=h,w_temp=w;
        int temp=min(h,w);
        if(h_temp==temp)w-=temp;
        if(w_temp==temp)h-=temp;
        cout<<h<<" "<<w<<endl;
    }
    cout<<ans<<endl;
}
int main(){
    solve();
    return 0;
}