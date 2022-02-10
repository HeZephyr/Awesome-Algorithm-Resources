/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-09-11 19:03
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, a[N];
ll sum;
map<ll, vector<int> > p;
void solve(){   
    if(sum % 3 != 0){
        cout << 0 << endl;
        return;
    }
    ll cnt = 0, res = 0;
    for(int i = 1; i <= n; ++ i){
        cnt += a[i];
        p[cnt].push_back(i);//前缀和。
    } 
    for(int i = 0; i < p[sum / 3].size(); ++ i){
        int x = p[sum / 3][i];
        int len = p[sum / 3 * 2].size();
        int idx = upper_bound(p[sum / 3 * 2].begin(), p[sum / 3 * 2].end(), x) - p[sum / 3 * 2].begin();
        if(len > 0 && p[sum / 3 * 2][len - 1] == n){
            -- len;
        }
        if(idx >= 0 && idx < len ){
            res += len - idx;
        }
    }
    cout << res << endl;
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        sum += a[i];
    }
    solve();
    return 0;
}