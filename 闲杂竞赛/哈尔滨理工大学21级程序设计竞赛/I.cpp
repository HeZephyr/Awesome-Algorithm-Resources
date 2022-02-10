#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, a, b;
void solve(){
}
int main(){	
    cin >> n;
    int cnt = 0;
    int prea = 0, preb = 0;
    for(int i = 1; i <= n; ++ i){
        cin >> a >> b;
        cnt += max(0, min(a, b) - max(prea, preb) + 1);
        prea = a, preb = b;
        //避免重复计算。
        if(a == b){
            ++ prea;
        }
    }
    cout << cnt << endl;
    solve();
    return 0;
}