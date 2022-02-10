#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ll t, l, r, s, ans;
    scanf("%lld", &t);
    while(t--){
        scanf("%lld%lld%lld", &l, &r, &s);
        if(l>r) swap(l, r);
        ll f = 0;
        if(l%2==0 && r%2==0){   //偶偶
            if(s){
                if((r-l)%4) f++;
                if(s>=(r^f)) ans = r-l+1;
                else ans = r-l;
            } else {
                ans = (r-l)/4 * 4;
            }
        }
        else if(l%2==0 && r%2){ //偶奇
            if(s){
                ans = r-l+1;
            } else {
                ans = (r-l+1)/4*4;
            }
        }
        else if(l%2 && r%2==0){ //奇偶
            ll sl = l;
            l++;
            if(s){
                if((r-l)%4) f++;
                //printf("l = %lld, r = %lld, sl = %lld, s= %lld\n", l, r, sl, s);
                if((sl^r^f) <= s) ans = r-l+2;
                else if((sl^f)<=s || (r^f)<=s) ans = r-l+1;
                else ans = r-l;
            } else {
                if(sl==1){
                    if((r-l)%4) ans = r-l+1;
                    else ans = (r-l)/4*4;
                }
                else {
                    ans = (r-l)/4*4;
                }
            }
        } else {                //奇奇
            if(s){
                if((r-l)%4) f++;
                ans = r-l;
                if((l^f) <= s) ans++;
            } else {
                if(l==1){
                    if((r-l)%4) ans = r-l+1;
                    else ans = (r-l)/4*4;
                }
                else {
                    ans = (r-l)/4*4;
                }
            }
        }
        if(ans==0) printf("-1\n");
        else printf("%lld\n", ans);
    }
    return 0;
}