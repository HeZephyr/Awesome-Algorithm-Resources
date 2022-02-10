/**
  *@filename:E1
  *@author: pursuit
  *@created: 2021-09-04 17:18
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, k, a[N];
int get(int x){
    int sum = 1;
    for(int i = 2; i * i <= x; ++ i){
        if(x % i == 0){
            int cnt = 0;
            while(x % i == 0){
                x /= i;
                ++ cnt;
            }
            if(cnt & 1)sum *= i;
        }
    }
    sum *= x;
    return sum;
}
void solve(){
    map<int, int> p;
    int res = 1;
    for(int i = 1; i <= n; ++ i){
        int x = get(a[i]);
        if(p[x]){
            ++ res;
            p.clear();
        }
        ++ p[x];
    }
    printf("%d\n", res);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &k);
        for(int i =  1; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        solve();
    }
    return 0;
}