#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 3e5 + 10;

int n, w, a[N], b[N];
int pos[N];
bool cmp(int i, int j){
    return a[i] > a[j];
}
int main(){
    scanf("%d%d", &n, &w);
    for(int i = 1; i <= n; ++ i){
        //b[i]个可用的奶酪，其中每克a[i]。
        scanf("%d%d", &a[i], &b[i]);
        pos[i] = i;
    }
    sort(pos + 1, pos + 1 + n, cmp);
    ll res = 0;
    for(int i = 1; i <= n; ++ i){
        int id = pos[i];
        int minn = min(w, b[id]);
        w -= minn;
        res += 1LL * minn * a[id];
    }
    cout << res << endl;
    return 0;
}