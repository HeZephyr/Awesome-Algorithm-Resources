/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-09-02 10:31
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t;
ll n, k;
//f(n)代表最小除数。
int cal(int x){
    for(int i = 2; i <= x; ++ i){
        if(x % i == 0){
            return i;
        }
    }
    return x;
}
void solve(){
    //当为偶数的时候，最小因子就是2。之后就是一直加2即可。
    //当为奇数的时候，最小因子就是奇数，那么之后就变成偶数了。
    while(k -- ){
        if(n % 2){
            n += cal(n);
        }
        else{
            n += (k + 1) * 2;
            break;
        }
    }
    printf("%lld\n", n);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%lld%lld", &n, &k);
        solve();
    }
    return 0;
}