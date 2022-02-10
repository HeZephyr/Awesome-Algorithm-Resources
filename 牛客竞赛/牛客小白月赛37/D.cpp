/**
  *@filename:D
  *@author: pursuit
  *@created: 2021-08-27 19:37
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,k,a[N],b[N];
void solve(){
    ll cnt1 = 0,cnt2 = 0,maxx = 0,minn = INF, l = INF;
    for(int i = 1; i < k; ++ i){
        cnt1 += a[i],cnt2 += b[i];
    }
    for(int i = k; i <= n; ++ i){
        cnt1 += a[i],cnt2 += b[i];
        if(cnt1 > maxx){
            maxx = cnt1;
            minn = cnt2;
            l = i - k + 1;
        }
        else if(cnt1 == maxx){
            if(cnt2 < minn){
                minn = cnt2;
                l = i - k + 1;
            }
        }
        cnt1 -= a[i - k + 1], cnt2 -= b[i - k + 1];
    }
    printf("%d\n", l);
}
int main(){	
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &b[i]);
    }
    solve();
    return 0;
}