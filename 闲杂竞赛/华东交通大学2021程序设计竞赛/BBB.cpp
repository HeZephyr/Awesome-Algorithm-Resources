#include<bits/stdc++.h>

using namespace std;

int n, a[11110];

int g[11110];
int main(){
    cin >> n;
    for(int i = 1; i <= n; ++ i){
        cin >> a[i];
    }
    int res = 0;
    for(int i = 1; i <= n; ++ i){
        int len1 = 0, len2 = 0;
        for(int j = 1; j <= 2 * n; ++ j){
            g[j] = 0;
        }
        for(int j = 1; j < i; ++ j){
            if(a[j] <= a[i]){
                if(a[j] >= g[len1]){
                    g[++ len1] = a[j];
                }
                else{
                    int idx = lower_bound(g + 1, g + 1 + len1, a[j]) - g;
                    g[idx] = a[j];
                }
            }
        }
        for(int j = 1; j <= 2 * n; ++ j){
            g[j] = 0;
        }
        for(int j = n; j > i; -- j){
            if(a[j] <= a[i]){
                if(a[j] >= g[len2]){
                    g[++ len2] = a[j];
                }
                else{
                    int idx = lower_bound(g + 1, g + 1 + len2, a[j]) - g;
                    g[idx] = a[j];
                }
            }
        }
        if(len1 + len2 + 1 > res){
            res = len1 + len2 + 1;
        }
    }
    printf("%d\n", n - res);
}