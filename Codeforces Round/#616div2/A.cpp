/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-08-22 15:26
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 3e3 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n;
char s[N];
void solve(){
    for(int i = n; i >= 1; -- i){
        if((s[i] - '0') % 2 == 0){
            -- n;
        }
        else{
            break;
        }
    }
    if(n < 1){
        puts("-1");
    }
    else{
        int sum = 0;
        for(int i = 1; i <= n; ++ i){
            sum += (s[i] - '0');
        }
        int idx = -1;
        if(sum % 2){
            //删除一个奇数。
            for(int i = 1; i < n; ++ i){
                if((s[i] - '0') % 2){
                    idx = i;
                    break;
                }
            }
            if(idx == -1){
                puts("-1");
                return;
            }
        }
        int i = 1;
        //cout << idx << endl;
        if(idx == 1){
            i = 2;
            while(s[i] == '0')i ++;
            if(i > n){
                puts("-1");
                return;
            }
        }
        for(; i <= n; ++ i){
            if(i == idx)continue;
            printf("%c", s[i]);
        }
        puts("");
    }
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        scanf("%s", s + 1);
        solve();
    }
    return 0;
}