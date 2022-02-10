#include<bits/stdc++.h>
#define ll long long 

const int N = 10 + 5;
const int P = 1e9 + 7;
using namespace std;

int n, m1, m2;
bool mp1[N][N], mp2[N][N];
int id[N];
int main(){
    while(cin >> n >> m1 >> m2){
        int u, v;
        memset(mp1, false, sizeof(mp1));
        memset(mp2, false, sizeof(mp2));
        for(int i = 1; i <= m1; ++ i){
            cin >> u >> v;
            mp1[u][v] = mp1[v][u] = true;
        }
        for(int i = 1; i <= m2; ++ i){
            cin >> u >> v;
            mp2[u][v] = mp2[v][u] = true;
        }
        ll res1 = 0, res2 = 0;
        for(int i = 1; i <= n; ++ i)id[i] = i;
        do{
            bool flag = true;
            for(int i = 1; i <= n; ++ i){
                for(int j = 1; j <= n; ++ j){
                    if(mp1[i][j] && !mp2[id[i]][id[j]]){
                        flag = false;
                        break;
                    }
                }
            }
            res1 += flag;
        }while(next_permutation(id + 1, id + 1 + n));
        do{
            bool flag = true;
            for(int i = 1; i <= n; ++ i){
                for(int j = 1; j <= n; ++ j){
                    if(mp1[i][j] && !mp1[id[i]][id[j]]){
                        flag = false;
                        break;
                    }
                }
            }
            res2 += flag;
        }while(next_permutation(id + 1, id + 1 + n));
        cout << res1 / res2 << endl;
    }
}