/**
  *@filename:D1
  *@author: pursuit
  *@created: 2021-09-10 16:41
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//糖果i现在在站ai，需要送到站bi。找到运送所有糖果的最短时间。
int n, m;//站数和糖果数量。
//火车一次占用一个车站。一次只能带走一种类型的物品。

vector<int> st[N];
int res;
void solve(){
    for(int i = 1; i <= n; ++ i){
        sort(st[i].begin(), st[i].end());
    }
    for(int i = 1; i <= n; ++ i){
        int res = 0, cost = 0;
        for(int j = 1; j <= n; ++ j){
            //起始站在i站。
            if(st[j].size() == 0)continue;
            if(i <= j){
                cost = j - i;
            }
            else{
                cost = n - (i - j);
            }
            int k = st[j].size() - 1;
            cost += k * n + st[j][0];
            res = max(res, cost);
        }
        cout << res << " ";
    }
    cout << endl;
}
int main(){	
    cin >> n >> m;
    for(int i = 1, u, w; i <= m; ++ i){
        cin >> u >> w;
        if(u <= w){
            w -= u;
        }
        else{
            w = n - (u - w);
        }
        st[u].push_back(w);
    }
    solve();
    return 0;
}