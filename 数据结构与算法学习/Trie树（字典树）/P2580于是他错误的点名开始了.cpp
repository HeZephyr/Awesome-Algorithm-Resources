/**
  *@filename:P2580于是他错误的点名开始了
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-10 20:38
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 10000 + 5;
const int mod = 1e9+7;

int n,m;//班上的人数和点名的名字数。
int trie[maxn*50][26],sum[maxn*50];//trie树，sum[i]记录编号为i的字符串所被查询的次数。
int tot;//编号。
string s;
void insert(string s){
    int len=s.size(),idx=0;
    for(int i=0;i<len;i++){
        if(trie[idx][s[i]-'a']==0){
            //说明没有子节点，那么我们需要创建子节点。
            trie[idx][s[i]-'a']=++tot;
        }
        idx=trie[idx][s[i]-'a'];
    }
}
int query(string s){
    int len=s.size(),idx=0;
    for(int i=0;i<len;i++){
        if(trie[idx][s[i]-'a']==0){
            //说明没有子节点，那么我们直接退出。
            return 0;
        }
        idx=trie[idx][s[i]-'a'];
    }
    sum[idx]++;//编号为idx的字符串被点名了一次。
    return sum[idx];
} 
void solve(){
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        insert(s);
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>s;
        if(query(s)==1){
            puts("OK");
        }
        else if(query(s)==0){
            puts("WRONG");
        }
        else{
            puts("REPEAT");
        }
    }
    solve();
    return 0;
}