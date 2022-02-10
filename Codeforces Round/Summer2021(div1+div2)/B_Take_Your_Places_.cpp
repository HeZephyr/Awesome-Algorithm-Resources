/**
  *@filename:B_Take_Your_Places_
  *@author: pursuit
  *@created: 2021-08-29 22:52
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n,a[N],cnt[2];
ll cal(int idx,vector<int> odd){
    ll res = 0;
    for(auto x : odd){
        res += abs(x - idx);
        idx += 2;
    }
    return res;
}
void solve(){
    if((n % 2 == 0 && cnt[0] == cnt[1]) || (n % 2 && abs(cnt[0] - cnt[1]) == 1)){
        vector<int> odd;
        for(int i = 1; i <= n; ++ i){
            if(a[i] % 2)odd.push_back(i);
        }
        ll minn = 1e12,idx;
        if(n & 1){
            //看odd size大小。
            if(cnt[1] > n / 2){
                idx = 1;
            }
            else{
                idx = 2;
            }
            minn = min(minn,cal(idx,odd));
        }
        else{
            minn = min(minn, min(cal(1,odd),cal(2,odd)));
        }
        printf("%d\n", minn);
    }
    else{
        puts("-1");
    }
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        cnt[0] = cnt[1] = 0;
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
            ++ cnt[a[i] % 2];
        }
        solve();
    }
    return 0;
}