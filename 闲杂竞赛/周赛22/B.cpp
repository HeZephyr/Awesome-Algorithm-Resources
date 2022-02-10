/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-10-29 19:55
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, k, a[N], pos[N], res[N];
vector<int> g[N];
bool cmp(int i, int j){
    return a[i] < a[j];
}
int check(int idx, int x){
    int l = 0, r = g[idx].size();
    int ans = INF;
    while(l < r){
        int mid = (l + r) >> 1;
        if(a[g[idx][mid]] < x){
            l = mid + 1;
        }
        else if(a[g[idx][mid]] == x){
            ans = mid;
            r = mid - 1;
        }
        else{
            r = mid;
        }
    }
    if(a[g[idx][l]] == x && l < ans)ans = l;
    return ans;
}
void solve(){
    for(int i = 1; i <= n; ++ i){
        g[i].push_back(i);
        sort(g[i].begin(), g[i].end(), cmp);
    }
    sort(pos + 1, pos + 1 + n, cmp);
    int last = 0;
    for(int i = 1; i <= n; ++ i){
        int idx = pos[i];
        //有idx - 1的符合。
        int y;
        if(a[idx] == a[pos[i - 1]])y = last;
        else{
            y = i - 1;
            last = y;
        }
        int x = check(idx, a[idx]);
        //cout << last << " " << x << endl;
        res[idx] = last - x;
    }
    for(int i = 1; i <= n; ++ i){
        printf("%d ", res[i]);
    }
    puts("");
}
int main(){	
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        pos[i] = i;
    }
    for(int i = 1, x, y; i <= k; ++ i){
        scanf("%d%d", &x, &y);
        g[x].push_back(y), g[y].push_back(x);
    }
    solve();
    return 0;
}