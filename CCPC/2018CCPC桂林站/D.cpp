#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 107;

int main(){
    ll x, y, t;
    scanf("%lld", &t);
    for(int tt = 1;tt <= t;tt++){
        scanf("%lld%lld", &x, &y);
        ll cnt = 0;
        vector<int> vx1, vx2, vy1, vy2;
        while(x){
            cnt++;
            if(x&1){
                if(cnt&1){
                    vx1.push_back(cnt);
                } else {
                    vx2.push_back(cnt);
                }
            }
            x>>=1ll;
        }
        cnt = 0;
        while(y){
            cnt++;
            if(y&1){
                if(cnt&1){
                    vy1.push_back(cnt);
                } else {
                    vy2.push_back(cnt);
                }
            }
            y>>=1ll;
        }
        printf("Case %d: ", tt);
        if(vx1.size()!=vy1.size() || vx2.size()!=vy2.size()){
            printf("-1\n");
            continue;
        }
        sort(vx1.begin(), vx1.end());sort(vx2.begin(), vx2.end());sort(vy1.begin(), vy1.end());sort(vy2.begin(), vy2.end());
        int ans = 0;
        for(int i = 0;i < vx1.size();i++){
            ans += abs(vx1[i]-vy1[i])/2;
        }
        for(int i = 0;i < vx2.size();i++){
            ans += abs(vx2[i]-vy2[i])/2;
        }
        printf("%d\n", ans);
    }
}