/**
  *@filename:tarjan双连通分量
  *@author: pursuit
  *@created: 2021-08-13 20:21
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
知识：
u和v边双连通：在一张无向图中，对于两个点u和v，
如果无论删去哪条边（只能删去一条）都不能使它们不连通，我们就说u和v边双连通。
u和v点双连通：....如果无论删除哪个点（除了u和v）都不能使他们不连通，则u和v点双连通。
注意，边双连通具有传递性，即x，y边双连通，y，z边双连通，那么x，z边双连通。
而点双连通则不具有传递性。
双连通分量：bcc，有点双连通分量和边双连通分量两种。
若一个无向图中的去掉任意一个结点（一条边）都不会改变此图的连通性，即不存在割点（桥）
则称为点（边）双连通图。
而一个无向图中的每一个极大点（边）双连通子图被称作次无向图的点（边）双连通分量。
 */
void solve(){
}
int main(){	
    solve();
    return 0;
}