/**
  *@filename:质数
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-13 01:05
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int primer[maxn];
void init(){
    memset(primer,0,sizeof(primer));
    for(int i=2;i<=maxn-1;i++){
        if(!primer[i]){
            primer[++primer[0]]=i;
            for(int j=i+i;j<=maxn-1;j+=i){
                primer[j]=1;
            }
        }
    }
}
void solve(){
    init();
    cout<<primer[2019]<<endl;
}
int main(){
    solve();
    return 0;
}