/**
  *@filename:七段码
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-13 14:26
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

//为了方便我们给每个二极管一个编号，abcdefg 对应 1234567
//为了表示它们的关系，我们可以用图来表示。相邻则连边。
int graph[9][9];
bool open[9];//open[i]表示编号为i的灯是否发光。
int father[9];//并查集。
int ans;
//初始化，由于边我们已经知道了，直接赋值即可。
void init(){
    memset(graph,0,sizeof(graph));
    graph[1][2]=graph[2][1]=1;
    graph[1][6]=graph[6][1]=1;
    graph[2][7]=graph[7][2]=1;
    graph[2][3]=graph[3][2]=1;
    graph[3][4]=graph[4][3]=1;
    graph[3][7]=graph[7][3]=1;
    graph[4][5]=graph[5][4]=1;
    graph[5][6]=graph[6][5]=1;
    graph[5][7]=graph[7][5]=1;
    graph[6][7]=graph[7][6]=1;
}
int find(int x){
    int r=x;
    while(r!=father[r])r=father[r];
    return r;
}
void dfs(int index){
    //index表示当前正在填写的编号。
    if(index==8){
        //说明前七个已经填完了，我们开始处理判断。
        for(int i=1;i<=7;i++)father[i]=i;
        for(int i=1;i<=7;i++){
            for(int j=1;j<=7;j++){
                if(graph[i][j]&&open[i]&&open[j]){
                    int fx=find(i),fy=find(j);
                    if(fx!=fy)father[fx]=fy;
                }
            }
        }
        //由于我们已经合并了，所以我们现在判断亮灯的是否在同一个集合。
        int cnt=0;
        for(int i=1;i<=7;i++){
            if(open[i]&&father[i]==i)cnt++;
        }
        if(cnt==1){
            ans++;
            for(int i=1;i<=7;i++)cout<<open[i];
            cout<<endl;
        }
        return;
    }
    open[index]=1;
    dfs(index+1);
    open[index]=0;
    dfs(index+1);
}
void solve(){
    init();
    ans=0;
    memset(open,0,sizeof(open));
    dfs(1);
    cout<<ans<<endl;
}
int main(){
    solve();
    return 0;
}