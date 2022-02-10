/**
  *@filename:发现环
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-29 19:06
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n,a,b;//n台电脑。
int father[maxn];
vector<int> ans;//存储出现环路的电脑。
vector<int> g[maxn];//无向图。 
bool vis[maxn];//vis[i]表示i是否已经进入结果序列。
vector<int> result;//结果序列。
bool flag;//判断是否找到回路。
int find(int x){
    int r=x;
    while(r!=father[r])r=father[r];
    int i=x,j;
    while(father[i]!=r){
        j=father[i];
        father[i]=r;
        i=j;
    }
    return r;
}
void dfs(int st,int ed){
    if(st==ed){
        //说明回路已经搜索完成，此时直接退出。
        sort(result.begin(),result.end());
        for(int i=0;i<result.size();i++){
            printf("%d%c",result[i],i==result.size()-1?'\n':' ');
        }
        flag=true;
        return;
    }
    for(int i=0;i<g[st].size();i++){
        int u=g[st][i];
        if(!vis[u]&&!flag){
            result.push_back(u);
            vis[u]=true;
            dfs(u,ed);
            //回溯。
            result.pop_back();
            vis[u]=false;
        }
    }
    return;
}
int main(){
    scanf("%d",&n);
    int st,ed;
    for(int i=1;i<=n;i++)father[i]=i;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a,&b);
        g[a].push_back(b),g[b].push_back(a);
        int fa=find(a),fb=find(b);
        if(fa!=fb){
            father[fa]=fb;
        }
        else{
            //说明a和b已经连接了，此时再次连接则会出现环路。所以我们可以记录环路的起点和终点。
            st=a,ed=b;
        }
    }
    vis[st]=true;
    result.push_back(st);
    dfs(st,ed);
    return 0;
}