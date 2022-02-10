#include<bits/stdc++.h>
using ll = long long;
using namespace std;

const int N = 1e5;
int t, n, m, tot;
map<string, int> p;
map<int, int> p2;
vector<int> g[N];
string s1[N], s2[N];
int siz[N];
int root[N], cnt;
int vis[N];
void solve(){
    for(int i = 1; i <= n; ++ i){
        string pre = "";
        for(int j = 0; j < s1[i].size(); ++ j){
            if(s1[i][j] == '/'){
                string temp = s1[i].substr(0, j);
                p[temp] = ++ tot;
                if(pre == "")pre = temp, root[++ cnt] = tot, p2[tot] = cnt;
                else{
                    g[p[pre]].push_back(tot);
                    siz[p[pre]] ++;
                }
            }
        }
        if(pre != ""){
            p[s1[i]] = ++ tot;
            g[p[pre]].push_back(tot);
            siz[p[pre]] ++;
        }
        else{
            p[s1[i]] = ++ tot;
            root[++ cnt] = tot, p2[tot] = cnt;
        }
    }
    int res = 0;
    for(int i = 1; i <= m; ++ i){
        vector<string> idx;
        for(int j = 0; j < s2[i].size(); ++ j){
            if(s1[i][j] == '/'){
                string temp = s2[i].substr(0, j);
                idx.push_back(temp);
            }
        }
        idx.push_back(s2[i]);
        string cur = idx[0];
        if(!p[cur])continue;
        for(int j = 1; j < idx.size(); ++ j){
            if(vis[p[idx[j]]])break;
            if(p[idx[j]])continue;
            else {
                vis[p[idx[j]]] = siz[p[idx[j - 1]]];
                break;
            }

        }
    }
    int ans = 0;
    for(int i = 1; i <= tot; ++i){
        ans += vis[i];
    }
    printf("%d\n", ans);

}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n >> m;
        tot = cnt = 0;
        memset(vis, 0, sizeof(vis));
        memset(siz, 0, sizeof(siz));
        for(int i = 1; i <= n; ++ i)cin >> s1[i];
        for(int i = 1; i <= m; ++ i)cin >> s2[i];
        solve();
    }
    return 0;
}
