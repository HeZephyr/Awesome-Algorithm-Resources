#include<bits/stdc++.h>
using namespace std;
int a[10], b[10], c[10];
int main(){
    int n;
    scanf("%d", &n);
    a[1] = 1, a[2] = 6, a[3] = 28, a[4] = 88, a[5] = 198, a[6] = 328, a[7] = 648;
    b[1] = 8, b[2] = 18, b[3] = 28, b[4] = 58, b[5] = 128, b[6] = 198, b[7] = 388;
    int ans = 0;
    for(int i = 0;i < 128;i++){
        int x = i, cnt = 0, sum = 0, tem = 0;
        while(x){
            c[++cnt] = x&1;
            if(c[cnt]&1){
                sum += a[cnt];
            }
            x>>=1;
        }
        if(sum>n) break;
        for(int j = 1;j <= cnt;j++){
            if(c[j]){
                tem += b[j];
            }
        }
        ans = max(ans, tem+n*10);
    }
    printf("%d\n", ans);
 }