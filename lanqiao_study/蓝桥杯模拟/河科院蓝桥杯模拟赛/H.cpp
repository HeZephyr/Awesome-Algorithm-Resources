#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

const int maxn=2e3+10;
int n,m,a,b;
vector<int> g[maxn];//无向图。
int father[maxn];
bool vis[maxn];//判断顶点是否被访问。
struct node{
    int u,w;//u表示当前遍历到的点，w表示遍历到当前点的权值之和。
    node operator=(const node A){
        this->u=A.u,this->w=A.w;
        return *this;
    }
};
queue<node> q;//bfs作用。
node head,temp;
int find(int x){
    int r=x;
    while(r!=father[r]){
        r=father[r];
    }
    return r;
}

int bfs(int x){
    //x为起点。
    memset(vis,false,sizeof(vis));//注意初始化。
    while(!q.empty())q.pop();
    head.u=x,head.w=0;
    vis[head.u]=true;
    q.push(head);
    int maxx=0;
    while(!q.empty()){
        head=q.front();
        if(head.w>maxx)maxx=head.w;
        q.pop();
        int u=head.u;
        for(int i=0;i<g[u].size();i++){
            temp.u=g[u][i];
            if(!vis[temp.u]){
                temp.w=head.w+1;
                vis[temp.u]=true;
                q.push(temp);
            }
        }
    }
    return maxx;
}
void solve(){
    int ans=0;
    for(int i=1;i<=n;i++){
        if(father[i]==i)ans++;
    }
    if(ans>1){
        //这种情况说明有的点是不能到达的。
        cout<<-1<<endl;
        return;
    }
    //对每个点跑一遍bfs求出最长路。
    int maxx=0;
    for(int i=1;i<=n;i++){
        maxx=max(maxx,bfs(i));
    }
    cout<<maxx<<endl;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)father[i]=i;
    int x,y,fx,fy;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        g[x].push_back(y),g[y].push_back(x);
        fx=find(x),fy=find(y);
        if(fx!=fy){
            //建立联系。
            father[fx]=fy;
        }
    }
    solve();
    return 0;
}