/**
  *@filename:B_Gregor_and_the_Pawn_Game
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-08-01 22:43
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200000 + 5;
const int P = 1e9+7;

int t,n;
string s1,s2;
bool vis[N];
void solve(){
    int ans = 0;
    for(int i = 0; i < n; ++ i){
        if(s2[i] == '1'){
            if(s1[i] == '0'){
                ans ++;
            }
            else{
                if(i - 1 >= 0 && !vis[i - 1] && s1[i - 1] == '1'){
                    vis[i - 1] = true;
                    ans ++;
                }
                else if(i + 1 < n && !vis[i + 1] && s1[i + 1] == '1'){
                    vis[i + 1] = true;
                    ans ++;
                }
            }
        }
    }
    cout << ans << endl;
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n;
        memset(vis,0,sizeof(vis));
        cin >> s1 >> s2;
        solve();
    }
    return 0;
}