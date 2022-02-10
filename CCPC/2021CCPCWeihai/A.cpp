#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+7;
int a[N];
int main(){
    int n, u, v;
    scanf("%d", &n);
    for(int i = 1;i < n;i++){
        scanf("%d%d", &u, &v);
        a[u]++;
        a[v]++;
    }
    int cnt = 0, fla = 0;
    for(int i = 1;i <= n;i++){
        if(a[i]>=3) cnt++;
        if(a[i]>=4) fla = 1;
    }
    if(fla) printf("0\n");
    else printf("%d\n", n-cnt);
    return 0;
}