/**
  *@filename:A
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-23 11:24
**/
#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<double,double> pdd;
const int N = 1000 + 5;
const int P = 1e9+7;

int n,m,p;
pdd judge[N],tar[N],feather[N];
bool visJudge1[N],visTar[N],visJudge2[N],visFeather[N];
struct node{
    int u,v;
    double dist;
    bool operator < (const node & A){
        if(dist == A.dist){
            return u < A.u;
        }
        return dist < A.dist;
    }
}ans1[N * N],ans2[N * N];
double getDist(pdd a,pdd b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
void solve(){
    int cnt1 = 0,cnt2 = 0;
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            ans1[++cnt1].u = i;
            ans1[cnt1].v = j;
            ans1[cnt1].dist = getDist(judge[i],tar[j]);
        }
    }
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= p; ++ j){
            ans2[++cnt2].u = i;
            ans2[cnt2].v = j;
            ans2[cnt2].dist = getDist(judge[i],feather[j]);
        }
    }
    sort(ans1 + 1, ans1 + 1 + cnt1);
    sort(ans2 + 1, ans2 + 1 + cnt2);
    double sum = 0;
    for(int i = 1; i <= cnt1; ++ i){
        if(!visJudge1[ans1[i].u] && !visTar[ans1[i].v]){
            sum += ans1[i].dist;
            //cout << sum << endl;
            visJudge1[ans1[i].u] = true;
            visTar[ans1[i].v] = true;
        }
    }
    for(int i = 1; i <= cnt2; ++ i){
        if(!visJudge2[ans2[i].u] && !visFeather[ans2[i].v]){
            sum += ans2[i].dist;
            //cout << sum << endl;
            visJudge2[ans2[i].u] = true;
            visFeather[ans2[i].v] = true;
        }
    }
    printf("%.8lf\n",sum);
}
int main(){
    scanf("%d%d%d", &n, &m, &p);
    for(int i = 1; i <= n; ++ i){
        scanf("%lf%lf", &judge[i].x, &judge[i].y);
    }
    for(int i = 1; i <= m; ++ i){
        scanf("%lf%lf", &tar[i].x, &tar[i].y);
    }
    for(int i = 1; i <= p; ++ i){
        scanf("%lf%lf", &feather[i].x, &feather[i].y);
    }
    solve();
    return 0;
}