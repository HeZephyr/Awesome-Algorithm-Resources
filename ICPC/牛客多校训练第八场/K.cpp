/**
  *@filename:K
  *@author: pursuit
  *@created: 2021-08-09 13:23
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int t;
double w,d;
void solve(){
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%lf%lf", &w, &d);
        double minn = min(w, d), dist = sqrt(w * w + d * d);
        ll ans = 0;
        for(int i = 0; i <= 2; ++ i){
            if(i * minn <= PI){
                ans = max(ans, (ll)(4 + 2 * i + floor((PI - i * minn) / dist) * 3)); 
            }
            if(i * dist <= PI){
                ans = max(ans, (ll)(4 + 3 * i + floor((PI - i * dist) / minn) * 2));
            }
        }
        printf("%lld\n", ans);
    }                                         
    return 0;
}