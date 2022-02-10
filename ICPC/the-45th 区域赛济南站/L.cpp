#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int t, m, a[110], digit[65];
int f[300];//提前计算好256前的数位和奇偶性。
ll L, dp[65][2][2][2];
void init(){
    for(int i = 1; i <= 256; ++ i){
        f[i] = (f[i >> 1] + (i & 1)) % 2;
    }
}
ll cal(bool sum, bool cnt, bool limit){
    int up = limit ? L % 128 : 127;
    ll ans = 0;
    for(int i = 0; i <= up; ++ i){
        bool flag = true;
        for(int j = 0; j < m && flag; ++ j){
            if(i + j < 128){
                //说明没有进位。
                flag = (f[i + j] ^ sum) == a[j];
            }
            else{
                //说明存在进位，此时需要将多余的cnt给删掉。
                flag = (f[i + j] ^ cnt ^ sum) == a[j];
            }
        }
        ans += flag;
    }
    return ans;
}
ll dfs(int pos, bool sum, bool cnt, bool limit){
    //pos为当前正在处理的为，sum为当前数位和奇偶性，cnt为从第八位开始连续1的个数的奇偶性，limit为是否限定上界。
    ll &x = dp[pos][sum][cnt][limit];
    //cout << pos << " " << sum << " " << cnt << " " << limit << endl;
    if(~x)return x;
    if(pos <= 6){
        return x = cal(sum, cnt, limit);
    }
    int up = limit ? digit[pos] : 1;
    ll ans = 0;
    for(int i = 0; i <= up; ++ i){
        int one = cnt;
        if(i)one ^= 1;
        else one = 0;
        ans += dfs(pos - 1, sum ^ i, one, limit && i == up);
    }
    return x = ans;
}
void solve(){
    int len = 0;
    memset(dp, -1, sizeof(dp));
    for(int i = 63; i >= 0; -- i){
        digit[i] = (L >> i) & 1;
        if(digit[i]){
            len = max(len, i);
        }
    }
    printf("%lld\n", dfs(len, 0, 0, 1));
}
int main(){
    scanf("%d", &t);
    init();
    while(t -- ){
        scanf("%d%lld", &m, &L);
        for(int i = 0; i < m; ++ i){
            scanf("%d", &a[i]);
        }
        solve();
    }
    return 0;
}