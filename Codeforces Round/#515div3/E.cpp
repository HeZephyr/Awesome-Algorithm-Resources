/**
  *@filename:E
  *@author: pursuit
  *@created: 2021-08-23 21:31
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 998244353;
const int INF = 0x3f3f3f3f;

//考虑贡献，每个移动一次就相当于在a中贡献了一次。累加前缀和即可。
int n,m,sum[N];
char a[N],b[N];
int ksm(int n, int q){
    int ans = 1;
    while(q){
        if(q & 1)ans = 1LL * ans * n % P;
        q >>= 1;
        n = 1LL * n * n % P;
    }
    return ans;
}
void solve(){
    //我们需要从低位处理到高位。为了方便，所以我们需要反转字符串。
    reverse(a + 1, a + 1 + n);
    reverse(b + 1, b + 1 + m);
    for(int i = 1; i <= n; ++ i){
        if(a[i] == '1'){
            sum[i] = ksm(2, i - 1);
        }
    }
    for(int i = 1; i <= m; ++ i){
        sum[i] = (sum[i] + sum[i - 1]) % P;
    }
    int res = 0;
    for(int i = 1; i <= m; ++ i){
        //考虑每一位的贡献。
        if(b[i] == '1'){
            res = (res + sum[i]) % P;
        }
    }
    printf("%d\n", res);
}
int main(){	
    scanf("%d%d", &n, &m);
    scanf("%s%s", a + 1, b + 1);
    solve();
    return 0;
}