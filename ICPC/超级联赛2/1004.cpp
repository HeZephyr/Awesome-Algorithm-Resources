/**
  *@filename:1004
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-22 13:37
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e5 + 5;
const int P = 1e9+7;

int n,x,q;
int trie[N * 400][2],tot,sum[N * 400];//字典树。sum[i]表示当前的节点总和。
int preIdx[N];//preIdx[i]表示i值上一次出现的下标。
int rt[N];//树状数组。
int a[N];
struct Node{
    int l,a,b,id;
};
vector<Node> v[N];//离线询问。常用技巧，能大幅提高效率。
int ans[N];//存储答案。
void insert(int &root,int v,int x){
    if(!root){
        root = ++ tot;
    }
    int u = root;
    for(int i = 20; i >= 0; -- i){
        int p = x >> i & 1;
        if(!trie[u][p]){
            //说明该节点不存在。我们创建该节点。
            trie[u][p] = ++ tot;
        }
        u = trie[u][p];
        sum[u] += v;
    }
}
int query(int root,int a,int b){
    if(!root)return 0;
    int res = 0,u = root;
    for(int i = 20; i >= 0; -- i){
        int p1 = a >> i & 1 , p2 = b >> i & 1;
        if(p2){
            if(p1){
                res += sum[trie[u][1]];
                u = trie[u][0];
            }
            else{
                res += sum[trie[u][0]];
                u = trie[u][1];
            }
        }
        else{
            if(p1){
                u = trie[u][1];
            }
            else{
                u = trie[u][0];
            }
        }
        if(!u)break;
    }
    return res + sum[u];
}
int lowbit(int x){
    return x & - x;
}
void add(int u,int v,int x){
    for(int i = u; i <= n; i += lowbit(i)){
        insert(rt[i],v,x);
    }
}
int cal(int u,int a,int b){
    int res = 0;
    for(int i = u; i > 0; i -= lowbit(i)){
        res += query(rt[i],a,b);
    }
    return res;
}
void solve(){
    for(int i = 1; i <= n; ++ i){
        if(preIdx[a[i]]){
            add(preIdx[a[i]], -1,a[i]);
        }
        preIdx[a[i]] = i;
        add(i,1,a[i]);
        for(auto iter : v[i]){
            int a = iter.a, b = iter.b;
            ans[iter.id] = cal(i,a,b) - cal(iter.l - 1,a,b);
        }
    }
    for(int i = 1; i <= q; ++ i){
        cout << ans[i] << endl;
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    scanf("%d", &q);
    for(int i = 1; i <= q; ++ i){
        int l, r, a, b;
        scanf("%d%d%d%d", &l, &r, &a, &b);
        v[r].push_back({l,a,b,i});
    }
    solve();
    return 0;
}