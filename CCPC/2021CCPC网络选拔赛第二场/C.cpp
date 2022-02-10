#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

ll a[N];
int main(){
    ll n, _, x, m;
    scanf("%lld", &_);
    while(_--){
        map<ll, ll> mp;
        scanf("%lld%lld", &n, &m);
        ll sum = 0ll;
        for(int i = 1;i <= n;i++){
            scanf("%lld", &a[i]);
            sum += a[i];
            if(!mp[sum])
                mp[sum] = i;
        }
        while(m--){
            scanf("%lld", &x);
            if(!x){
                printf("0\n");
                continue;
            }
            if(mp[x]){
                printf("%lld\n", mp[x]);
                continue;
            }
            //printf("sum = %lld\n", sum);
            if(sum>0 && x<sum  ||  sum<0 && x>sum || sum==0){
                printf("-1\n");
                continue;
            }
            if(mp[x%sum]){
                printf("%lld\n", (x/sum)*n + mp[x%sum]);
            } else {
                printf("-1\n");
            }
        }
    }
    return 0;
}