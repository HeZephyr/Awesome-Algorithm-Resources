/**
  *@filename:D
  *@author: pursuit
  *@created: 2021-08-21 15:37
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,a[N],dp1[N],dp2[N];
void solve(){
    for(int i = 2; i <= n; ++ i){
        if(a[i] > a[i - 1]){
            dp1[i] = dp1[i - 1] + 1;
        }
    }
    for(int i = n - 1; i >= 1; -- i){
        if(a[i] < a[i + 1]){
            dp2[i] = dp2[i + 1] + 1;
        }
    }
    //枚举删除的元素。
    int maxx = 0;
    for(int i = 1; i <= n; ++ i){
        maxx = max(maxx,dp1[i]);
        if(i >= 2 && i <= n - 1 && a[i - 1] < a[i + 1]){
            //debug(i);
            maxx = max(maxx,dp1[i - 1] + dp2[i + 1]);
        }
    }
    printf("%d\n", maxx);
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        dp1[i] = 1;
        dp2[i] = 1;
    }
    solve();
    return 0;
}