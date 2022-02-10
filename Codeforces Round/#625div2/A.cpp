/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-09-03 09:47
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, r[N], b[N];
void solve(){
    //bi存在ri不存在的都设1.
    int cnt1 = 0, cnt2 = 0;
    for(int i = 1; i <= n; ++ i){
        if(b[i] > r[i]){
            ++ cnt1;
        }
        else if(r[i] > b[i]){
            ++ cnt2;
        }
    }
    if(cnt2 == 0){
        puts("-1");
    }
    else{
        int temp = cnt1 / cnt2 + 1;
        printf("%d\n", temp);
    }
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &r[i]);
    }
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &b[i]);
    }
    solve();
    return 0;
}