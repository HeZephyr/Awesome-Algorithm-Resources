#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 1e17;
const int N = 1e5 + 10;
int t;
int n, m, a[N];
int main(){
    scanf("%d", &t);
    while(t -- ){
        vector<int> v;
        scanf("%d%d", &n, &m);
        ll sum = 0;
        int cnt = 0;
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
            if(!a[i])++ cnt;
            else v.push_back(a[i]);
        }
        if(n == m){
            puts("Richman");
            continue;
        }
        if(cnt > m){
            puts("Impossible");
        } else {
            int ans = cnt;
            int minn = 1e9;
            for(int i = 0;i < n-cnt;i++){
                if(ans < m){
                    sum += v[i];
                    ++ ans;
                }
                else{
                    minn = min(minn, v[i]);
                }
            }
            printf("%lld\n", sum + minn - 1);
        }
    }
    return 0;
}