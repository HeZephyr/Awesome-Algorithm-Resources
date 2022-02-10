/**
  *@filename:G_Photoshop_Layers
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-27 13:43
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n,q,x,f[N];
struct node{
    int m,r,g,b;
}a[N];
int change(int x){
    return x < 255 ? x : 255;
}
void solve(){
    int l,r;
    while(q -- ){
        scanf("%d%d", &l, &r);
        int x = f[r];
        if(x >= l){
            //说明中间出现1，中断了。
            l = x;
        }
        printf("%02X%02X%02X\n", change(a[r].r - a[l - 1].r), change(a[r].g - a[l - 1].g), change(a[r].b - a[l - 1].b));
    }
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; ++ i){
            scanf("%d%X", &a[i].m, &x);
            a[i].b = x & 255;
            x >>= 8;
            a[i].g = x & 255;
            x >>= 8;
            a[i].r = x & 255;
            a[i].b += a[i - 1].b, a[i].g += a[i - 1].g, a[i].r += a[i - 1].r;
            if(a[i].m == 1){
                f[i] = i;
            }
            else{
                f[i] = f[i - 1];
            }
        }
        solve();
    }
    return 0;
}