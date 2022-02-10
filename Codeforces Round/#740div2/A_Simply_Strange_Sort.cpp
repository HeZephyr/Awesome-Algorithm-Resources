/**
  *@filename:A_Simply_Strange_Sort
  *@author: pursuit
  *@created: 2021-08-24 22:36
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e3 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n,a[N];
bool check(){
    for(int i = 1; i <= n; ++ i){
        if(a[i] != i){
            return false;
        }
    }
    return true;
}
void solve(){
    int i = 1;
    if(check()){
        puts("0");
        return;
    }
    while(true){
        if(check()){
            printf("%d\n", i - 1);
            break;
        }
        if(i & 1){
            for(int j = 1; j <= n - 2; j += 2){
                if(a[j] > a[j + 1]){
                    swap(a[j], a[j + 1]);
                }
            }
        }
        else{
            for(int j = 2; j <= n - 1; j += 2){
                if(a[j] > a[j + 1]){
                    swap(a[j], a[j + 1]);
                }
            }
        }
        ++ i;
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