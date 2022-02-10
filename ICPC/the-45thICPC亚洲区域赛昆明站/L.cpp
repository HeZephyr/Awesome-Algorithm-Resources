#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
int t, n, a[N], ans[N], res[N], len;
int check(int x){
    int l = 1, r = len, mid;
    while(l <= r){
        mid = (l + r) >> 1;
        if(x < res[mid]){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return l;
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        res[1] = a[1];
        ans[1] = len = 1;
        for(int i = 2; i <= n; ++ i){
            if(a[i] < res[len]){
                res[++ len] = a[i];
                ans[i] = len;
            }
            else{
                int idx = check(a[i]);
                //cout << a[i] << "idx: " << idx << endl;
                res[idx] = a[i];
                ans[i] = idx;
            }
        }
        printf("%d\n", len);
        for(int i = 1; i <= n; ++ i){
            printf("%d%c", ans[i], i == n ? '\n' : ' ');
        }
    }
    return 0;
}