#include<bits/stdc++.h>

using namespace std;
const int N = 1e6+7;
int tr[N][12], cnt, vis[N];
void add(char *s){
    int p = 0, n = strlen(s);
    for(int i = 0;i < n;i++){
        if(!tr[p][s[i]-'0']){
            tr[p][s[i]-'0'] = ++cnt;
        }
        p = tr[p][s[i]-'0'];
    }
    vis[p] = 1;
}
bool query(char *s){
    int p = 0, n = strlen(s);
    for(int i = 0;i < n;i++){
        if(!tr[p][s[i]-'0']){
            return false;
        }
        p = tr[p][s[i]-'0'];
        if(vis[p]) return true;
    }
    return true;
}
int main(){
    int t, n;
    scanf("%d", &t);
    for(int c = 1; c <= t;c++){
        cnt = 0;
        char s[13];
        scanf("%d", &n);
        bool fla = 0;
        while(n--){
            scanf("%s", s);
            if(fla) continue;
            if(query(s)){
                fla = 1;
                continue;
            }
            add(s);
        }
        printf("Case #%d: ", c);
        if(fla) printf("No\n");
        else printf("Yes\n");
        for(int i = 0;i <= cnt;i++){
            vis[i] = 0;
            for(int j = 0;j <= 9;j++){
                tr[i][j] = 0;
            }
        }
    }
    return 0;
}