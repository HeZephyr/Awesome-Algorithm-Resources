/**
  *@filename:B_XOR_Specia_LIS_t
  *@author: pursuit
  *@created: 2021-10-30 22:40
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, a[N];
void solve(){
    if(n % 2 == 0){
        puts("YES");
    }
    else{
        //找一个2和一个3。
        bool flag = false;
        for(int i = 1; i < n; ++ i){
            if(a[i] >= a[i + 1]){
                flag = true;
                break;
            }
        }
        if(flag)puts("YES");
        else puts("NO");
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