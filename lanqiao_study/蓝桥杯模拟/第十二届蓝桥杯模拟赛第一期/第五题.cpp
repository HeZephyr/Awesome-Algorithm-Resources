/**
  *@filename:第五题
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-15 19:58
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int a[]={87,39,35,1,99,11,54,1,46,24,74,62,49,13,2,80,24,58,8,14,83,23,97,85,3,2,86,10,71,15};
void solve(){
    int ans=0;
    int n=sizeof(a)/4;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j])ans++;
        }
    }
    cout<<ans<<endl;//218
}
int main(){
    solve();
    return 0;
}