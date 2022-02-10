/**
  *@filename:F
  *@author: pursuit
  *@created: 2021-08-23 22:02
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl
#define x first
#define y second

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,m;
map<int,vector<pii> > levels;//存储每个级别的坐标点。
pii a,b,c,d;
ll dp[N][2];
bool cmp(pii a,pii b){
    if(a.x == b.x){
        return a.y > b.y;//列相同，按行排序。
    }
    return a.x < b.x;
}
int dist(pii a,pii b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}
void solve(){
    levels[0].push_back({0,0});
    for(auto &it : levels)sort(it.second.begin(), it.second.end(), cmp);
    fill(dp[0], dp[0] + N * 2, 1e18);
    dp[0][0] = dp[1][0] = 0;//初始化。
    int cur = 0, pre = 0;
    for(auto &it : levels){
       ++ cur;
       //取出当前级别第一个点和最后一个点。
       a = it.second[0], b = it.second.back();
       //取出先前级别第一个点和最后一个点。
       c = levels[pre][0], d = levels[pre].back();
       dp[cur][0] = min(dp[cur][0], dp[cur - 1][0] + 
       dist(c,b) + dist(b,a));
       dp[cur][0] = min(dp[cur][0], dp[cur - 1][1] + 
       dist(d,b) + dist(b,a)); 
       dp[cur][1] = min(dp[cur][1], dp[cur - 1][0] + 
       dist(c,a) + dist(a,b));
       dp[cur][1] = min(dp[cur][1], dp[cur - 1][1] + 
       dist(d,a) + dist(a,b)); 
       pre = it.first;
    }
    printf("%lld\n", min(dp[cur][0], dp[cur][1]));
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d%d", &a.x, &a.y);
        levels[max(a.x,a.y)].push_back(a);
    }
    solve();
    return 0;
}