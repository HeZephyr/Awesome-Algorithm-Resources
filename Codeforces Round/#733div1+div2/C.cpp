/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-10-31 11:51
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, a[N], b[N];
ll sum1, sum2;
ll pre1[N], pre2[N];
bool check(int x){
    ll ans1 = sum1, ans2 = sum2;
    int temp1 = (n + x) / 4;//需要减掉的数量。
    int temp2 = temp1;
    temp2 = max(0, temp2 - x);
    ans2 -= pre2[temp2];//最终的得分。
    ans1 = ans1 - pre1[temp1] + x * 100;
    return ans1 >= ans2;
}
void solve(){
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    for(int i = 1; i <= n; ++ i){
        pre1[i] = pre1[i - 1] + a[i];
        pre2[i] = pre2[i - 1] + b[i];
    }
    int l = 0, r = n;
    while(l < r){
        //枚举需要添加的阶段。
        int mid = (l + r) >> 1;
        //让a全添加100，b全添加0。
        if(check(mid)){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    printf("%d\n", l);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        sum1 = sum2 = 0;
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
            sum1 += a[i];
        }
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &b[i]);
            sum2 += b[i];
        }
        solve();
    }
    return 0;
}