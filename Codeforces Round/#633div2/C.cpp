/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-08-14 21:36
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n,a[N];
//t秒可以给数组中的任意元素加上2^{t-1}次方。找到与前面差值最大的，它可以了其他就可以了。
int cal(int x){
    int res = 0;
    while(x){
        x /= 2;
        res ++;
    }
    return res;
}
void solve(){
    int cnt = 0,minn = a[n];
    for(int i = n - 1; i >= 1; -- i){
        cnt = max(cnt,a[i] - minn);
        minn = min(minn,a[i]);
    }
    printf("%d\n",cnt == 0 ? 0 : cal(cnt));
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        solve();
    }
    return 0;
}