#include<bits/stdc++.h>
#define ll long long
using namespace std;
using pii = pair<int, int>;
const int N = 1e6 + 10;

int t, n;
vector<int> a[N];
pii tag[N];
int b[N];//存储是什么类型的。
int temp[N], cnt;
int ans[N];
int q[N], st, ed;
void bfs(int n){
    st = -1, ed = 0;
    q[++ st] = n;
    while(st >= ed){
        int x = q[st --];
        if(b[x] == 1){
            ++ ans[x];
        }
        else if(b[x] == 2){
            q[++ st] = tag[x].first;
            q[++ st] = tag[x].second;
        }
    }
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        cnt = 0;
        unordered_map<int, ll> c;
        for(int i = 1, op; i <= n; ++ i){
            ans[i] = 0;
            scanf("%d", &op);
            b[i] = op;
            if(op == 1){
                int len;
                scanf("%d", &len);
                a[i].resize(len);
                for(int j = 0, x; j < len; ++ j){
                    scanf("%d", &a[i][j]);
                    temp[++ cnt] = a[i][j];
                }
            }
            else{
                scanf("%d%d", &tag[i].first, &tag[i].second);
            }
        }
        bfs(n);
        ll sum = 0ll, Max = -1;
        for(int i = 1; i <= n; ++ i){
            if(b[i] == 1 && ans[i]){
                //printf("ans[%d] = %d\n", i, ans[i]);
                int len = a[i].size();
                for(int j = 0;j < len;j++){
                    c[a[i][j]] += ans[i];
                    sum += ans[i];
                    Max = max(Max, c[a[i][j]]);
                }
            }
        }
        //printf("Max = %lld, sum = %lld\n", Max, sum);
        if(Max*2ll<=sum) printf("%lld\n", sum);
        else printf("%lld\n", (sum-Max)*2ll);
    }
    return 0;
}