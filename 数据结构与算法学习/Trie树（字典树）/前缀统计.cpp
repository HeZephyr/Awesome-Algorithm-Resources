/**
  *@filename:前缀统计
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-10 21:46
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1000000 + 5;
const int mod = 1e9+7;

int n,m;
ll trie[maxn][26],cnt[maxn];//cnt[i]表示编号为i的子树有多少个。即就是以i为前缀的有多少个。
//查询已有字符串多少是T的前缀。
int tot;//编号。
void insert(string s){
    int len=s.size();
    ll p=0;
    for(int i=0;i<len;i++){
        if(!trie[p][s[i]-'a']){
            //说明不存在该子树，我们创建它。
            trie[p][s[i]-'a']=++tot;
        }
        p=trie[p][s[i]-'a'];
    }
    cnt[p]++;//统计编号为这样的子树数量+1。
}
int query(string s){
    int len=s.size(),p=0;
    int res=0;
    for(int i=0;i<len;i++){
        if(!trie[p][s[i]-'a']){
            return res;//说明已经到达了末尾，没有这样的前缀了。
        }
        p=trie[p][s[i]-'a'];
        res+=cnt[p];
    }
    return res;
}
void solve(){
}
int main(){
    cin>>n>>m;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        insert(s);
    }
    for(int i=0;i<m;i++){
        cin>>s;
        cout<<query(s)<<endl;
    }
    solve();
    return 0;
}