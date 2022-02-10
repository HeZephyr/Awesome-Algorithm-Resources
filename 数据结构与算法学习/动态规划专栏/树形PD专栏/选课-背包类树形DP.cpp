/**
  *@filename:选课
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-25 18:16
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 300 + 5;
const int P = 1e9+7;

int n,m;//n门课程和m个需要选择的课程。
int w[N];
struct node{
    int v,next;
}edges[N << 1];
//每门课的先修课最多一门，说明每个结点最多只有一个父亲，则实际上是构成了一个森林结构。
//我们可以建一个虚拟课程0号结点，将森林转化为一个n + 1结点的树，其中结点0为根结点。
int tot,head[N];//root为根结点。
bool vis[N];
int f[N][N];
//在这个题目中，我们必须选择先修课，即根结点，才可以去选择孩子结点。
//那么我们则可以用f[u][k]表示在以u为根的子树中选择k门课程能获得的最高学分。
void add(int u,int v){
    edges[++tot].v = v;
    edges[tot].next = head[u];
    head[u] = tot;
    //printf("%d -> %d\n",u,v);
}
void dfs(int u,int fu){
    f[u][0] = 0;//不用选择课程当前学分自然为0。
    for(int i = head[u]; i; i = edges[i].next ){
        int v = edges[i].v;
        if(v == fu)continue;
        //printf("%d -> %d\n",u,v);
        dfs(v,u);
        //开始循环枚举背包体积。
        for(int j = m - 1; j >= 0; j -- ){
            //枚举子树的背包体积。
            for(int k = 1; k <= j; k ++ ){
                if(j >= k){
                    //这里需要判断根结点的体积是否大于等于分给子树的体积。
                    f[u][j] = max(f[u][j],f[u][j - k] + f[v][k]);
                }
            }
        }
    }
    //这个结点是必须要选择的。所以我们需要加上。
    for(int j = m; j >0; j -- ){
        f[u][j] = f[u][j-1] + w[u];
    }
}
void solve(){
    //由于多选择了一个虚拟结点，所以m++。
    m++;
    dfs(0,-1);
    printf("%d\n",f[0][m]);
}
int main(){
    scanf("%d%d",&n,&m);
    int u;
    for(int i = 1; i <= n; i++){
        scanf("%d%d",&u,&w[i]);
        add(u,i);
    }
    solve();
    return 0;
}