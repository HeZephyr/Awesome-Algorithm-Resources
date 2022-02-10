/**
  *@filename:B_Groups
  *@author: pursuit
  *@created: 2021-10-10 17:11
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n;
int a[N][6];
int cnt[6];
void solve(){
    bool flag = false;
    for(int j = 1; j <= 5; ++ j){
        //说明可行，在于配对问题。
        if(cnt[j] >= n / 2){
            for(int k = j + 1; k <= 5; ++ k){
                if(cnt[k] < n / 2)continue;
                int ans1 = 0, ans2 = 0, ans3 = 0;
                //ans1只能用于k。ans2能用于两者, ans2只能用于j。
                for(int i = 1; i <= n; ++ i){
                    if(!a[i][j] && a[i][k])++ ans1;
                    if(a[i][j] && a[i][k])++ ans2;
                    if(!a[i][k] && a[i][j])++ ans3;
                }
                //cout << j << " " << k << " " << ans << endl;
                if(ans1 + ans2 + ans3 == n){
                    flag = true;
                    break;
                }
            }
            if(flag)break;
        }
    }
    if(flag){
        puts("YES");
    }
    else{
        puts("NO");
    }
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        memset(cnt, 0, sizeof(cnt));
        for(int i = 1; i <= n; ++ i){
            for(int j = 1; j <= 5; ++ j){
                scanf("%d", &a[i][j]);
                if(a[i][j]){
                    ++ cnt[j];
                }
            }
        }
        solve();
    }
    return 0;
}