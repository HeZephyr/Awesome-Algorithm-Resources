#include<bits/stdc++.h>

using namespace std;

const int N = 110;
int t;
int x;
unordered_map<int, int> mp;
unordered_map<int, int> ans;
int Find(int x){
    if(x==mp[x]) return x;
    else return mp[x] = Find(mp[x]);
}
int main(){
    int n, u, v;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1;i <= n;i++){
            scanf("%d%d", &u, &v);
            if(!mp[u]) mp[u] = u;
            if(!mp[v]) mp[v] = v;
            int fu = Find(u);
            int fv = Find(v);
            if(fu!=fv){
                mp[fu] = fv;
            }
        }
        int tem = 0;
        for(auto it:mp){
            ans[Find(it.second)]++;
            tem = max(tem, ans[Find(it.second)]);
        }
        printf("%d\n", tem);
        ans.clear();
        mp.clear();
    }
    return 0;
}