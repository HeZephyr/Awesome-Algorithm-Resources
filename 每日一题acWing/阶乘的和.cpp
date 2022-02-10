/**
  *@filename:阶乘的和
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-16 21:15
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1000000 + 5;
const int P = 1e9+7;

int n;
int a[13];
bool vis[N];
void init(){
    a[0]=1,a[1]=1;
    for(int i=2;i<11;i++){
        a[i]=a[i-1]*i;
    }
    for(int i=1;i<1024;i++){
        int sum=0;
        for(int j=0;j<12;j++){
            if(i>>j&1)sum+=a[j];
        }
        vis[sum]=true;
    }
}
void solve(){
    int n;
    init();
    while(cin>>n){
        if(n<0)break;
        if(vis[n])cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
int main(){
    solve();
    return 0;
}