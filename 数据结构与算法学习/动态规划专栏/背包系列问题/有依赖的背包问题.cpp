#include<bits/stdc++.h>

using namespace std;

const int maxn=110;
int n,m;//n个物品，容量m。
int v[maxn],w[maxn];
//对于这种有依赖的dp问题，我们还是可以按照闫式DP分析法来解决。
//首先对于状态的表示，我们可以认为dp[i][j]表示以i做为根结点，体积不超过j的最大价值。
//那么这个实际上是比较广的，因为我们不清楚树的结构，即是根结点的子树选择情况，这个我们可以通过递归解决。
//即dp[i][j]=dp[i][j-k]+dp[u][k];这个状态计算表示的就是以i为根结点，体积不超过j-k的最大价值加上以u为根结点体积不超过k的最大价值。
//也就是根结点+子树的最大价值。
vector<int> g[maxn];//存储树结构。
int root;//根结点。
int dp[maxn][maxn];//dp[i][j]表示的以i作为根结点，体积不超过j的最大价值。
void dfs(int root){
    //选取这个作为结点，我们必须要选择这个，所以我们可以确定一个上限。
    for(int j=v[root];j<=m;j++)dp[root][j]=w[root];//接下来考虑子树，相当于对子树进行分组。即0~m-v[root]。
    for(int i=0;i<g[root].size();i++){
        int son=g[root][i];
        dfs(son);//递归求出子树的最大价值。
        for(int j=m;j>=v[root];j--){
            for(int k=0;k<=j-v[root];k++){
                //k为留给子树的体积分配。
                dp[root][j]=max(dp[root][j],dp[root][j-k]+dp[son][k]);
            }
        }
    }
}
int main(){
    cin>>n>>m;
    int father;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i]>>father;
        if(father==-1){
            root=i;
        }
        else{
            g[father].push_back(i);
        }
    }
    dfs(root);
    cout<<dp[root][m]<<endl;
    return 0;
}