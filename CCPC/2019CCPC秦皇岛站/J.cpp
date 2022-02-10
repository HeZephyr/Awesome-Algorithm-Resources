#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const int N = 1e7+7;

char s1[N], s2[N];
int ne[N];
void getne(int len, char *s){
    ne[1] = 0;
    for(int i = 2, j = 0;i <= len;i++){
        while(j>0 && s[i]!=s[j+1])
            j = ne[j];
        if(s[i]==s[j+1])
            j++;
        ne[i] = j;
    }
}
int main(){
    ll a, b;
    scanf("%lld%lld%s", &a, &b, s1+1);
    int n = strlen(s1+1), cnt = 0;
    for(int i = n;i;i--){
        if(s1[i]=='.') break;
        s2[++cnt] = s1[i];
    }
    getne(cnt, s2);
    ll ans = INT64_MIN;
    //printf("%lld\n", ans);
    for(int i = 1;i <= cnt;i++){
        printf("p = %lld, j = %lld\n", i, i-ne[i]);
        ans = max(ans, a*i - b*(i-ne[i]));
    }
    printf("%lld\n", ans);
    return 0;
}