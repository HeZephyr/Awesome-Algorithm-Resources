/**
  *@filename:九宫幻方
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-01 10:36
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

//由于每一行每一列都是相同的，所以值为总和除以3.为15.
int a[4][4];
int result[4][4];
bool vis[10];
int cnt;
void dfs(int x,int y){
    if(x==1){
        //说明第0行已经填完了，我们剪枝判断。
        if(a[0][0]+a[0][1]+a[0][2]!=15){
            return;
        }
    }
    else if(x==2){
        if(a[1][0]+a[1][1]+a[1][2]!=15){
            return;
        }
    }
    else if(x==3){
        if(a[2][0]+a[2][1]+a[2][2]==15&&a[0][0]+a[1][0]+a[2][0]==15&&a[0][1]+a[1][1]+a[2][1]==15
        &&a[0][2]+a[1][2]+a[2][2]==15&&a[0][0]+a[1][1]+a[2][2]==15&&a[0][2]+a[1][1]+a[2][0]==15){
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    result[i][j]=a[i][j];//将结果存储。
                }
            }
            cnt++;
        }
    }
    if(a[x][y]==0){
        for(int j=1;j<10;j++){
            if(!vis[j]){
                vis[j]=true;
                a[x][y]=j;
                dfs(x+(y+1)/3,(y+1)%3);
                //还原状态。
                vis[j]=false;
                a[x][y]=0;
            }
        }
    }
    else{
        //说明这个位置不需要填，我们直接进入下一步。
        dfs(x+(y+1)/3,(y+1)%3);
    }
}
void solve(){
    dfs(0,0);//从0开始遍历查找。
    if(cnt>1){
        cout<<"Too Many"<<endl;
        return;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<result[i][j];
            j==2?cout<<endl:cout<<" ";
        }
    }
}
int main(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>a[i][j];
            vis[a[i][j]]=true;//标记用过了的数。
        }
    }
    solve();
    return 0;
}