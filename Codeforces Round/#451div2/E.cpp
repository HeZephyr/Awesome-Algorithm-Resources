/**
  *@filename:E
  *@author: pursuit
  *@created: 2021-08-12 15:39
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n;
ll x;
ll a[N],b[N];
int cnta,cntb;
ll cal(ll *a,int x,int n){
    ll res = 0;
    sort(a + 1,a + 1 + n);
    for(int i = 1; i <= x; ++ i){
        //cout << a[i] << endl;
        res += a[i];
    }
    return res;
}
void solve(){
    if(cnta == cntb){
        puts("0");
    }
    else{
        printf("%lld\n",cnta > cntb ? cal(a,cnta - n / 2,cnta) : cal(b,cntb - n / 2,cntb));
    }
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%lld", &x);
        int temp = sqrt(x);
        if(temp * temp == x){
            if(x)a[++cnta] = 1;
            else a[++cnta] = 2;
        }
        else{
            b[++cntb] = min((temp + 1) * (temp + 1) - x,x - temp * temp);
        }
    }
    solve();
    return 0;
}