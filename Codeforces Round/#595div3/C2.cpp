/**
  *@filename:C2
  *@author: pursuit
  *@created: 2021-08-27 11:15
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,bit[40];//3进制位。
ll n,ans;
void solve(){
    memset(bit,0,sizeof(bit));
    int cnt = 0;
    while(n){
        bit[cnt ++] = n % 3;
        n /= 3;
    }
    for(int i = cnt; i >= 0; -- i){
        if(bit[i] == 2){
            //当遇到2，后面的位都变为0，前面选择一个非1位变0，为了最小，后面的都变为0.
            for(int j = i; j >= 0; -- j){
                bit[j] = 0;
            }
            for(int j = i + 1; j <= cnt; ++ j){
                if(bit[j] == 1){
                    bit[j] = 0;
                }
                else if(bit[j] == 0){
                    bit[j] = 1;
                    break;
                }
            }
            break;
        }
    }
    ll ans = 0,temp = 1;
    for(int i = 0; i <= cnt; ++ i){
        if(bit[i])ans += temp;
        temp *= 3;
    }
    cout << ans << endl;
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n;
        solve();
    }
    return 0;
}