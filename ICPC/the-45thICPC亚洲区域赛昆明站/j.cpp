#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n, m, a[N], b[N];
bool vis[N];

int main(){
    vector<pair<int, int>> v1, v2;
    int n;
    scanf("%d", &n);
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
        b[a[i]] = i;
    }
    int fla = 0;
    for(int i = 1;i <= n;i++){
        if(a[i]!=i){
            if(b[i]==a[i]){
                v1.push_back({i, a[i]});
                int x = a[i];
                swap(a[i], a[x]);
            } else{
                fla = 1;
            }
        }
    }
    if(!fla){
        if(v1.empty()){
            printf("0\n");
            return 0;
        }
        printf("1\n%d ", v1.size());
        for(int i = 0;i < v1.size();i++){
            printf("%d %d", v1[i].first, v1[i].second);
            if(i<v1.size()-1) printf(" ");
        }
        return 0;
    }
    for(int i = 1;i <= n;i++){
        if(vis[i]) continue;
        if(a[i]!=i){
            //printf("a[%d] = %d\n", i, b[i]);
            int tem = b[i];
            int x = a[tem], y = b[tem];
            while(x!=y){
                if(vis[x] || vis[y]) break;
                //printf("x = %d, y = %d\n",x, y);
                v1.push_back({x, y});
                vis[x] = vis[y] = 1;
                swap(a[x], a[y]);
                int nex = a[y], ney = b[y];
                b[a[x]] = x, b[a[y]] = y;
                x = nex, y = ney;
            }
        }
    }
    for(int i = 1;i <= n;i++){
        if(a[i]!=i){
            v2.push_back({i, a[i]});
            int x = a[i];
            swap(a[i], a[x]);
        }
    }
    printf("2\n%d ", v1.size());
    for(int i = 0;i < v1.size();i++){
        printf("%d %d", v1[i].first, v1[i].second);
        if(i<v1.size()-1) printf(" ");
    }
    printf("\n%d ", v2.size());
    for(int i = 0;i < v2.size();i++){
        printf("%d %d", v2[i].first, v2[i].second);
        if(i<v2.size()-1) printf(" ");
    }
    return 0;
}