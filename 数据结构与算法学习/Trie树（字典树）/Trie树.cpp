/**
  *@filename:Trie树
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-10 19:55
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1000010;
const int mod = 1e9+7;

//trie树结构，我们需要知道，一个节点有26个子节点，而每一个结点又对应着26个字母中的一个字符。
//所以我们用tree[i][j] = k 来表示编号为i的节点第j个子节点是编号为k的节点。这个编号可以再树中唯一确定一个节点。
int trie[maxn][26];
int sum[maxn];//当前这个单词在查询中出现的次数。

//插入操作，即将字符串中的每个字母逐一插入Tire树中。
//在插入之前我们需要判断这个字母对应的节点是否存在，如果不存在就新建，否则就共享这个节点。
int tot=0;//t是节点的编号。
void insert(string s){
    int len=s.size();
    int idx=0;//为当前字母的编号。
    for(int i=0;i<len;i++){
        if(trie[idx][s[i]-'a']==0){
            //如果当前结点不存在。则新建一个子节点。记录结点的编号。
            trie[idx][s[i]-'a']=++tot;
        }
        idx=trie[idx][s[i]-'a'];//获取子结点的编号。
    }
}
//查询s是否存在。操作即是依次查询字符串中的字符。若当前结点存在子节点a，则继续查询，否则退出。
ll query(string s){
    int len=s.size();
    int idx=0;//为当前字母的编号。
    for(int i=0;i<len;i++){
        if(trie[idx][s[i]-'a']==0){
            //不存在，直接退出，并返回0.
            return 0;
        }
        idx=trie[idx][s[i]-'a'];//获取子节点编号。
    }
    //查询次数加1.
    sum[idx]++;
    return sum[idx];
}
//时间复杂度分析，实际上Trie树就是一种利用空间换取时间的算法。插入和查询的时间复杂度都为O(|s|)。|s|为字符串的长度。
void solve(){
}
int main(){
    solve();
    return 0;
}