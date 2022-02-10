/**
  *@filename:AAA
  *@author: pursuit
  *@created: 2021-11-03 21:18
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, m, len1, len2;
ll a[N], b[N];
struct node{
    ll sum, cnt;
    bool operator < (const node &A){
        return 1.0 * sum / cnt < 1.0 * A.sum / A.cnt;
    }
    node operator + (const node A){
        return {sum + A.sum, cnt + A.cnt};
    }
}A[N], B[N];
void solve(){
    len1 = len2 = 0;
    //如果平均值大，那就合并。
    for(int i = 1; i <= n; ++ i){
        A[++ len1] = {a[i], 1};
        while(len1 > 1 && A[len1 - 1] < A[len1]){
            A[len1 - 1] = A[len1 - 1] + A[len1];
            -- len1;
        }
    }
    for(int i = 1; i <= m; ++ i){
        B[++ len2] = {b[i], 1};
        while(len2 > 1 && B[len2 - 1] < B[len2]){
            B[len2 - 1] = B[len2 - 1] + B[len2];
            -- len2;
        }
    }
    int idx1 = 1, idx2 = 1, idxa = 1, idxb = 1;
    vector<ll> ans;
    while(idx1 <= len1 || idx2 <= len2){
        if(idx1 > len1){
            for(int i = idxb; i <= idxb + B[idx2].cnt - 1; ++ i){
                ans.push_back(b[i]);
            }
            idxb += B[idx2].cnt;
            ++ idx2;
        }
        else if(idx2 > len2){
            for(int i = idxa; i <= idxa + A[idx1].cnt - 1; ++ i){
                ans.push_back(a[i]);
            }
            idxa += A[idx1].cnt;
            ++ idx1;
        }
        else if(A[idx1] < B[idx2]){
            for(int i = idxb; i <= idxb + B[idx2].cnt - 1; ++ i){
                ans.push_back(b[i]);
            }
            idxb += B[idx2].cnt;
            ++ idx2;
        }
        else{
            for(int i = idxa; i <= idxa + A[idx1].cnt - 1; ++ i){
                ans.push_back(a[i]);
            }
            idxa += A[idx1].cnt;
            ++ idx1;
        }
    }
    ll res = 0;
    for(int i = 0; i < n + m; ++ i){
        res += 1LL * (i + 1) * ans[i];
    }
    printf("%lld\n", res);
}
int main(){	
    scanf("%d", &t);
    for(int k = 1; k <= t; ++ k){
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++ i){
            scanf("%lld", &a[i]);
        }
        for(int i = 1; i <= m; ++ i){
            scanf("%lld", &b[i]);
        }
        printf("Case %d: ", k);
        solve();
    }
    return 0;
}