/**
  *@filename:C_Rings
  *@author: pursuit
  *@created: 2021-08-26 23:25
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e4 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

/*
0代表金，1代表银
*/
int t,n;
char s[N];
void solve(){
    for(int i = 1; i <= n; ++ i){
        if(s[i] == '0' && n - i >= n / 2){
            printf("%d %d %d %d\n", i, n, i + 1, n);
            return;
        }
        else if(s[i] == '0' && i - 1 >= n / 2){
            printf("%d %d %d %d\n", 1, i, 1, i - 1);
            return;
        }
    }
    //说明不存在0.
    printf("%d %d %d %d\n", 1, n / 2, 2, n / 2 + 1);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%s", &n, s + 1);
        solve();
    }
    return 0;
}