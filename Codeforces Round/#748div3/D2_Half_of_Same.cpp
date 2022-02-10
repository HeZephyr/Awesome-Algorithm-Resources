/**
  *@filename:D2_Half_of_Same
  *@author: pursuit
  *@created: 2021-10-16 16:36
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, a[N];
void solve(){
    sort(a + 1, a + 1 + n);
    int maxx = 0, cnt = 1;
    for(int i = 2; i <= n; ++ i){
        if(a[i] != a[i - 1]){
            maxx = max(cnt, maxx);
            cnt = 1;
        }
        else ++ cnt;
    }
    maxx = max(maxx, cnt);
    if(maxx * 2 >= n)puts("-1");
    else{
        //存所有因子。
        set<int> v1, v2;
        for(int i = 1; i <= n; ++ i){
            for(int j = i + 1; j <= n; ++ j){
                v1.insert(a[j] - a[i]);
            }
        }
        for(auto x : v1){
            for(int j = 1; j * j <= x; ++ j){
                if(x % j)continue;
                v2.insert(j), v2.insert(x / j);
            }
        }
        int res = 0;
        for(auto x : v2){
            //枚举要变成的数。
            for(int i = 1; i <= n / 2 + 1; ++ i){
                int cnt = 1;
                for(int j = i + 1; j <= n; ++ j){
                    if((a[j] - a[i]) % x == 0)++ cnt;
                }
                if(cnt * 2 >= n){
                    res = x;
                }
            }
        }
        cout << res << endl;
    }
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n;
        for(int i = 1; i <= n; ++ i){
            cin >> a[i];
        }
        solve();
    }
    return 0;
}