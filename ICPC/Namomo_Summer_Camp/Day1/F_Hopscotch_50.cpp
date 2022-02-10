/**
  *@filename:F_Hopscotch_50
  *@author: pursuit
  *@created: 2021-08-20 13:26
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 50 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,k,w;
struct node{
    int x,y;
    ll minn;
};
vector<node> a[N * N];
void solve(){
    for(int i = 1; i < k; ++ i){
        //从i跳到i + 1。
        for(auto &iter1 : a[i]){
            for(auto &iter2 : a[i + 1]){
                iter2.minn = min(iter2.minn, iter1.minn + abs(iter2.x - iter1.x) + abs(iter2.y - iter1.y));
            }
        }
    }
    ll minn = INF;
    for(auto &iter : a[k]){
        minn = min(iter.minn,minn);
    }
    if(minn >= INF)minn = -1;
    printf("%lld\n", minn);
}
int main(){	
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= n; ++ j){
            scanf("%d", &w);
            if(w == 1)a[w].push_back({i,j,0});
            else a[w].push_back({i,j,INF});
        }
    }
    solve();
    return 0;
}