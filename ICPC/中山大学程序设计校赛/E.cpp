#include<bits/stdc++.h>
using namespace std;

int n;
int a[10];
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + 1 + n);
        int minn = 1e9;
        do{
            int ans = 0;
            for(int i = 1; i <= n; ++ i){
                ans = abs(ans - a[i]);
            }
            minn = min(ans, minn);
        }while(next_permutation(a + 1, a + 1 + n));
        printf("%d\n", minn);
    }
    return 0;
}