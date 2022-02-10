/**
  *@filename:C_Make_Them_Equal
  *@author: pursuit
  *@created: 2021-10-08 23:28
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 3e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n;
char s[N], op[3], c;
void solve(){
    bool flag = true;
    for(int i = 1; i <= n; ++ i){
        if(s[i] != c){
            flag = false;
            break;
        }
    }
    if(flag){
        puts("0");
        return;
    }
    for(int i = n; i >= 2; -- i){
        if(s[i] == c){
            flag = true;
            for(int j = i * 2; j <= n; j += i){
                if(s[j] != c){
                    flag = false;
                    break;
                }
            }
            if(flag){
                puts("1");
                printf("%d\n", i);
                return;
            }
        }
    }
    puts("2");
    printf("%d %d\n", n - 1, n);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%s", &n, op);
        scanf("%s", s + 1);
        c = op[0];
        solve();
    }
    return 0;
}