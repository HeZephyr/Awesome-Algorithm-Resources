#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
const int maxn = 100 + 5;
const int mod = 1e9 + 7;
int a[maxn] , m , dig[maxn] , cnt;
ll dp[65][2][2][2] , L;
int f[500];
//进位时，一定是
ll cal (int sum , int one , int li)
{
    //sum为数位和的奇偶性，one为连续1的个数的奇偶性，li为是否限定上界。
    int s = (li ? L % 128 : 127);
    int ans = 0;
    for (int i = 0 ; i <= s ; i++){
        //暴力处理。
        bool ok = true;
        for (int j = 0 ; j < m && ok ; j++){
            if (i + j < 128) ok = ((f[i + j] ^ sum) == a[j]);
            else ok = ((f[i + j] ^ one ^ sum) == a[j]);
        }
        ans += ok;
    }
    return ans;
}
ll dfs (int step , int sum , int one , int li) {
    //step为当前需要考虑的位的长度，sum为数位和的奇偶性。one为从第七位开始的连续1的个数的奇偶性。
    //li为是否限定上界。
    ll &x = dp[step][sum][one][li];
    //记忆化搜索。
    if (~x) return x;
    if (step <= 6){
        //小于6位直接暴力统计。
        x = cal(sum , one , li);
        return x;
    }
    //获取当前位的取值。
    int up = (li ? dig[step] : 1);
    ll ans = 0;
    for (int i = 0 ; i <= up ; i++){
        //获取连续1的个数。
        int no = one;
        if (i) no ^= 1;
        else no = 0;
        //sum统计数位和的奇偶性。
        ans += dfs(step - 1 , sum ^ i , no , li && i == up);
    }
    //记忆化赋值。
    return x = ans;
}
ll solve (ll x)
{
    memset(dp , -1 , sizeof dp);
    cnt = 0;
    int len = 0;
    for (int i = 63 ; i >= 0 ; i--){
        dig[i] = (x >> i) & 1;
        //找到最大的位，同时将位的情况存储起来。
        if (dig[i]) len = max(len , i);
    }
    //开始数位dp。
    return dfs(len , 0 , 0 , 1);
}
int main()
{
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (int i = 1 ; i < 500 ; i++)
        //提前处理好前500内的f(x)对2取余的值。
        f[i] = (f[i >> 1] + (i & 1))%2;
    while (t--){
        cin >> m; cin >> L;
        for (int i = 0 ; i < m ; i++) cin >> a[i];
        cout << solve (L) << endl;
    }
    return 0;
}
