#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, k, x, y;
map<int, vector<int> > p;
void solve(){
}
int main(){	
    cin >> n >> k;
    int op, z, ymin, ymax;
    for(int i = 1; i <= n; ++ i){
        cin >> op >> z;
        if(op == 2){
            cin >> ymin >> ymax;
            int cnt = 0;
            for(auto v : p[z]){
                if(v >= ymin && v <= ymax){
                    ++ cnt;
                }
            }
            printf("%d\n", cnt);
        }
        else{
            while(z -- ){
                cin >> x >> y;
                p[x].push_back(y);
            }
        }
    }
    solve();
    return 0;
}