#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, a[N];
void solve(){   
    if(a[1] != n && a[n] != n){
        puts("-1");
        return;
    }
    else{
        if(n > 2){
            //将最大值卡着左边数据和右边数据。
            if(a[1] == n){
                swap(a[1], a[2]);
                reverse(a + 3, a + n + 1);
            }
            else{
                swap(a[n], a[n - 1]);
                reverse(a + 1, a + n - 1);
            }
        }
        for(int i = 1; i <= n; ++ i){
            printf("%d%c", a[i], i == n ? '\n' : ' ');
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