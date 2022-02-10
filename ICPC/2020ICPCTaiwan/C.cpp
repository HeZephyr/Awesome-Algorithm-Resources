/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-08-10 15:33
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl
#define x first 
#define y second
#define double long double
using namespace std;

typedef pair<double,double> pdd;
typedef long long ll;
const int N = 2e3 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
const double PI = acos(-1);

struct node{
    double dist;
    int i,j;
    bool operator < (const node &A) const{
        return dist > A.dist;
    }
};
int n;
priority_queue<node> q;
pdd points[N];
bool vis[N];//判断是否已经停止生长。
double r[N];
double getDistance(pdd a,pdd b){
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}
void solve(){
    for(int i = 1; i <= n; ++ i){
        for(int j = i + 1; j <= n; ++ j){
            q.push({getDistance(points[i],points[j]) / 2.0,i,j});
        }
    }
    node head;
    double ans = 0;
    while(!q.empty()){
        head = q.top();
        q.pop();
        //cout << head.dist << " " << head.i << " " << head.j << endl;
        if(vis[head.i] && vis[head.j])continue;
        if(vis[head.j])swap(head.i,head.j);
        if(vis[head.i]){
            //说明i已经停止生长。
            if(fabs(getDistance(points[head.i],points[head.j]) - head.dist - r[head.i]) <= EPS){
                vis[head.j] = true;
                ans += head.dist * head.dist * PI;
                r[head.j] = head.dist;
            }
            else{
                q.push({getDistance(points[head.i],points[head.j]) - r[head.i],head.i,head.j});
            }
        }
        else{
            //cout << ans << endl;
            vis[head.i] = true;
            vis[head.j] = true;
            ans += 2 * head.dist * head.dist * PI;
            r[head.i] = head.dist,r[head.j] = head.dist;
        }
    }
    cout << fixed << setprecision(8) << ans << endl;
}
int main(){	
    cin >> n;
    for(int i = 1; i <= n; ++ i){
        cin >> points[i].x >> points[i].y;
    }
    solve();
    return 0;
}