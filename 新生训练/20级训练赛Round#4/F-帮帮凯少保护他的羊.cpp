#include <bits/stdc++.h>

using namespace std;

const int N = 500 + 5;

int n,m;//n * m的矩阵。
char s[N][N];
bool check(int x,int y){
    if((x > 0 && s[x - 1][y] == 'S') || (y > 0 && s[x][y - 1] == 'S') || 
    (x < n - 1 && s[x + 1][y] == 'S') || (y < m - 1 && s[x][y + 1] == 'S')){
        return false;
    }
    return true; 
}
void solve(){
    for(int i = 0; i < n; ++ i){
        for(int j = 0; j < m; ++ j){
            if(s[i][j] == 'W'){
                if(!check(i,j)){
                    puts("NO");
                    return;
                }
            }
        }
    }
    puts("YES");
    for(int i = 0; i < n; ++ i){
        for(int j = 0; j < m; ++ j){
            if(s[i][j] == '.'){
                s[i][j] = 'D';
            }
        }
        puts(s[i]);
    }
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++ i){
        scanf("%s",s[i]);
    }
    solve();
    return 0;
}