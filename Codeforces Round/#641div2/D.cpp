/**
  *@filename:D
  *@author: pursuit
  *@created: 2021-09-02 13:06
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, k, a[N];
/* 
中位数为(s + 1) / 2 ，判断是否可以将所有数变成k。
*/
bool flag;
void solve(){
    if(!flag){
        puts("no");
    }
    else{
        if(n == 1){
            puts("yes");
            return;
        }
        //若有两个相邻的数均为1即可。
        for(int i = 1; i <= n; ++ i){
            for(int j = i + 1; j <= n && j - i <= 2; ++ j){
                if(a[i] && a[j]){
                    puts("yes");
                    return;
                }
            }
        }
        puts("no");
    }
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &k);
        flag = false;
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
            if(a[i] == k)a[i] = 1, flag = true;
            else if(a[i] > k)a[i] = 2;
            else a[i] = 0;
        }
        solve();
    }
    return 0;
}