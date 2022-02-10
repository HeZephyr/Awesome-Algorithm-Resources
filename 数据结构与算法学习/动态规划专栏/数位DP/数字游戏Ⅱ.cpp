/**
  *@filename:数字游戏Ⅱ
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-12 18:23
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;

int l,r,p;
int f[12][12][110];//f[i][j][k]表示i位数，最高位是j，其模n的余数是k的方案数。
//预处理也是一个dp过程。
int mod(int x,int y){
    //由于c++中的%负数会得到负数，所以我们需要做一个偏移。
    return (x%y+y)%y;
}
void init(){
    memset(f,0,sizeof(f));
    //预处理f数组。
    for(int i=0;i<10;i++)f[1][i][i%p]++;
    for(int i=2;i<12;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<p;k++){
                for(int x=0;x<10;x++){
                    f[i][j][k]+=f[i-1][x][mod(k-j,p)];
                }
            }
        }
    }
}
int dp(int n){
    if(!n)return 1;
    vector<int> a;//存储切出来的位数。
    while(n)a.push_back(n%10),n/=10;
    int last=0;//last存储前面数字之和。
    int ans=0;
    for(int i=a.size()-1;i>=0;i--){
        int x=a[i];
        for(int j=0;j<x;j++){
            //走左边分支。为了凑成模n余0，则接下来的所有位数相加+last模n为0，所以我们来个-last即可。
            ans+=f[i+1][j][mod(-last,p)];
        }
        last+=x;
        if(!i&&last%p==0)ans++;//判断本身是否符合条件。
    }
    return ans;
}
void solve(){
}
int main(){
    while(cin>>l>>r>>p){
        init();
        cout<<dp(r)-dp(l-1)<<endl;
    }
    solve();
    return 0;
}