/**
  *@filename:不要62
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-12 19:56
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int l,r;
int f[11][11];//f[i][j]表示i位数且最高位为j的方案数。
//那么我们来对这个进行分析，对于f[i][j]这个状态，我们根据题意我们转移的f[i-1][k]必须满足k!=4,j!=4.
//并且jk!=62.
void init(){
    for(int i=0;i<10;i++)f[1][i]=1;
    //排除4的情况。
    f[1][4]=0;
    for(int i=2;i<11;i++){
        for(int j=0;j<10;j++){
            if(j==4)continue;
            for(int k=0;k<10;k++){
                if((j==6&&k==2)||k==4)continue;
                f[i][j]+=f[i-1][k];
            }
        }
    }
}
int dp(int n){
    if(!n)return 1;
    vector<int> a;//存储分割位数。
    int ans=0,last=0;//last保存上一位的值。
    while(n)a.push_back(n%10),n/=10;
    for(int i=a.size()-1;i>=0;i--){
        int x=a[i];
        for(int j=0;j<x;j++){
            //走左边分支，我们需要判断。
            if(j==4||(j==2&&last==6))continue;
            ans+=f[i+1][j];
        }
        if(x==4||(last==6&&x==2))break;
        last=x;
        if(!i)ans++;
    }
    return ans;
}
void solve(){
}
int main(){
    init();
    while(cin>>l>>r&&(l||r)){
        cout<<dp(r)-dp(l-1)<<endl;
        solve();
    }
    return 0;
}