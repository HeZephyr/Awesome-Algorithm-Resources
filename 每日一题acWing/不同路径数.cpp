#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 10;

int n,m,k;
int a[N][N];
int go[4][2]={1,0,0,1,0,-1,-1,0};
set<int> t;
void dfs(int x,int y,int step,int ans){
    if(step==k){
        t.insert(ans);
        return;
    }
    for(int i=0;i<4;i++){
        int dx=x+go[i][0],dy=y+go[i][1];
        if(dx>=1&&dx<=n&&dy>=1&&dy<=m){
            dfs(dx,dy,step+1,ans*10+a[dx][dy]);
        }
    }
}
void solve(){
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dfs(i,j,0,a[i][j]);//当前正在构成的数。
        }
    }
    cout<<t.size()<<endl;
}
int main(){
    while(cin>>n>>m>>k){
        t.clear();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        solve();
    }
    return 0;
}