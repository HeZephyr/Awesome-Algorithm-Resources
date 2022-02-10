/**
  *@filename:三升序列
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-15 21:47
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

char g[32][55];
void solve(){
    ll ans=0;
    for(int i=0;i<30;i++){
        for(int j=0;j<50;j++){
            for(int k=j+1;k<50;k++){
                for(int t=k+1;t<50;t++){
                    if(g[i][k]>g[i][j]&&g[i][k]<g[i][t]){
                        ans++;
                    }
                }
            }
        }
    }
    for(int i=0;i<50;i++){
        for(int j=0;j<30;j++){
            for(int k=j+1;k<30;k++){
                for(int t=k+1;t<30;t++){
                    if(g[k][i]>g[j][i]&&g[k][i]<g[t][i]){
                        ans++;
                    }
                }
            }
        }
    }
}
int main(){
    for(int i=0;i<30;i++){
        cin>>g[i];
    }
    solve();
    return 0;
}