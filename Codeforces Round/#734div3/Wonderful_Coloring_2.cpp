/**
  *@filename:Wonderful_Coloring_2
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-23 23:01
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200000 + 5;
const int P = 1e9+7;

int t,n,k,a[N],cnt[N],ans[N];
vector<int> pos;
bool cmp(int i,int j){
    return a[i] < a[j];
}
void solve(){
    sort(pos.begin(),pos.end(),cmp);
    int len = pos.size();
    //cout << len << endl;
    while(len % k)len --;
    for(int i = 0; i < len; ++ i){
        //cout << pos[i] << endl;
        ans[pos[i]] = i % k + 1;
    }
    for(int i = 1; i <= n; ++ i){
        cout << ans[i] << " ";
    }
    cout << endl;
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &k);
        pos.clear();
        for(int i = 1; i <= n; ++ i){
            cnt[i] = ans[i] = 0;
        }
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
            cnt[a[i]] ++;
            if(cnt[a[i]] <= k){
                pos.push_back(i);
            }
        }
        solve();
    }
    return 0;
}