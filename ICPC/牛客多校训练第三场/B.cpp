/**
  *@filename:B
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-24 12:02
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 5000 + 5;
const int P = 1e9+7;

int n,m;
int b,c,d,p;
int pre,cur;//代表a[i - 1]和a[i];
//将行列转换为点。其中格子(i,j) -> 边i->j
struct edge{
    int u,v;
};
vector<edge> edges[100005];//利用桶排序，由于边太多了。
int father[N << 1];
int find(int x){
    int r = x;
    while(father[r] != r){
        r = father[r];
    }
    int i = x, j;
    while(father[i] != r){
        j = father[i];
        father[i] = r;
        i = j;
    }
    return r;
}
void solve(){
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            cur = (1LL * pre * pre * b + 1LL * pre * c + d) % p;
            edges[cur].push_back({i,n + j});
            pre = cur;
        }
    }
    for(int i = 1; i <= n + m; ++ i){
        father[i] = i;
    }
    ll ans = 0,cnt = 0;
    for(int i = 0; i <= 100000; ++ i){
        for(auto &edge : edges[i]){
            int fu = find(edge.u), fv = find(edge.v);
            if(fu != fv){
                father[fu] = fv;
                ans += i;
                cnt ++;
            }
            if(cnt == n + m - 1){
                break;
            }
        }
    }
    cout << ans << endl;
}
int main(){
    cin >> n >> m >> pre >> b >> c >> d >> p;
    solve();
    return 0;
}