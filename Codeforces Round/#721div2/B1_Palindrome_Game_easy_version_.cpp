/**
  *@filename:B1_Palindrome_Game_easy_version_
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-24 08:49
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 500 + 5;
const int P = 1e9+7;

int t,n;
string s;
int dp[N][N][2][2];//dp[same][diff][mid][rev]表示双方在最优策略下，局面为(same,diff,mid,rev)时当前选手与对手的花费差。
//same:表示对称的0的对数，即满足0 <= i <= n/2-1 且ai = an-i+1 = 0的i的数量。
//diff:表示不对称的0的数量。即满足0 <= i <= n-1 时且ai = 0 and ai != an-i+1的i的数量。
//mid:表示字符串长度是否为奇数，且an/2 = 0。
//rev:表示上一步是否为反转操作。
//则当diff > 0 and rev = 0 时，我们可以反转字符串，花费0，此时dp[same][diff][mid][1] = -dp[same][diff][mid][0];
//注意这里的same无需更改，因为我们已经让rev置为1了，表示已经反转了。
//若same > 0，我们可以将一个对称的0改为1，花费1。注意这里我们需要求rev = 0的状态，这样same才是same。
//dp[same][diff][mid][0] = 1 - dp[same - 1][diff + 1][mid][0];
//当diff > 0时，我们可以将一个不对称的0改为1，花费1。此时这里我们需要求rev = 0的状态。这样same才是same。
//dp[same][diff][mid][0] = 1 - dp[same][diff + 1][mid][0].
//若mid > 0，可以将中间的0改为1，花费1。dp[same][diff][mid][rev] = 1 - dp[same][diff][0][0]。
bool vis[N][N][2][2];
int dfs(int same,int diff,int mid,int rev){
    int &ans = dp[same][diff][mid][rev];
    if(vis[same][diff][mid][rev]){
        return ans;
    }
    //开始去模拟判断选择情况。
    ans = 0x3f3f3f3f;
    if(diff && rev == 0){
        //此时这个状态可以反转字符串。
        ans = min(ans,-dfs(same,diff,mid,1));//1代表已经反转了字符串。
    }
    if(same){
        //此时这个状态可以将对称的0修改为1.
        ans = min(ans,1 - dfs(same - 1,diff + 1,mid,0));
    }
    if(mid){
        //此时这个状态可以将中间的0改为1.
        ans = min(ans,1 - dfs(same,diff,0,0));
    }
    if(diff){
        //此时这个状态可以将不对称的0修改为1.
        ans = min(ans,1 - dfs(same,diff - 1,mid,0));
    }
    vis[same][diff][mid][rev] = true;
    return ans;
}
void solve(){
    int same = 0,diff = 0,mid = (n % 2 && s[n / 2] == '0');
    for(int i = 0; i <= n / 2 -1; i++){
        if(s[i] == '0' && s[i] == s[n - i - 1])same ++;
        else if(s[i] == '0' || s[n - i - 1] == '0')diff ++;
    }
    int ans = dfs(same,diff,mid,0);
    if(ans > 0){
        puts("BOB");
    }
    else if(ans == 0){
        puts("DRAW");
    }
    else{
        puts("ALICE");
    }
}
int main(){
    cin >> t;
    dp[0][0][0][0] = 0;
    vis[0][0][0][0] = true;
    dp[0][0][0][1] = 0;
    vis[0][0][0][1] = true;
    while(t--){
        cin >> n >> s;
        solve();
    }
    return 0;
}