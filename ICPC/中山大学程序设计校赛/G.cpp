#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, a[N], b[N], c[N];
int res[N][2], tot;
void add(int i, int j){
    res[++ tot][0] = i;
    res[tot][1] = j;
}
void solve(){
    sort(b + 1, b + 1 + n);
    int len = unique(b + 1, b + 1 + n) - (b + 1);
    for(int i = 1; i <= n; ++ i){
        a[i] = lower_bound(b + 1, b + 1 + len, a[i]) - b;
        //cout << a[i] << " ";
    }
    //cout << endl;
    for(int i = 0; i < 10; ++ i){
        int cnta = 0, cntb = 0, cntc = 0;
        //an是栈顶。
        for(int j = n; j >= 1; -- j){
            if((a[j] >> i) & 1){
                //说明该位上有1。
                b[++ cntb] = a[j];
                add(1, 2);
            }
            else{
                c[++ cntc] = a[j];
                add(1, 3);
            }
        }
        //从大到小放入。
        while(cntb){
            a[++ cnta] = b[cntb -- ];
            add(2, 1);
        }
        while(cntc){
            a[++ cnta] = c[cntc -- ];
            add(3, 1);
        }
    }
    printf("%d\n", tot);
    for(int i = 1; i <= tot; ++ i){
        printf("%d %d\n", res[i][0], res[i][1]);
    }
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &b[i]);
        a[i] = b[i];
    }
    solve();
    return 0;
}