/**
  *@filename:蒙德里安的梦想
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-01 15:31
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 12,M = 1 << N;
const int P = 1e9+7;

//核心：先放横着的，再放竖着的，因为我们放完横着的了，那么竖着的就没得选择，只能插入进去了。
//总方案数，等于只放横着的小方块的合法方案数。
//那么如何判断当前方案是否合法呢？所有剩余位置，能否填充竖着的小方块，
//也就是说，可以按列来看，每一个列内部所有连续的空着的小方块，需要是偶数个。
//用f[i][j]表示已经将前i - 1列摆好，且从第i - 1列，伸出到第i列的状态是j的所有方案。
//j是一个二进制数，用来表示哪一行的小方块是横着放的，其位数和棋盘的行数一致。
//既然第i列固定了。那么就要看第i - 2列是怎么转移到第i - 1列的（看转移过来的状态）。
//我们设前一列的状态为k,即f[i - 1][k]，表示前i - 2列已经摆好，且从i - 2列伸到第i - 1列的状态为k的所有方案数。
//则易知k和j不能在同一行。即(k & j) == 0，判断是否有一行是相同的。
//我们既然从第i - 1列到第i列横着摆的，和第i - 2列到第i - 1列横着摆的也都确定了，那么第i - 1列空着的各自就确定了，这些用来放竖着的各自。
//我们一定要注意，该列所有连续空着的位置长度必须是偶数。
int n,m;
ll f[N][M];
bool g[M];//g[i]表示i这个状态的列是否有连续个偶数的的0。
vector<int> st[M];
int maxn;
void init(){
    maxn = 1 << n;
    for(int i = 0; i < maxn; ++ i){
        g[i] = true;
        //判断是否有偶数个0.
        int cnt = 0;
        for(int j = 0; j < n; ++ j){
            if((i >> j) & 1){
                if(cnt & 1){
                    break;
                }
                cnt = 0;
            }
            else{
                cnt ++;
            }
        }
        if(cnt & 1)g[i] = false;
    }
    //预处理，判断第i - 2列伸出来的和第i - 1列伸出去的是否有冲突。
    for(int i = 0; i < maxn; ++ i){
        st[i].clear();
        for(int j = 0; j < maxn; ++ j){
            if((i & j) == 0 && g[i | j]){
                //这里我们需要知道，我们需要考虑的是第i - 1列，这个为主体，而第i - 2是伸过来的，而第i列则是由第i - 1列伸出去的。
                //所以首先我们需要判断它们是否在同一行。同时，对于延伸的，我们需要判断合成的第i - 1列是否符合要求。
                st[i].push_back(j);
            }
        }
    }
}
void solve(){
    init();
    memset(f,0,sizeof(f));
    f[0][0] = 1;//初始状态。
    for(int i = 1; i <= m; ++ i){
        for(int j = 0; j < maxn; ++ j){
            for(auto & k : st[j]){
                //遍历第i - 1行的可行状态。
                f[i][j] += f[i - 1][k];
            }
        }
    }
    printf("%lld\n", f[m][0]);//需要注意这个状态，因为到m列我们不能延伸了。
}
int main(){
    while(scanf("%d %d", &n , &m) != EOF && (n || m)){
        solve();
    }
    return 0;
}