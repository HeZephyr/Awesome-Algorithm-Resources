/**
  *@filename:B_Chess_Tournament
  *@author: pursuit
  *@created: 2021-09-08 22:40
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 60 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n;
char s[N];
char g[N][N];
void solve(){
    vector<int> ans;
    memset(g, '0', sizeof(g));
    for(int i = 1; i <= n; ++ i){
        if(s[i] == '2'){
            ans.push_back(i);
        }
    }
    int len = ans.size();
    if(len >= 1 && len <= 2){
        puts("NO");
    }
    else{
        puts("YES");
        for(int i = 0; i < len - 1; ++ i){
            g[ans[i]][ans[i + 1]] = '+';
            g[ans[i + 1]][ans[i]] = '-';
        }
        if(len != 0){
            g[ans[len - 1]][ans[0]] = '+';
            g[ans[0]][ans[len - 1]] = '-';
        }
        for(int i = 1; i <= n; ++ i){
            for(int j = 1; j <= n; ++ j){
                if(i == j){
                    printf("X");
                }
                else if(g[i][j] == '+' || g[i][j] == '-'){
                    printf("%c", g[i][j]);
                }
                else{
                    printf("=");
                }
            }
            puts("");
        }
    }
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n >> s + 1;
        solve();
    }
    return 0;
}