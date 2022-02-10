#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e5 + 10;

int t, x;
int a[33];
int main(){
    int t;
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &x);
        int cnt = 0;
        for(int i = 31; i >= 0; -- i){
            a[i] = (x >> i) & 1;
            if(a[i] == 1)++ cnt;
        }
        int res = 0;
        while(true){
            if(!cnt)break;
            ++ res;
            if(cnt % 2 == 0){
                //说明去掉最高位。
                -- cnt;
            }
            else{
                if(a[0] == 1)a[0] = 0, -- cnt;
                else a[0] = 1, ++ cnt;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}