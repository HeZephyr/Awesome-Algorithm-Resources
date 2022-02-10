#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int t, n, k, m;
vector<int> v[N];
int res[N];
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d%d", &n, &k, &m);
        for(int i = 0, x; i < n; ++ i){
            scanf("%d", &x);
            v[x].push_back(i);
        }
        int u = m / n, x = m % n;//循环次数和最后一轮到达位置。
        for(int i = 1; i <= k; ++ i){
            if(v[i].size() % 2){
                for(int j = 0; j < v[i].size(); ++ j){
                    if(j & 1){
                        res[v[i][j]] += (u + 1) / 2;
                    }
                    else{
                        res[v[i][j]] += u / 2;
                    }
                }
                for(int j = 0; j < v[i].size(); ++ j){
                    
                }
            }
        }
    }
    return 0;
}