/**
  *@filename:F
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-07 13:16
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200000 + 5;
const int P = 1e9+7;

int t,n,a[N],cnt[N];
int sum[N];
void solve(){
    int tot = 1;
    sort(a + 1,a + 1 + n);
    int pre = -1;
    for(int i = 1; i <= n; ++ i){
        if(pre == -1)pre = a[i];
        if(a[i] == pre){
            cnt[tot] ++;
        }
        else{
            tot ++;
            pre = a[i];
            cnt[tot] ++;
        }
    }
    sort(cnt + 1,cnt + tot + 1);
    for(int i = 1; i <= tot; ++ i){
        sum[i] = sum[i - 1] + cnt[i];
        //cout << cnt[i] << " ";
    }
    //cout << endl;
    int minn = 0x3f3f3f3f;
    for(int i = 1; i <= tot; ++ i){
        minn = min(minn,sum[i - 1] + (sum[tot] - sum[i]) - (tot - i) * cnt[i]);
    }
    printf("%d\n",minn);
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        memset(cnt,0,sizeof(cnt));
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        solve();
    }
    return 0;
}