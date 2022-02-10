#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int inf=1e9;
const int N=2e5+10;
set<pair<int,int>>ans;
map<pair<int,int>,int>mp;
int n,m,k,q;
int *dis[45][4][N];
int dir[4][2]={{0,-1},{0,1},{1,0},{-1,0}};//黑洞的上下左右四个方向
struct node
{
    int x,y;
    int dist;
};
void bfs()
{
    for(auto iter=ans.begin();iter!=ans.end();iter++)
    {//遍历每个黑洞
        int x=(*iter).first;        //黑洞的坐标
        int y=(*iter).second;
        int idx=mp[make_pair(x,y)]; //黑洞的编号
        for(int i=0;i<4;i++)
        {//遍历该黑洞的4个方向
            int dx=x+dir[i][0];
            int dy=y+dir[i][1];
            //判断是否越界。
            if(dx<1||dx>n||dy<1||dy>m) continue; //越界
            if(ans.count(make_pair(dx,dy))) continue; //如果这个点也是黑洞
            for(int j=1;j<=n;j++)
            {
                dis[idx][i][j]=new int[m+5];
                for(int k=1;k<=m;k++)
                    dis[idx][i][j][k]=inf;
            }
            dis[idx][i][dx][dy]=0;
            queue<node>que;
            node p;
            p.x=dx,p.y=dy,p.dist=0;
            que.push(p);
            while(!que.empty())
            {
                node now=que.front();
                que.pop();
                for(int j=0;j<4;j++)
                {
                    int fx=now.x+dir[j][0];
                    int fy=now.y+dir[j][1];
                    if(fx<1||fx>n||fy<1||fy>m) continue;
                    if(dis[idx][i][fx][fy]!=inf) continue;
                    if(ans.count(make_pair(fx,fy))) continue;
                    dis[idx][i][fx][fy]=now.dist+1;
                    que.push({fx,fy,dis[idx][i][fx][fy]});
                }
            }
        }
    }
}
bool check(int x1,int y1,int x2,int y2)
{
    if(x1>x2) swap(x1,x2);
    if(y1>y2) swap(y1,y2);
    for(auto iter=ans.begin();iter!=ans.end();iter++)
    {
        //遍历每个黑洞。
        int dx=(*iter).first;
        int dy=(*iter).second;
        //判断矩形范围内是不是有黑洞。
        if(dx>=x1&&dx<=x2&&dy>=y1&&dy<=y2)//矩形范围内存在黑洞
            return false;
    }
    return true;
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&k,&q);
    for(int i=1;i<=k;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        ans.emplace(x,y);   //将黑洞以pair的形式存入set中
        mp[make_pair(x,y)]=i;//将每个黑洞编号
    }
    bfs();
    while(q--)
    {
        int xs,ys,xt,yt;
        scanf("%d%d%d%d",&xs,&ys,&xt,&yt);  //输入起点和终点
        //如果区域中没有黑洞，那么返回曼哈顿距离
        if(check(xs,ys,xt,yt)) printf("%d\n",abs(xs-xt)+abs(ys-yt));
        else
        {
            int res=inf;
            for(auto iter=ans.begin();iter!=ans.end();iter++)//遍历每个黑洞
            {
                int x=(*iter).first;
                int y=(*iter).second;
                int idx=mp[make_pair(x,y)];//黑洞的编号
                for(int i=0;i<4;i++)
                {
                    int dx=x+dir[i][0];
                    int dy=y+dir[i][1];
                    if(dx>n||dx<1||dy>m||dy<1) continue; //越界
                    if(ans.count(make_pair(dx,dy))) continue; //如果查询的点也是黑洞
                    res=min(res,dis[idx][i][xs][ys]+dis[idx][i][xt][yt]);
                }
            }
            if(res==inf) printf("-1\n");
            else printf("%d\n",res);
        }
    } 
    //system("pause");
    return 0;
}
