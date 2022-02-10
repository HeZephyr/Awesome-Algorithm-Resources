#include<bits/stdc++.h>

using namespace std;

const int N = 510, M = 20;
int t, n, m, w;//n个朋友，m个礼物，w资产。
int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
struct node{
    int ans, day, v;
    bool operator < (const node &A){
        return ans < A.ans;
    }
}a[N];
int c[M], v[M], f[M];//f[i]表示给i个人发礼物能得到的最大好感度。
int dp[M][N];//dp[j][k]表示给j个人发礼物，且当前时间为k所获得的最大好感度。
void dfs(int idx, int ans, int cnt, int w){
    //idx为当前考虑第几个礼物，ans为当前所获得的好感度，cnt为当前选取的礼物数量，w为当前的金钱数量。
    if(ans > f[cnt])f[cnt] = ans;//更新最优解。
    //考虑当前的idx。是否选取。
    if(idx > m)return;
    if(w >= c[idx])dfs(idx + 1, ans + v[idx], cnt + 1, w - c[idx]);
    dfs(idx + 1, ans, cnt, w);
}
void solve(){
    dfs(1, 0, 0, w);
    /* for(int i = 1; i <= m; ++ i){
        cout << f[i] << " ";
    }
    cout << endl; */
    sort(a + 1, a + 1 + n);
    int res = 0;
    for(int i = 1; i <= n; ++ i){
        for(int j = m; j >= 0; -- j){
            for(int k = a[i].ans; k >= 0; -- k){
                //给第i个人做蛋糕。
                if(k >= a[i].day){
                    dp[j][k] = max(dp[j][k], dp[j][k - a[i].day] + a[i].v);
                }
                if(j){
                    //说明可以送礼物，假设送礼物给第i个人。注意要减去之前算的状态。
                    dp[j][k] = max(dp[j][k], dp[j - 1][k] + f[j] - f[j - 1]);
                }
                res = max(res, dp[j][k]);
            }
        }
    }
    printf("%d\n", res);
}
int main(){
    scanf("%d", &t);
    for(int i = 1; i <= 12; ++ i)months[i] += months[i - 1];//前缀和便于处理。
    while(t -- ){
        memset(f, 0, sizeof(f));
        memset(dp, 0, sizeof(dp));
        scanf("%d%d%d", &n, &m, &w);
        for(int i = 1, y, m, d, day, v; i <= n; ++ i){
            scanf("%d-%d-%d%d%d", &y, &m, &d, &day, &v);
            if(m == 2 && d == 29){
                //由于2021年是闰年，故轮不到当天。
                -- i, -- n;
            }
            else{
                a[i].ans = (months[m - 1] + d), a[i].day = day, a[i].v = v;
            }
            //cout << y << " " << m << " " << d << " " << a[i].ans << endl;
        }
        for(int i = 1; i <= m; ++ i){
            scanf("%d%d", &c[i], &v[i]);
        }
        solve();
    }
    return 0;
}