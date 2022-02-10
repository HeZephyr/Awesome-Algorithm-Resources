#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 10;

int main(){
    int n,t;
    scanf("%d %d", &n, &t);
    if(t == 0){
        for(int i = 1; i <= n; ++i){
            int a,b;
            scanf("%d %d", &a, &b);
        }
        printf("0");
    }
    else if(t == 1){
        ll ans = 0;
        for(int i = 1; i <= n; ++i){
            int a,b;
            scanf("%d %d", &a, &b);
            ans += 1LL * a * b;
        }
        printf("%lld",ans);
    }
    else if(t == 2){
        ll ans = 0;
        ll sum = 0;
        for(int i = 1; i <= n; ++i){
            int a,b;
            scanf("%d %d", &a, &b);
            ans -= 1LL * a * b * b;
            sum += 1LL * a * b;
        }
        if(sum == 0)
            if(ans % 2 == 0)printf("%lld", ans/2);
                else printf("%lld/2", ans);
        else printf("infinity");
    }
    else {
        ll ans = 0;
        for(int i = 1; i <= n; ++i){
            int a,b;
            scanf("%d %d", &a, &b);
            if(a == 0 || b == 0)ans++;
        }
        if(ans == n)printf("0");
            else printf("infinity");
    }
}