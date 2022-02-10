/**
  *@filename:D
  *@author: pursuit
  *@created: 2021-08-09 12:21
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,b[N],c[N];
//给定序列b和c，现在需要你找到有多少数组a使得$b_i=a_{i-1}\or a_i,c_i=a_{i-1}+a_i$。
//就是给出了相邻两位的或和且的结果。而$c_i=a_{i-1}+a_i=a_{i-1}|a_i + a_{i-1} & a_i$,则$a_{i-1} & a_i=c_i-b_i$
//则可得bi和di限定了a的位。
void solve(){   
    ll res = 1;
    for(int i = 0; i <= 31; ++ i){
        int bit0 = 1, bit1 = 1;//初始默认0，1都可以取。
        for(int j = 2; j <= n; ++ j){
            int nowbit0 = 0, nowbit1 = 0;
            int u = b[j] >> i & 1, v = c[j] >> i & 1;
            if(!u && !v){
                //说明都为0，那么该位不能取1，取0需要根据前面是否可以取0。
                nowbit0 = bit0, nowbit1 = 0;
            }
            else if(u && !v){
                nowbit1 = bit0, nowbit0 = bit1;
            }
            else if(u && v){
                nowbit1 = bit1, nowbit0 = 0;
            }
            //更新当前的数位状态。
            bit1 = nowbit1, bit0 = nowbit0;
        }
        res *= (bit1 + bit0);
    }
    printf("%lld\n", res);
}
int main(){	
    scanf("%d", &n);
    for(int i = 2; i <= n; ++ i){
        scanf("%d", &b[i]);
    }
    for(int i = 2; i <= n; ++ i){
        scanf("%d", &c[i]);
        c[i] -= b[i];
    }
    solve();
    return 0;
}