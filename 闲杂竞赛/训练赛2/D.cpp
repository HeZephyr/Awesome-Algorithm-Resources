/**
  *@filename:D
  *@author: pursuit
  *@created: 2021-08-11 19:14
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const ll INF = 1e10;

int n;
ll b[N],minn = INF,maxx = -INF,c[N];
void solve(){
    bool flag = false;
    if(n <= 2){
        puts("0");
        return;
    }
    if(maxx - minn > 4){
        puts("-1");
    }
    else{
        ll ans = INF;
        for(int d = minn; d <= maxx; ++ d){
            for(int j = 0; j < 3; ++ j){
                for(int i = 1; i <= n; ++ i){
                    c[i] = b[i];
                }
                ll cnt = 0;
                bool flag = true;
                if(j == 1){
                    c[1] += 1;
                    cnt ++;
                }
                else if(j == 2){
                    c[1] -= 1;
                    cnt ++;
                }
                //cout << c[1] << " ";
                for(int i = 2; i <= n; ++ i){
                    if(abs(c[i] - c[i - 1] - d) > 1){
                        flag = false;
                        break;
                    }
                    else if(abs(c[i] - c[i - 1] - d) == 1){
                        cnt ++;
                        c[i] = c[i - 1] + d;
                    }
                    //cout << c[i] << " ";
                }
                //cout << endl;
                if(flag){
                    ans = min(ans,cnt);
                }
            }
        }
        if(ans == INF){
            puts("-1");
        }
        else{
            printf("%lld\n", ans);
        }
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%lld", &b[i]);
        if(i >= 2){
            minn = min(minn,b[i] - b[i - 1]);
            maxx = max(maxx,b[i] - b[i - 1]);
        }
    }	
    solve();
    return 0;
}