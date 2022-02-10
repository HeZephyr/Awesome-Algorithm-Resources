#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
//
int n,a[N];
char s[N];
void solve(){
    for(int i = 1; i <= n - 1; ++ i){
        if(s[i] == '1'){
            int j = i;
            while(j + 1 <= n - 1 && s[j + 1] == '1'){
                j ++ ;
            }
            sort(a + i,a + 1 + j + 1);
            i = j;//注意这里需要直接跳到j。
        }
    }
    for(int i = 1; i <= n; ++ i){
        if(a[i] != i){
            puts("NO");
            return;
        }
    }
    puts("YES");
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    scanf("%s",s + 1);
    solve();
    return 0;
}