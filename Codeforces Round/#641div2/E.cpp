/**
  *@filename:E
  *@author: pursuit
  *@created: 2021-09-02 13:53
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e3 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, m, t;
char s[N][N];
/* 对于每一个位子，如果这个格子的周围有一个和这个颜色相同的情况下，那么在一次的翻转后，
那么周围颜色相同的都可以翻转，给你t tt个查询，每一个有i , j , p i,j,pi,j,p，
问在p pp次翻转后，i , j i,ji,j的颜色是什么。 */
void solve(){
}
int main(){	
    scanf("%d%d%d", &n, &m, &t);
    for(int i = 1; i <= n; ++ i){
        scanf("%s", s[i] + 1);
    }
    solve();
    return 0;
}