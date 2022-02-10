#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, a[3], m;
void solve(){
    if(max(0, a[0] - 1) + max(0, a[1] - 1) + max(0, a[2] - 1) < m){
        puts("NO");
    }
    else{
        sort(a, a + 3);
        if(a[2] - 1 - a[0] - a[1] > m){
            puts("NO");
        }
        else{
            puts("YES");
        }
    }
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> a[0] >> a[1] >> a[2] >> m;
        solve();
    }
    return 0;
}