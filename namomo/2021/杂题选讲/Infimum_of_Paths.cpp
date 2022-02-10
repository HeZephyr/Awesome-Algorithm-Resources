/**
  *@filename:Infimum_of_Paths
  *@author: pursuit
  *@created: 2021-10-28 20:42
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

/*
给定一个n个顶点m条边的有向图，每条边权值为0-9.找出结点0到结点1最小路径。
*/
int t, n, m;
void solve(){
}
int main(){	
    scanf("%d", &t);
    for(int k = 1; k <= t; ++ k){
        scanf("%d%d", &n, &m);
        solve();
    }
    return 0;
}