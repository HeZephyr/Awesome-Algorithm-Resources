#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int n, k, x, y;
vector<int> p[110];
int op, z, minn, maxx;
void solve(){
    scanf("%d%d", &op, &z);
    if(op == 2){
        cin >> minn >> maxx;
        int cnt = 0;
        for(int i = 0; i < p[z].size(); ++ i){
            if(p[z][i] >= minn && p[z][i] <= maxx){
                cnt ++;
            }
        }
        cout << cnt << endl;
    }
    else{
        while(z -- ){
            cin >> x >> y;
            p[x].pb(y);
        }
    }
}
int main(){	
    cin >> n >> k;
    while(n -- ){
        solve();
    }
    return 0;
}