#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, a[N], b[N], n;
bool check(int x){
    int cnt = 0, cur = 0;//表示前面有多少人数。
    for(int i = 1; i <= n; ++ i){
        if(x - cur - 1 <= a[i] && cur <= b[i]){
            ++ cur;
        }
        else{
            continue;
        }
    }
    //cout << x << " " << cur << endl;
    return cur >= x;
}
void solve(){
    int l = 1, r = n + 1;
    while(l < r){
        int mid = l + r >> 1;
        //printf("l:%d r:%d\n", l, r);
        if(!check(mid)){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    if(!check(l))-- l;
    cout << l << endl;

}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d%d", &a[i], &b[i]);
        }
        solve();
    }
    return 0;
}