/**
  *@filename:B_Moamen_and_k_subarrays
  *@author: pursuit
  *@created: 2021-08-09 22:41
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n,k;
int a[N],b[N];
void solve(){
    sort(b + 1,b + n + 1);
    int len = unique(b + 1, b + n + 1) - (b + 1);
    int cnt = 0;
    for(int i = 1; i <= n; ++ i){
        a[i] = lower_bound(b + 1,b + 1 + len,a[i]) - b;
    }
    int i = 2;
    while(i <= n){
        while(a[i] == a[i - 1] + 1 && i <= n)i ++;
        cnt ++,i ++;
    }
    if(a[n] == a[n - 1] + 1)cnt --;
    if(cnt + 1 <= k){
        puts("Yes");
    }
    else{
        puts("No");
    }
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        solve();
    }	
    return 0;
}