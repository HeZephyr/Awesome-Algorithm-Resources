/**
  *@filename:016愿天下有情人都是失散多年的兄妹
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-20 21:22
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

struct node{
    int fa,mo,sex;//1男0女。
};
node info[maxn];//info[i]表示id为i的信息。
int step[maxn];//表示代数。
bool vis[maxn];//vis[i]表示id为i的是否存在。
int n,m;
void solve(){
    int a,b;
    cin>>m;
    while(m--){
        cin>>a>>b;
        if(info[a].sex==info[b].sex){
            puts("Never Mind");
            continue;
        }
        memset(step,0,sizeof(step));
        step[a]=step[b]=1;
        set<int> s;//用于判断是否有相同祖先。
        queue<int> q;
        q.push(a),q.push(b);
        bool flag=false;
        while(!q.empty()){
            int head=q.front();
            q.pop();
            int size=s.size();
            s.insert(head);
            if(size==s.size()){
                puts("No");
                flag=true;
                break;
            }
            if(!vis[head])continue;
            if(step[head]<=4){
                if(info[head].fa!=-1){
                    q.push(info[head].fa);
                    step[info[head].fa]=step[head]+1;
                }
                if(info[head].mo!=-1){
                    q.push(info[head].mo);
                    step[info[head].mo]=step[head]+1;
                }
            }
        }
        if(!flag)puts("Yes");
    }
}
int main(){
    cin>>n;
    int id,fa,mo;
    char op[2];
    for(int i=0;i<n;i++){
        cin>>id>>op>>fa>>mo;
        info[id].fa=fa,info[id].mo=mo;
        if(op[0]=='M')info[id].sex=1;
        else info[id].sex=0;
        vis[id]=true;
        info[fa].sex=1,info[mo].sex=0;//这里需要记录父母的性别。
    }
    solve();
    return 0;
}