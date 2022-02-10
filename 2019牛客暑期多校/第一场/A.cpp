#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e5+7;
int a[N], b[N], tr1[N*4], tr2[N*4];
int n, m;
int lowbit(int x){
    return x & (-x);
}
void add(int *c, int x, int value){
    while(x <= n){
        c[x] += value;
        x += lowbit(x);
    }
}
int get(int *c, int x){
    int ans = 0;
    while(x){
        ans += c[x];
        x -= lowbit(x);
    }
    return ans;
}
int main(){
    while(~scanf("%d", &n)){
        int x;
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            tr1[i] = tr2[i] = 0;
        }
        for(int i = 1; i <= n; ++i){
            scanf("%d", &b[i]);
        }
        int ans = n;
        for(int i = 1;i <= n;i++){
            add(tr1, a[i], 1);
            add(tr2, b[i], 1);
            int pos1 = get(tr1, a[i]);
            int pos2 = get(tr2, b[i]);
            if(pos1!=pos2){
                ans = i;
                break;
            }
        }
        printf("%d\n", ans);
    }
}