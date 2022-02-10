/**
  *@filename:B_Diameter_of_Graph
  *@author: pursuit
  *@created: 2021-10-05 10:45
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//需要你判断是否创建一个n个顶点m条边的无向连通图，需要保证图没有自环和重边，且图的直径严格小于k - 1.
//图的直径表示为最大的任意两个结点之间的的最小距离。
int t;
ll n, m, k;
void solve(){
    //首先需要考虑能不能形成一个无向连通图并且符合图的规则。
    if(n * (n - 1) / 2 < m || n - 1 > m){
        puts("NO");
    }
    else if(k < 3){
        //此时我们要小于k - 1即是小于1，此时只有一个顶点的时候才满足。
        if(n == 1 && k == 2)puts("YES");
        else puts("NO");
    }
    else if(k == 3){
        //此时直径必须小于等于1。这个时候只有每个点都和其他点连了一条边才符合。
        if(n * (n - 1) / 2 == m)puts("YES");
        else puts("NO");
    }
    else{
        puts("YES");
    }
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> n >> m >> k;
        solve();
    }
    return 0;
}