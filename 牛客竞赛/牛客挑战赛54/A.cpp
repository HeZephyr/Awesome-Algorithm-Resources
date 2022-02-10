#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 6e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n;
string s;
int cnt[2];
void solve(){
    int cnt0 = 0, cnt1 = 0;
    for(int i = 0; i < n; ++ i){
        if(s[i] == '0')++ cnt0;
        else ++ cnt1;
    }
    s += s;
    int l = 0, r = l - 1;
    int res = 0;
    while(l < n){
        while((r - l + 1) * 2 < n){
            if(r == 2 * n - 1)break;
            ++ cnt[s[r + 1] - '0'];
            ++ r;
        }
        if((r - l + 1) * 2 == n && cnt[0] * 2 == cnt0 && cnt[1] * 2 == cnt1)++ res;
        -- cnt[s[l ++] - '0'];
    }
    printf("%d\n", res);
}
int main(){	
    cin >> n >> s;
    solve();
    return 0;
}