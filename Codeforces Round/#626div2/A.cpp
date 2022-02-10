/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-08-15 13:14
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 100 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n,a[N];
void solve(){
    if(n == 1 && a[1] % 2){
        puts("-1");
    }
    else{
        int l = -1;
        for(int i = 1; i <= n; ++ i){
            if(a[i] % 2){
                if(l == -1)l = i;
                else{
                    printf("2\n%d %d\n", l, i);
                    break;
                }
            }
            else{
                printf("1\n%d\n", i);
                break;
            }
        }
    }
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        solve();
    }
    return 0;
}