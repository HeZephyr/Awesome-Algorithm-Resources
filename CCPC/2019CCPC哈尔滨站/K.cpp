#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
int a[N];
int main(){
    int t, n, k;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &k);
        long long sum = 0;
        for(int i = 1;i <= n;i++){
            scanf("%d", &a[i]);
            sum += a[i];
        }
        for(int i = 1;i <= n;i++){
            printf("%.8lf ", 1.0*a[i]*(1.0 + 1.0*k/(1.0*sum)));
        }
        printf("\n");
    }
}