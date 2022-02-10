/**
  *@filename:BBB
  *@author: pursuit
  *@created: 2021-10-07 20:18
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e3 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, m;
char a[N][N], b[N][N];
int main(){	
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++ i){
        scanf("%s", a[i]);
    }
    int cnt = 0;
    for(int i = 0; i < n; ++ i){
        scanf("%s", b[i]);
        for(int j = 0; j < m; ++ j){
            if(a[i][j] != b[i][j]){
                ++ cnt;
            }
        }
    }
    if(cnt <= n * m / 2){
        for(int i = 0; i < n; ++ i){
            printf("%s\n", a[i]);
        }
    }
    else{
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < m; ++ j){
                printf("%c", a[i][j] == 'X' ? '.' : 'X');
            }
            puts("");
        }
    }
    return 0;
}