#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e6+7;
int a[N], rad[N], c[N], ans[N];
int main(){
    int t, n;
    scanf("%d", &t);
    for(int k = 1; k <= t; ++ k){
        scanf("%d", &n);
        for(int i = 1;i <= n;i++){
            scanf("%d", &rad[i]);
            a[i-rad[i]+1]++;
            a[i-rad[i]-1]--;
        }
        int l = 0, r = 0;
        for(int i = 1;i <= n;i++){
            r += a[i];
            c[l]++, c[r]--;
            l++;
        }
        for(int i = 1;i <= n;i++){
            ans[i] += c[i-1];
        }
        for(int i = 1;i <= n;i++){
            printf("%d ", ans[i]);
        }
    }
    return 0;
}