/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-09-01 10:31
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e6 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int a, b, c, d;
ll sum[N];
void solve(){
    //做差分。
    for(int i = a; i <= b; ++ i){
        ++ sum[i + b], -- sum[i + c + 1];
    }
    for(int i = 1; i < N; ++ i){
        sum[i] += sum[i - 1];
    }
    for(int i = 1; i < N; ++ i){
        sum[i] += sum[i - 1];
    }
    ll res = 0;
    for(int i = c; i <= d; ++ i){
        res += sum[N - 1] - sum[i];
    }
    printf("%lld\n", res);
}
int main(){
    scanf("%d%d%d%d", &a, &b, &c, &d);	
    solve();
    return 0;
}