/**
  *@filename:电话列表
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-11 19:44
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 10000 + 5;
const int mod = 1e9+7;

int t,n;
string s[maxn];
int trie[maxn*10][10],sum[maxn*10];
int tot;
void insert(string s){
    int p=0,len=s.size();
    int temp;
    for(int i=0;i<len;i++){
        int u=s[i]-'0';
        if(!trie[p][u]){
            trie[p][u]=++tot;
        }
        p=trie[p][u];//此时的p已经到了p的孩子结点了。
        sum[p]++;
    }
}
bool query(string s){
    int p=0,len=s.size();
    for(int i=0;i<len;i++){
        int u=s[i]-'0';
        if(sum[trie[p][u]]==1)return false;//只存在1个，说明之后都是一个。
        p=trie[p][u];
    }
    return true;
}
void solve(){
    for(int i=0;i<n;i++){
        if(query(s[i])){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}
int main(){
    cin>>t;
    while(t--){
        memset(trie,0,sizeof(trie));
        memset(sum,0,sizeof(sum));
        tot=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>s[i];
            insert(s[i]);
        }
        solve();
    }
    return 0;
}