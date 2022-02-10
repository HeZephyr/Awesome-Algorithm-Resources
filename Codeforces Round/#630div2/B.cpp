/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-08-11 14:49
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e3 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n,a[N],c[] = {2,3,5,7,11,13,17,19,23,29,31};
map<int,int> p;
void solve(){
    int cnt = 0;
    for(int i = 1; i <= n; ++ i){
        for(int j = 0; j < 11; ++ j){
            if(a[i] % c[j] == 0){
                if(!p[c[j]]){
                    p[c[j]] = ++ cnt;
                }
                a[i] = p[c[j]];
                break;
            }
        }
    }
    printf("%d\n", cnt);
    for(int i = 1; i <= n; ++ i){
        printf("%d ", a[i]);
    }
    puts("");
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        p.clear();
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        solve();
    }
    return 0;
}