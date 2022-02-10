#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 2033;
int a[N], b[N];
struct node{
    int a, id;
    bool operator < (const node &x) const{
        return a<x.a;
    }
}p[N];
bool vis[N];
int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1;i <= n;i++){
            vis[i] = 0;
            scanf("%d", &a[i]);
            p[i] = {a[i], i};
        }
        for(int i = 1;i <= n;i++){
            scanf("%d", &b[i]);
        }
        sort(p+1, p+1+n);
        vector<pair<int, int> > ans;
        bool fla = 0;
        for(int i = 1;i <= n;i++){
            int r = p[i].id, l = p[i].id;
            if(a[r]==b[r]) continue;
            l--;
            //printf("l = %d, r = %d\n", l, r);
            while(l>0){
                while(a[l]==b[l] || a[r]>a[l]){
                    l--;
                    if(!l) break;
                }
                //printf("l = %d, r = %d\n", l, r);
                if(!l) break;
                ans.push_back({l, r});
                p[a[l]].id = r;
                p[a[r]].id = l;
                swap(a[l], a[r]);
                if(a[l]==b[l]){
                    break;
                }
                l--;
                r--;
            }
        }
        for(int i = 1;i <= n;i++){
            if(a[i]!=b[i]){
                fla = 1;
                break;
            }
        }
        if(fla){
            printf("-1\n");
            continue;
        }
        printf("%d\n", ans.size());
        for(auto it:ans){
            printf("%d %d\n", it.first, it.second);
        }
    }
    return 0;
}