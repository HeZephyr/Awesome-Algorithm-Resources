/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-08-11 15:46
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n,k;
char s[N];
int cnt[26];
void solve(){
    int ans = 0;
    for(int l = 0,r = k - 1; l <= r; l ++ , r --){
        //cout << l << " " << r << endl;
        for(int i = l, j = r; i < n; i += k, j += k){
            cnt[s[i] - 'a'] ++;
            cnt[s[j] - 'a'] ++;
        }
        int maxx = 0;
        for(int i = 0; i < 26; ++ i){
            maxx = max(cnt[i],maxx);
            cnt[i] = 0;
        }
        if(l == r){
            ans += n / k - maxx / 2;
        }
        else{
            ans += n / k * 2 - maxx;
        }
    }
    printf("%d\n", ans);
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &k);
        scanf("%s", s);
        solve();
    }	
    return 0;
}