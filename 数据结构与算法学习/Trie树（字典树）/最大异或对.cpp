/**
  *@filename:最大异或对
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-11 18:37
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n;
int trie[maxn*31][2],sum[maxn*31];//结点出现次数。
//在tire树中第一维就是下标的值，第二位就代表着儿子，在本题中，只有0或1 两个儿子。
int tot;
void insert(int x){
    int p=0;
    for(int i=30;i>=0;i--){
        int u=x>>i&1;
        if(trie[p][u]==0){
            trie[p][u]=++tot;
        }
        p=trie[p][u];
    }
}
int query(int x){
    int p=0;
    int res=0;
    for(int i=30;i>=0;i--){
        int u=x>>i&1;
        if(trie[p][!u]){
            p=trie[p][!u];
            res=res*2+1;
        }
        else{
            p=trie[p][u];
            res=res*2;
        }
    }
    return res;
}
void solve(){
}
int main(){
    int maxx=0,x;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        insert(x);
        maxx=max(maxx,query(x));
    }
    cout<<maxx<<endl;
    solve();
    return 0;
}