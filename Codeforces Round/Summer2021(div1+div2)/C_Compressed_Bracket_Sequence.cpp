/**
  *@filename:C_Compressed_Bracket_Sequence
  *@author: pursuit
  *@created: 2021-08-31 10:06
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//下标为奇数代表连续左括号的数量，下标为偶数代表连续右括号的数量。
int n,c[N];
void solve(){
    ll res = 0;
    for(int i = 1; i <= n; i += 2){
        //利用左括号去匹配，统计每个左括号的贡献。
        ll minn = c[i],cur = c[i];//cur统计。
        for(int j = i + 1; j <= n; ++ j){
            if(j % 2){
                //为左括号，累加。
                cur += c[j];
            }
            else{
                //为右括号，开始匹配。
                ll l = max(0LL, cur - c[j]);//记录当前消耗右括号所剩的左括号数量，实际上就是左端点。
                ll r = min({minn, cur - 1, c[i] - 1LL});
                if(l <= r){
                    res += r - l + 1;
                }
                cur -= c[j];//由于该右括号已经过期，我们用右括号左边的匹配它。
                minn = min(minn, cur);//获得更新后的cur，即抵消后剩余的。
            }
        }
    }
    printf("%lld\n", res);
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &c[i]);
    }
    solve();
    return 0;
}