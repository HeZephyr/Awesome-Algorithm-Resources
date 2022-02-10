/**
  *@filename:第九题
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-15 20:40
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n,a[maxn];
void solve(){
}
int main(){
    int maxx=INT_MIN;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(i>0)maxx=max(maxx,a[i]-a[i-1]);
        }
        cout<<maxx<<endl;
    }    
    solve();
    return 0;
}