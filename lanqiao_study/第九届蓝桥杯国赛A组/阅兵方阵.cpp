/**
  *@filename:阅兵方阵
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-07 21:56
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

//要求士兵能恰好组成两个方阵。不一样恰好是两种队形，暴力枚举即可。对于出现过的标记即可。
int a[maxn];
void init(){
    for(int i=1;i<1000;i++){
        a[i]=i*i;
    }
}
int check(int x){
    int ans=0;
    for(int i=1;a[i]*2<=x;i++){
        int temp=sqrt(x-a[i]);
        if(temp*temp==x-a[i]){
            ans++;
        }
    }
    return ans;
}
void solve(){
    init();
    for(int i=1;;i++){
        if(check(i)==12){
            cout<<i<<endl;//160225
            break;
        }
    }
}
int main(){
    solve();
    return 0;
}