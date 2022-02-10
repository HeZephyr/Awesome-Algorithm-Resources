/**
  *@filename:调手表
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-09 14:24
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

//bfs题。
int n,k;
//我们有两种策略，若当前为cur，则可进行(cur+1)%n或者(cur+k)%n。那么我们用一个bfs数组来标记即可。
bool vis[maxn];
struct node{
    int idx,step;
};
node a[maxn];
void bfs(){
    vis[0]=true;
    queue<node> q;
    node head,temp;
    head.idx=0,head.step=0;
    q.push(head);
    int maxx=0;
    while(!q.empty()){
        head=q.front();
        q.pop();
        maxx=max(head.step,maxx);
        for(int i=0;i<2;i++){
            temp.idx=i==0?(head.idx+1)%n:(head.idx+k)%n;
            if(!vis[temp.idx]){
                temp.step=head.step+1;
                vis[temp.idx]=true;
                q.push(temp);
            }
        }
    }
    cout<<maxx<<endl;
}
void solve(){
    bfs();
}
int main(){
    cin>>n>>k;
    solve();
    return 0;
}