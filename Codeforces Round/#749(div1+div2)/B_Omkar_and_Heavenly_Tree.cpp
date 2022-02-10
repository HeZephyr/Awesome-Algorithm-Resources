/**
  *@filename:B_Omkar_and_Heavenly_Tree
  *@author: pursuit
  *@created: 2021-10-17 19:17
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, m;
int vis[N];
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n >> m;
        memset(vis, 0, sizeof(vis));
        for(int i = 0, a, b, c; i < m; ++ i){
            cin >> a >> b >> c;
            vis[b] = true;
        }
        int root;
        for(int i = 1; i <= n; ++ i){
            if(!vis[i]){
                root = i;
                break;
            }
        }
        for(int i = 1; i <= n; ++ i){
            if(i == root)continue;
            cout << i << " " << root << endl;
        }
    }
    return 0;
}