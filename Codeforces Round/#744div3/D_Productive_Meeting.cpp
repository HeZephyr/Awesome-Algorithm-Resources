/**
  *@filename:D_Productive_Meeting
  *@author: pursuit
  *@created: 2021-09-28 22:55
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, a[N];
struct node{
    int i;
    bool operator < (const node &A) const{
        return a[i] < a[A.i];
    }
};
void solve(){
    multiset<node> s;
    vector<pii> res;
    for(int i = 1; i <= n; ++ i)s.insert({i});
    while(s.size() > 1){
        auto iter1 = s.begin(), iter2 = s.end();
        -- iter2;
        int x = (*iter1).i, y = (*iter2).i;
        if(a[x] == 0){
            s.erase(iter1);
            continue;
        }
        if(a[y] == 0){
            s.erase(iter2);
            continue;
        }
        -- a[x], -- a[y];
        s.erase(iter1), s.erase(iter2);
        s.insert({x}), s.insert({y});
        res.push_back({x, y});
    }
    cout << res.size() << endl;
    for(auto iter : res){
        cout << iter.first << " " << iter.second << endl;
    }
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        solve();
    }
    return 0;
}