/**
  *@filename:7-7
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-20 12:38
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100 + 5;
const int P = 1e9+7;

int n,m,q;
int a[N][N],b[N][N];
vector<int> a1,b1;
bool vis1[N],vis2[N];//判断他们是否成功约会。
vector<pair<int,int> > result;
void solve(){
}
int main(){
    cin>>n>>m>>q;
    int x,y;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>y;
            a[i][j]=y;
        }
    }
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            cin>>y;
            b[j][i]=y;
        }
    }
    for(int k=1;k<=q;k++){
        cin>>x>>y;
        if(k<=2){
            a1.push_back(y);
            b1.push_back(x);
        }
        else{
            if(!vis1[x]&&!vis2[y]&&a[x][y]>a1[a1.size()-1]&&a[x][y]>a1[a1.size()-2]&&b[x][y]>b1[b1.size()-1]&&b[x][y]>b1[b1.size()-2]){
                result.push_back({x,y});
                vis1[x]=true;
                vis2[y]=true;
            }
            else{
                a1.push_back(y);
                b1.push_back(x);
            }       
        }
    }
    if(result.size()==0){
        cout<<"PTA is only my love"<<endl;
    }
    else{
        for(auto x:result){
            cout<<x.first<<" "<<x.second<<endl;
        }
    }
    solve();
    return 0;
}