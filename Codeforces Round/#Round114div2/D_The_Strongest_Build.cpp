#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, a[11][N], len[11];
map<vector<int>, int> p, flag;
priority_queue<pair<int, vector<int>>> q;
int m;
void solve(){
    int sum = 0;
    vector<int> temp;
    for(int i = 1; i <= n; ++ i){
        sum += a[i][len[i]];
        temp.push_back(len[i]);
    }
    q.push({sum, temp});
    vector<int> head;
    int val;
    while(!q.empty()){
        head = q.top().second, val = q.top().first;
        q.pop();
        if(!p.count(head)){
            for(auto x : head){
                printf("%d ", x);
            }
            puts("");
            break;
        }
        for(int i = 1; i <= n; ++ i){
            if(head[i - 1] > 1){
                //说明可以减。
                -- head[i - 1];
                if(!flag[head]){
                    q.push({val + a[i][head[i - 1]] - a[i][head[i - 1] + 1], head});
                    flag[head] = 1;
                }
                ++ head[i - 1];
            }
        }
    }
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &len[i]);
        for(int j = 1; j <= len[i]; ++ j){
            scanf("%d", &a[i][j]);
        }
    }
    scanf("%d", &m);
    for(int i = 1; i <= m; ++ i){
        vector<int> temp;
        for(int j = 1, x; j <= n; ++ j){
            scanf("%d", &x);
            temp.push_back(x);
        }
        p[temp] = 1;
    }
    solve();
    return 0;
}