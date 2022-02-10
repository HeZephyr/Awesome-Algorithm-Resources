#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
const int MOD = 1e9+7;
int a[N];
long long b[N], c[N];
int main(){
    int t, n;
    scanf("%d", &t);
    b[0] = c[0] = 1ll;
    for(long long i = 1;i <= 1e5;i++){
        b[i] = b[i-1]*2ll%MOD;
        c[i] = c[i-1]*i%MOD;
    }
    while(t--){
        scanf("%d", &n);
        for(int i = 1;i <= n;i++){
            scanf("%d", &a[i]);
        }
        int pos = 0, fla = 0;
        for(int i = 1;i <= n;i++){
            if(a[i]>=n || i<n && a[i]>a[i+1]){
                fla = 1;
                break;
            }
            if(a[i]==n-1 && pos==0) pos = i;
        }
        //printf("pos = %d\n", pos);
        if(fla || pos==0){
            printf("0\n");
        } else {
            int cb = 0, cc = 0;
            long long ans = 1ll;
            for(int i = 1;i < n;i++){
                if(a[i]<a[i+1]){
                    cb++;
                    cc += a[i+1]-a[i]-1;
                } else {
                    ans = ans*cc%MOD;
                    cc--;
                    if(cc<0){
                        fla = 1;
                        break;
                    }
                }
            }
            printf("cb = %d, cc = %d\n", cb, cc);
            if(fla) printf("0\n");
            else printf("%lld\n", ans*b[cb]%MOD*c[cc]%MOD);
        }
    }
    return 0;
}