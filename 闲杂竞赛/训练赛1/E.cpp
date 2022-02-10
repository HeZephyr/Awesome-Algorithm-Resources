/**
  *@filename:E
  *@author: pursuit
  *@created: 2021-08-08 19:14
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl;

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n;
vector<ll> a;
map<ll,int> p;
void dfs(int i,vector<ll> ans,int cnt){
    //debug(ans[i]);
    if(cnt == n){
        for(int j = 1; j < ans.size(); ++ j){
            printf("%lld ", ans[j]);
        }
        puts("");
        return;
    }
    for(int op = 0; op < 2; ++ op){
        if(op == 0 && ans[i] % 3 == 0 && p[ans[i] / 3]){
            ans.push_back(ans[i] / 3);
            dfs(i + 1,ans,cnt + 1);
            ans.pop_back();
        }
        else if(op == 1 && p[2 * ans[i]]){
            ans.push_back(ans[i] * 2);
            dfs(i + 1, ans,cnt + 1);
            ans.pop_back();
        }
    }
}
void solve(){
    sort(a.begin(),a.end());
    bool flag = false;
    vector<ll> temp;
    temp.push_back(0);
    for(int i = 1; i <= n; ++ i){
        temp.push_back(a[i]);
        dfs(1,temp,1);
        temp.pop_back();
        if(flag)break;
    }
}
int main(){
    scanf("%d", &n);
    a.resize(n + 1);
    for(int i = 1; i <= n; ++ i){
        scanf("%lld", &a[i]);
        p[a[i]] = i;
    }	
    solve();
    return 0;
}