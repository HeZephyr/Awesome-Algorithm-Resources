/**
  *@filename:C_Grandma_Capa_Knits_a_Scarf
  *@author: pursuit
  *@created: 2021-10-24 18:34
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
char s[N];
int check(char c){
    int l = 0, r = n - 1;
    int cnt = 0;
    while(l <= r){
        //cout << s[l] << " " << s[r] << endl;
        if(s[l] != s[r]){
            if(s[l] == c){
                ++ l, ++ cnt;
            }
            else if(s[r] == c){
                -- r, ++ cnt;
            }
            else{
                return -1;
            }
        }
        else{
            ++ l, -- r;
        }
    }
    return cnt;
}
void solve(){
    int res = 1e9;
    for(char c = 'a'; c <= 'z'; ++ c){
        int x = check(c);
        if(x != -1){
            res = min(res, x);
        }
    }
    if(res == 1e9){
        puts("-1");
    }
    else{
        printf("%d\n", res);
    }
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        //memset(cnt, 0, sizeof(cnt));
        scanf("%d", &n);
        scanf("%s", s);
        /* for(int i = 0; i < n; ++ i){
            cnt[s[i] - 'a'] ++;
        } */
        solve();
    }
    return 0;
}