/**
  *@filename:B_Shifting_Sort
  *@author: pursuit
  *@created: 2021-09-28 22:39
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 50 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, a[N], b[N];
struct node{
    int l, r, d;
};
void solve(){
    //每一次可以确定最大值。将最大值移动到相应位置即可。
    vector<node> res;
    int k = n;
    sort(b + 1, b + 1 + n);
    while(k){
        int idx = 0;
        for(int i = 1; i <= k; ++ i){
            if(a[i] == b[k]){
                idx = i;
                break;
            }
        }
        //i应该要到k。
        if(idx == k){
            -- k;
            continue;
        }
        else res.push_back({idx, k, 1});
        //修改ai。
        for(int i = idx; i < k; ++ i)a[i] = a[i + 1];
        a[k] = b[k];
        -- k;
    }
    cout << res.size() << endl;
    for(int i = 0; i < res.size(); ++ i){
        cout << res[i].l << " " << res[i].r << " " << res[i].d << endl;
    }
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n;
        for(int i = 1; i <= n; ++ i){
            cin >> a[i];
            b[i] = a[i];
        }
        solve();
    }
    return 0;
}