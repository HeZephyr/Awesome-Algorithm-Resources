/**
  *@filename:E
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-28 18:11
**/
#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 200000 + 5;
const int P = 1e9+7;
const int INF = 0x3f3f3f3f;

int n;
pii a[N];
int dp[N];//dp[i]表示前i个数分完组后的差的和。
int t[N],p[N];
void solve(){
    sort(a + 1, a + 1 + n);
    //需要注意i从
    for(int i = 1; i <= n; ++ i){
        dp[i] = INF;
    }
    for(int i = 1; i <= n; ++ i){
        //枚举第i个数属于的区间长度。
        for(int len = 3; len <= 5 && i + len - 1 <= n; ++ len){
            int diff = a[i + len - 1].x - a[i].x;//获取差值。
            if(dp[i + len - 1] > dp[i - 1] + diff){
                dp[i + len - 1] = dp[i - 1] + diff;
                p[i + len - 1] = i;//为上界，即从[i,i + j - 1]的区间。
                //cout << "i:" << i << " len:" << len << " value:" << dp[i + len - 1] << endl;
            }
        }
    }
    int cur = n,cnt = 0;
    while(cur != 0){
        cnt ++;
        for(int i = cur; i >= p[cur]; -- i){
            //遍历区间。
            t[a[i].y] = cnt;
        }    
        cur = p[cur] - 1;//获取下一个区间。
    }
    printf("%d %d\n", dp[n], cnt);
    for(int i = 1; i <= n; ++ i){
        cout << t[i] << " ";
    }
    cout << endl;
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i].x);
        a[i].y = i;
    }
    solve();
    return 0;
}