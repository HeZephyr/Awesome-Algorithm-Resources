#include<bits/stdc++.h>

using namespace std;

int t, n;
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        int cnt = 0, cur = 1;
        while(cnt <= 1000){
            if(cur == 0)break;
            cur %= n;
            cur *= 10;
            ++ cnt;
        }
        if(cnt > 1000)puts("Yes");
        else puts("No");
    }
    return 0;
}