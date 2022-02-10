#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, m, k;//n个调查结果，每个调查结果包括m个问题，每个问题有两个选项，A和B。
//现在任选一个问题的子集，如果>=k对答卷在该子集上答案有不同，那么这个子集就是可以辨别的，求这个子集数量。
//我们将问题转化成01串，那么两个答卷相同就是两个01串异或为0.
void solve(){
}
int main(){	
    cin >> n >> m >> k;
    solve();
    return 0;
}                                             