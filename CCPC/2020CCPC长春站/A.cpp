#include<bits/stdc++.h>
int main(){
    int n;
    scanf("%d", &n);
    int ans = 0;
    int f1 = 0,f2 = 0,f3 = 0,f4 = 0,f5 = 0,f6 = 0,f7 = 0;
    while(n){
        int cnt = 0;
        if(n>=648 && !f1){
            ans += 6480+388;
            f1 = 1;
            cnt++;
            n-=648;
        }
        else if(n>=328 && !f2){
            ans += 3280+198;
            f2 = 1;
            cnt++;
            n-=328;
        }
        else if(n>=198 && !f3){
            ans += 1980+128;
            f3 = 1;
            cnt++;
            n-=198;
        }
        else if(n>=88 && !f4){
            ans +=  880+58;
            f4 = 1;
            cnt++;
            n-=88;
        }
        else if(n>=28 && !f5){
            ans += 280+28;
            f5 = 1;
            cnt++;
            n-=28;
        }
        else if(n>=6 && !f6){
            ans += 60+18;
            f6 = 1;
            cnt++;
            n-=6;
        }
        else if(n && !f7){
            ans += 10+8;
            f7 = 1;
            cnt++;
            n--;
        }
        if(!cnt) break;
    }
    printf("%d\n", ans+n*10);
    return 0;
}