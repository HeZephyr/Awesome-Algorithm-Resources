#include<bits/stdc++.h>

using namespace std;

const int N = 110;
int n;
char s[N];
void solve(){
    int ans = n;//什么都不替换自然为n。
    for(int i = 1; i < n; ++ i){
        if((s[i] == 'R' && s[i + 1] == 'U' || s[i] == 'U' && s[i + 1] == 'R')){
            ans -- ;
            i ++;
        }
    }
    printf("%d\n",ans);
}
int main(){
    while(scanf("%d", &n) != EOF){
        scanf("%s", s + 1);
        solve();
    }
    return 0;
}