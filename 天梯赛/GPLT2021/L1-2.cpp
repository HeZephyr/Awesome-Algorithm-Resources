#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1e5+10;

int n,m;
int h[maxn];
int k,temp,len;
bool vis[105];//判断是否已经被确定。
vector<int> a[105];
vector<int> ans;
void dfs(int step,int idx,int cur){
    for(int i=1;i<=m;i++){
        if(a[i][idx]==h[step]){
            dfs(step+1,idx+1,i);
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    for(int i=1;i<=m;i++){
        cin>>k;
        a[i].resize(k);
        for(int j=0;j<k;j++){
            cin>>a[i][j];
        }
    }
    int idx;
    len=1;
    while(len<=n){
        idx=0;
        dfs(len,idx,1);
    } 
    return 0;
}