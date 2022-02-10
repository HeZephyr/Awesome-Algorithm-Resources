/**
  *@filename:001凑零钱
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-23 10:15
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n,m;//硬币总数和要付的款额。
int coins[maxn];
int result[maxn];//存储路径。
bool flag;//判断是否已经找到方案了。
int cnt;//全局变量，记录已经选取了几个，以及作为索引使用。
int ans;
void dfs(int step,int sum){
    if(sum>m)return;
    if(sum==m){
        //说明已经找到。
        flag=true;
        for(int i=0;i<cnt;i++){
            cout<<result[i];
            i==cnt-1?cout<<endl:cout<<' ';
        }
        return;
    }
    //开始枚举选择。
    for(int i=step;i<n;i++){
        result[cnt++]=coins[i];
        dfs(i+1,sum+coins[i]);
        if(flag)break;
        cnt--;
    }
}
int main(){
    cin>>n>>m;
    cnt=0,flag=false,ans=0;
    for(int i=0;i<n;i++){
        cin>>coins[i];
        ans+=coins[i];
    }
    if(ans<m){
        puts("No Solution");
        return 0;
    }
    else if(ans==m){
        sort(coins,coins+n);
        for(int i=0;i<n;i++){
            cout<<coins[i];
            i==n-1?cout<<endl:cout<<" ";
        }
    }
    else{
        sort(coins,coins+n);
        dfs(0,0);
        if(!flag)puts("No Solution");
    }
    return 0;
}