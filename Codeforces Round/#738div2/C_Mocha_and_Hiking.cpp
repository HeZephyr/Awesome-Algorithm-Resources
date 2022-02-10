/**
  *@filename:C_Mocha_and_Hiking
  *@author: pursuit
  *@created: 2021-08-15 23:25
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n,a[N];
void solve(){
    if(a[n] == 0){
        for(int i = 1; i <= n + 1; ++ i){
            printf("%d ", i);
        }
        puts("");
    }
    else if(a[1] == 1){
        printf("%d ", n + 1);
        for(int i = 1; i <= n; ++ i){
            printf("%d ", i);
        }
        puts("");
    }
    else{
        int idx = -1;
        for(int i = 1; i < n; ++ i){
            if(a[i] == 0 && a[i + 1] == 1){
                idx = i;
                break;
            }
        }
        if(idx == -1){
            puts("-1");
        }
        else{
            for(int i = 1; i <= n; ++ i){
                printf("%d ", i);
                if(idx == i){
                    printf("%d ", n + 1);
                }
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