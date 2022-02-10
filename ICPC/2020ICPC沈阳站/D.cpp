#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//当从第i步走到第j步时，如果走过得红色步数数量是奇数，那么会很满意。
int n;
int cnt, limit;//统计已经输出了多少字符串了。
char s[N];
void dfs(int idx, int cntb, int cntr, int st){
    if(cnt >= 100 || cntb > limit || cntr > limit)return;
    if(idx == n + 1){
        cout << s + 1 << endl;
        ++ cnt;
        return;
    }
    s[idx] = 'b';
    dfs(idx + 1, cntb + (st ^ 1), cntr + st, st);
    st ^= 1;
    s[idx] = 'r';
    dfs(idx + 1, cntb + (st ^ 1), cntr + st, st);
}
int main(){	
    cin >> n; 
    cout << 1LL * (n + 1) / 2 * ((n + 2) / 2) << endl;
    s[n + 1] = '\0';
    limit = (n + 2) / 2;
    dfs(1, 1, 0, 0);//这里将cntb设置成1.
    return 0;
}