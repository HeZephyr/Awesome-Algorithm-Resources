#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll N = 1e6 + 7;
int pri[N], vis[N];
int t;
ll c;
int main(){
    scanf("%d", &t);
    int cnt = 0;
    for(int i = 2;i <= 1e6;i++){
        if(!vis[i]){
            pri[++cnt] = i;
        }
        for(int j = 1;j<=cnt && i*pri[j]<=1e6;j++){
            vis[i*pri[j]] = 1;
            if(i%pri[j]) break;
        }
    }
    while(t -- ){
        scanf("%lld", &c);
        bool fla = 0;
        for(int i = 1;i <= cnt;i++){
            int f = 0;
            while(1){
                if(c%pri[i]==0){
                    f++;
                    c/=pri[i];
                } else {
                    break;
                }
            }
            if(f>=2){
                fla = 1;
            }
        }
        if(fla)puts("yes");
        else{
            ll x = sqrt(c);
            if(c<=1e12) puts("no");
            else if(x * x == c) puts("yes");
            else puts("no");
        }
    }
    return 0;
}