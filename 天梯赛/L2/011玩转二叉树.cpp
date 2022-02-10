/**
  *@filename:011玩转二叉树
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-20 19:01
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 10000 + 5;
const int mod = 1e9+7;

int n;//结点个数。
int in[maxn],pre[maxn];
int level[maxn];
void build(int root,int st,int ed,int index){//index为结点下标。
    //根据前序遍历确定根结点。
    if(st>ed)return;
    int i=st;
    //寻找在中序的哪个位置。
    while(i<ed&&in[i]!=pre[root])i++;
    level[index]=pre[root];
    build(root+1,st,i-1,2*index+1);//由于是镜面翻转，我们需要更改index值。
    build(root+1+i-st,i+1,ed,index*2);
}
void solve(){
    memset(level,-1,sizeof(level));
    build(1,1,n,1);
    int cnt=0;
    for(int i=1;i<maxn;i++){
        if(level[i]!=-1&&cnt!=n-1){
            cout<<level[i]<<' ';
            cnt++;
        }
        else if(level[i]!=-1){
            cout<<level[i]<<endl;
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>in[i];
    for(int i=1;i<=n;i++)cin>>pre[i];
    solve();
    return 0;
}