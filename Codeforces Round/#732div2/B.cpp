/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-08-12 09:42
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n,m;
ll cnt[N][26];
char s[N];
void solve(){
    //由于输出的字符串少了。
    for(int i = 0; i < m; ++ i){
        bool flag = false;
        for(int j = 0; j < 26; ++ j){
            if(cnt[i][j]){
                if(!flag)printf("%c", 'a' + j);
                flag = true;
                cnt[i][j] = 0;
            }
        }
    }
    puts("");
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++ i){
            scanf("%s", s);
            for(int j = 0; j < m; ++ j){
                cnt[j][s[j] - 'a'] ++;//原来该位置出现的字符串。
            }
            //printf("%s\n", s);
        }
        for(int i = 1; i < n; ++ i){
            scanf("%s", s);
            for(int j = 0; j < m; ++ j){
                cnt[j][s[j] - 'a'] --;//现在该位置出现的字符串。
            }
        }
        solve();
    }
    return 0;
}