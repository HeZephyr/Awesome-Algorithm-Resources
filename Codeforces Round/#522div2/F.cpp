/**
  *@filename:F
  *@author: pursuit
  *@created: 2021-08-31 17:23
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
有一个n个顶点组成的树，他想删除这颗树中的一些边，使得最大匹配唯一。
他要求你计算选择要删除的一组边的方法数。
*/
int n;
struct edge{
    int to,next;
}edges[N];
int head[N], tot;
void solve(){
}
int main(){	
    solve();
    return 0;
}