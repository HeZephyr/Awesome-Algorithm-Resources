#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 505;
int a[N][N];
bool vis[N][N];
struct node{
    int x, y, id;
    bool operator < (const node t) const{
        return id<t.id;
    }
};
ll nx[5] = {1, -1, 0, 0};
ll ny[5] = {0, 0, 1, -1};
priority_queue<node> q;
int n;
double m, ans[N][N];
int main(){
    scanf("%d%lf", &n, &m);
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            scanf("%d", &a[i][j]);
            q.push({i, j, a[i][j]});
            ans[i][j] = m;
        }
    }
    while(!q.empty()){
        node tem = q.top();
        q.pop();
        int cnt = 0;
        for(int i = 0;i < 4;i++){
            int tx = tem.x + nx[i];
            int ty = tem.y + ny[i];
            if(tx<=0 || tx>n || ty<=0 || ty>n || a[tx][ty]>=tem.id) continue;
            cnt++;
        }
        double tt = ans[tem.x][tem.y]/(cnt*1.0);
        //printf("cnt = %d\n", cnt);
        //printf("tt = %lf, %lf\n", tt, ans[tem.x][tem.y]);
        for(int i = 0;i < 4;i++){
            int tx = tem.x + nx[i];
            int ty = tem.y + ny[i];
            if(tx<=0 || tx>n || ty<=0 || ty>n || a[tx][ty]>=tem.id) continue;
            ans[tx][ty] += tt;
            //printf("tt = %lf, %lf\n", tt, ans[tx][ty]);
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(a[i][j]==0) printf("%.6lf ", ans[i][j]);
            else printf("0 ");
        }
        printf("\n");
    }
    return 0;
}