/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-09-24 19:14
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

char s[10];
char res[] = " cocacola";
int a[] = {1, 3, 5}, b[] = {2, 6}, c[] = {4, 8};
int minn = INF, res;
bool vis[N];
void dfs(int x, next){
    
}
void solve(){
    do{
        b[0] = 2, b[1] = 6;
        do{
            c[0] = 4, c[1] = 8;
            do{
               memset(vis, 0 ,sizeof(vis));
               res = 0;
               for(int i = 1; i <= 8; ++ i){
                   if(!vis[i])dfs(i);
               }
            }while(next_permutation(c, c + 2));
        }while(next_permutation(b, b + 2));
    }while(next_permutation(a, a + 3));
}
int main(){	
    scanf("%s", s + 1);
    solve();
    return 0;
}