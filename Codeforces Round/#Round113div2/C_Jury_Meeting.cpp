/**
  *@filename:C_Jury_Meeting
  *@author: pursuit
  *@created: 2021-09-08 23:04
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 998244353;
const int INF = 0x3f3f3f3f;

//就是找出符合排列的个数，
//使得排列满足按顺序提问没有一个人连续讲述问题。ai代表问题数。没有问题的人会跳过
int t, n, a[N], fac[N];
void init(){
    fac[0] = fac[1] = 1;
    for(int i = 2; i < N; ++ i){
        fac[i] = 1LL * fac[i - 1] * i % P;
    }
}
int ksm(int n, int q){
    int ans = 1;
    while(q){
        if(q & 1){
            ans = 1LL * ans * n % P;
        }
        n = 1LL * n * n % P;
        q >>= 1;
    }
    return ans;
}
void solve(){
    sort(a + 1, a + n + 1, greater<int>() );
    if(a[1] - a[2] > 1){
        puts("0");
    }
    else{
        ll res = 1;
        if(a[1] == a[2]){
            //说明怎么排列都没有关系。
            res = fac[n];
        }
        else{
            int cnt = 0;
            for(int i = 2; i <= n; ++ i){
                if(a[i] == a[2])++ cnt;
                else break;
            }
            //Anm = n!/(n - m)!;
            res = 1LL * fac[cnt] * cnt % P * fac[n] % P * ksm(fac[cnt + 1], P - 2) % P;
        }
        printf("%lld\n", res);
    }
}
int main(){	
    scanf("%d", &t);
    init();
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        solve();
    }
    return 0;
}