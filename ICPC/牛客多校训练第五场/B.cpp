/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-08-06 10:14
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl;

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

double ans,sum;
int n;
double c,w[N];
void solve(){
    sort(w + 1, w + 1 + n);
    double f = 1.0;
    for(int i = n; i; -- i){
        ans += (1.0 - f) * w[i];
        f /= 2;
    }
    //要么全开。要么在最开始花一次，然后相当于一个01序列一样开过去即可。
    printf("%.8lf\n", min(sum,c + ans));
}
int main(){	
    scanf("%d%lf", &n, &c);
    for(int i = 1; i <= n; ++ i){
        scanf("%lf", &w[i]);
        sum += w[i];
    }
    solve();
    return 0;
}