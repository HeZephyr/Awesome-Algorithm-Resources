#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, a[N], b[N], pos[N];
bool cmp(int i, int j){
    return a[i] < a[j];
}
void solve(){
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n;
        for(int i = 1; i <= n; ++ i){
            cin >> a[i];
            pos[i] = i;
        }
        bool flag = false;
        for(int i = 1; i <= n; ++ i){
            cin >> b[i];
        }
        bool flag1 = false;
        bool flag2 = false;
        sort(pos + 1, pos + n + 1, cmp);
        sort(b + 1, b + 1 + n);
        vector<int> temp;
        for(int i = 1; i <= n; ++ i){
            //cout << a[pos[i]] << " ";
            if(a[pos[i]] != b[i])flag1 = true;
            if(b[i] - a[pos[i]] != 1 && b[i] - a[pos[i]] != 0){
                flag2 = true;
            }
        }
        //cout << endl;
        if(!flag1 || !flag2){
            puts("YES");
        }
        else{
            puts("NO");
        }
        solve();
    }
    return 0;
}