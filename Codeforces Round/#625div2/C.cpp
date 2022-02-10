/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-09-03 10:12
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 100 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n;
char s[N];
void solve(){
    //枚举选择的起始字符。
    int res = 0;
    for(char c = 'z'; c >= 'b'; -- c){
        for(int i = 1; i <= n; ++ i){
            if(s[i] == c && (i - 1) >= 1 && s[i - 1] == s[i] - 1){
                for(int j = i; j < n; ++ j){
                    s[j] = s[j + 1];
                }
                -- n, i -= 2;
                ++ res;
            }
            if(s[i] == c && (i + 1) <= n && s[i + 1] == s[i] - 1){
                for(int j = i; j < n; ++ j){
                    s[j] = s[j + 1];
                }
                -- n, i -= 2;
                ++ res;
            }

        }
    }
    printf("%d\n", res);
}
int main(){
    scanf("%d%s", &n, s + 1);
    solve();
    return 0;
}
