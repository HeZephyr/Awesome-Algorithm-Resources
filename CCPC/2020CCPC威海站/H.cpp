#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n, m, s, res[N << 1];
struct node{
    unordered_map<int, int> p;
    int d;
}a[N];
int main(){
    scanf("%d%d%d", &n, &m, &s);
    for(int i = 1, t, x, y; i <= s; ++ i){
        scanf("%d%d%d", &t, &x, &y);
        if(t == 1){
            //x加入y组。
            a[y].p[x] = 1;
            res[x] -= a[y].d;
        }
        else if(t == 2){
            //x退出y组。
            res[x] += a[y].d;
            a[y].p.erase(x);
        }
        else{
            //x给第y组的人发信息。
            a[y].d += 1;
            res[x] -= 1;
        }
    }
    for(int i = 1; i <= n; ++ i){
        for(auto iter : a[i].p){
            res[iter.first] += a[i].d;
        }
    }
    for(int i = 1; i <= m; ++ i){
        printf("%d\n", res[i]);
    }
    return 0;
}