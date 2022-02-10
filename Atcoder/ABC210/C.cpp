/**
  *@filename:C
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-25 15:54
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 3e5 + 5;
const int P = 1e9+7;

int n,k,c[N];
unordered_map<int,int> p;//判断是否符合。
void solve(){
    int maxx = 1;
    for(int i = 1; i <= k; ++ i){
        p[c[i]]++;//先将前i个放入map中
    }
    maxx = max(maxx,(int)p.size());
    for(int i = k + 1; i <= n; ++ i){
        p[c[i]] ++;
        p[c[i - k]]--;
        if(p[c[i - k]] == 0)p.erase(c[i - k]);
        maxx = max(maxx,(int)p.size());
    }
    cout << maxx << endl;
}
int main(){
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &c[i]);
    }
    solve();
    return 0;
}