/**
  *@filename:D
  *@author: pursuit
  *@created: 2021-09-22 16:29
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
int l, r, w;
ll res;
vector<int> a[N], b[N];
int main(){	
    scanf("%d", &t);
    for(int k = 1; k <= t; ++ k){
        scanf("%d%d", &n, &m);
        res = 0;
        for(int i = 1; i <= m; ++ i){
            scanf("%d%d%d", &l, &r, &w);
            a[l + 1].push_back(w), b[r + 1].push_back(w);
            res += 1LL * (r - l + 1) * (r - l) / 2 * w;
        }
        priority_queue<int, vector<int>, greater<int> > q1, q2;
        int cnt = 0;
        for(int i = 2; i <= n; ++ i){
            for(int j = 0; j < a[i].size(); ++ j)q1.push(a[i][j]);
            for(int j = 0; j < b[i].size(); ++ j)q2.push(b[i][j]);
            while(q1.size() > 0 && q2.size() > 0 && q1.top() == q2.top()){
                q1.pop(), q2.pop();
            }
            if(q1.size() > 0)++ cnt, res -= q1.top();
        }
        printf("Case #%d: ", k);
        if(cnt != n - 1){
            puts("Gotta prepare a lesson");
        }
        else{
            printf("%lld\n", res);
        }
        for(int i = 0; i < N; ++ i){
            a[i].clear(), b[i].clear();
        }
    }
    return 0;
}