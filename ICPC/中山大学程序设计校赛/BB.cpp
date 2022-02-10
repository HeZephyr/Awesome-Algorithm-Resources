#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5+7;
char s[3];
int r1[N], c1[N], d1[N], r2[N], c2[N], d2[N];
int main(){
    ll t, n, m, x;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld", &n, &m);
        for(int i = 1;i <= n;i++){
            r2[i] = c2[i] = d2[i] = n;
        }
        ll sum = 0;
        while(m--){
            scanf("%s", s);
            if(s[0]=='R'){
                scanf("%d", &x);
                swap(r1[x], r2[x]);
                sum = sum-r2[x]+r1[x];
                if(d[x])
            }
            else if(s[0]=='C'){
                scanf("%d", &x);

            } else {
                
            }
            printf("ans = %lld\n", sum);
        }
    }
    return 0;
}