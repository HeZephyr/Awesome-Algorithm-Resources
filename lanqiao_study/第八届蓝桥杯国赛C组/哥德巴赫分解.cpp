/**
  *@filename:哥德巴赫分解
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-30 13:57
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 10000 + 5;
const int mod = 1e9+7;

int isprimer[maxn],primer[maxn];
int ans=0;
void init(){
    memset(isprimer,true,sizeof(isprimer));
    for(int i=2;i<10000;i++){
        if(isprimer[i]){
            primer[++primer[0]]=i;
            for(int j=i+i;j<10000;j+=i){
                isprimer[j]=false;
            }
        }
    }
}
void cal(int x){
    for(int i=1;i<=primer[0];i++){
        int t=x-primer[i];
        if(t>0&&isprimer[t]){
            ans=max(ans,primer[i]);
            return;
        }
    }
}
void solve(){
    init();
    for(int i=4;i<10000;i+=2)cal(i);
    cout<<ans<<endl;//173
}
int main(){
    solve();
    return 0;
}