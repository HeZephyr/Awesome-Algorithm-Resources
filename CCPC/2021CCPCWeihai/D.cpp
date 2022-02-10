#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+7;
char s[N];
int a[N], sum[N], ne[N];
int main(){
    int t, x;
    scanf("%s", s);
    scanf("%d", &t);
    int n = strlen(s);
    int i, j;
    j = ne[0] = -1;
    i = 0;
    while(i<n){
        while(j!=-1 && s[i]!=s[j]) j = ne[j];
        ne[++i] = ++j;
    }
    for(int i = 0;i <= n;i++){
        printf("ne[%d] = %d\n", i, ne[i]);
    }
    for(int i = 1;i <= ne[n];i++){
        a[i] = 1;
    }
    for(int i = 1;i <= n;i++){
        //printf("%d ", a[i]);
        sum[i] = sum[i-1] + a[i];
    }
    while(t--){
        scanf("%d", &x);
        printf("%d\n", sum[min(x-1, n-x)]);
    }
    return 0;
}