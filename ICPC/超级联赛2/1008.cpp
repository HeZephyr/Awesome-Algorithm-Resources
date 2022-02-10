/**
  *@filename:1008
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-22 13:57
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 15000 + 10;
const int P = 1e9+7;
const int INF = 0x3f3f3f3f;

int q,t,n,m,p;//t为最大复习天数，m为复习资料数量。p为不及格课程上限。
//首先用01背包求出每门课花费k天可以最多得到多少分。
int f[550];//f[i]表示前i天最多可以得到多少分。
int dp[55][550][550];//dp[i][k][l]则表示前i门课程，复习了k天，挂了l门的最大分数。
//dp[i][k][l] = max(dp[i - 1][k - j][l - x] + f[j],dp[i][k][l])
map<string,int> mp;
struct node{
    int x,y;//x为提高的分数，y为所需要学习的天数。
};
vector<node> item[55];
void solve(){
    fill(dp[0][0],dp[0][0] + 55 * 550 * 550,-INF);
    dp[0][0][0] = 0;//初始状态。
    for(int i = 1; i <= n; ++ i){
        //求第i门课程花费k天可以最多得到多少分。
        fill(f,f + 550,-INF);
        f[0] = 0;
        for(int j = 0; j < item[i].size(); ++ j){
            for(int k = t; k >= item[i][j].y; -- k){
                f[k] = max(f[k],f[k - item[i][j].y] + item[i][j].x);
            }
        }
        for(int j = 1; j <= t; ++ j){
            for(int k = j; k <= t; ++ k){
                for(int l = 0; l <= p; ++ l){
                    if(f[j] < 0)continue;//说明没有被初始化到。
                    int flag = 0;
                    if(f[j] < 60)flag = 1;//说明这个天数学习的第i个课程没有及格。
                    if(f[j] > 100)f[j] = 100;
                    if(l >= flag){ 
                        dp[i][k][l] = max(dp[i - 1][k - j][l - flag] + f[j],dp[i][k][l]);
                    }
                }
            }
        }
    }
    int maxx = -INF;
    for(int k = 0; k <= t; ++ k){
        for(int l = 0; l <= p; ++ l){
            maxx = max(dp[n][k][l],maxx);
        }
    }
    if(maxx < 0)maxx = -1;
    cout << maxx << endl;
    for(int i = 1; i <= n; ++ i){
        item[i].clear();
    }
    mp.clear();
}
int main(){
    cin >> q;
    while(q -- ){
        cin >> n;
        string s;
        int x,y;
        for(int i = 1; i <= n; ++ i){
            cin >> s;
            mp[s] = i;
        }
        cin >> m;
        for(int i = 1; i <= m; ++ i){
            cin >> s >> x >> y;
            item[mp[s]].push_back({x,y});
        }
        cin >> t >> p;
        solve();
    }
    return 0;
}