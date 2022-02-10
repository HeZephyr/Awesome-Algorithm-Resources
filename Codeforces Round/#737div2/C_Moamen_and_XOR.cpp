/**
  *@filename:C_Moamen_and_XOR
  *@author: pursuit
  *@created: 2021-08-09 23:31
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n,k;
int f[N];
int qsm(int n,int q){
    int ans = 1;
    while(q){
        if(q & 1)ans = 1LL * ans * n % P;
        n = 1LL * n * n % P;
        q >>= 1;
    }
    return ans;
}
void solve(){
    if(k == 0){
        //此时取值唯一。
        printf("1\n");
        return;
    }
    if(n % 2 == 1){
        printf("%d\n", qsm(f[n - 1] + 1,k));
        return;
    }
    int ans = qsm(f[n - 1] - 1,k);
    for(int i = 1; i <= k; ++ i){
        ans = (1LL * ans + 1LL * qsm(f[n],k - i) * qsm(f[n - 1] - 1,i - 1) % P) % P;
    }
    printf("%d\n", ans);
}
int main(){
    scanf("%d", &t);
    f[0] = 1;//1
    for(int i = 1; i < N; ++ i){
        //10 100
        f[i] = 1LL * f[i - 1] * 2 % P;
    }
    while(t -- ){
        scanf("%d%d", &n, &k);
        solve(); 
    }	
    return 0;
}