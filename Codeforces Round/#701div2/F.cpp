/**
  *@filename:F
  *@author: pursuit
  *@created: 2021-09-07 14:17
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//给定数组$b$，现在定义混合数组至少满足$b_i=a_i$或者$b_i=\sum_{j=1}^ia_j$。请你找出这些数组的数量。对$1e9+7$取模
我们可以转化一下，定义$sum$数组为$a$的前缀和，那么$b_i=sum_i$或者$b_i=sum_i - sum_{i - 1}$。
int t, n, b[N];
void solve(){
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &b[i]);
        }
        solve();
    }
    return 0;
}