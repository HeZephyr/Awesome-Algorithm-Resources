#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 510;

int t, n;
string s1, s2;
bool flag;
void dfs(int idx1, int idx2, bool statu){
    //statu 为 1代表向左移，否则向右移。
    if(flag)return;
    if(idx2 >= s2.size()){
        flag = true;
        return;
    }
    if(idx1 >= s1.size() || s1[idx1] != s2[idx2]){
        return;
    }
    if(statu){
        dfs(idx1 + 1, idx2 + 1, statu);
    }
    dfs(idx1 - 1, idx2 + 1, 0);
}
void solve(){
    n = s2.size(), flag = false;
    for(int i = 0; i < s1.size(); ++ i){
        dfs(i, 0, 1);
        if(flag)break;
    }
    if(flag)puts("YES");
    else puts("NO");
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        cin >> s1 >> s2;
        solve();
    }
    return 0;
}