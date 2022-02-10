/**
  *@filename:跳蚱蜢
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-26 10:46
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

map<string,int> p;//存储访问过的状态。
//将空格作为动点。由于要寻找最少跳跃，我们需要进行bfs。
struct node{
    int x;
    int step;
    string graph;//记录当前状态的地图。
};
string res;
string result="087654321";
void bfs(){
    node head,temp;
    queue<node> q;
    head.x=0,head.step=0,head.graph=res;
    p[head.graph]++;
    q.push(head);
    while(!q.empty()){
        head=q.front();
        q.pop();
        //接下来开始模拟四种操作。
        if(head.graph==result){
            cout<<head.step<<endl;
            return;
        }
        for(int i=0;i<4;i++){
            if(i==0){
                //左跳。
                temp.x=head.x+1;
                //此时需要判断temp坐标是否符合。
                if(temp.x>8){
                    temp.x=0;
                }
            }
            else if(i==1){
                //跨越跳。
                temp.x=head.x+2;
                if(temp.x>8){
                    temp.x=(temp.x-1)%8;
                }
            }
            else if(i==2){
                temp.x=head.x-1;
                if(temp.x<0){
                    temp.x=8;
                }
            }
            else{
                temp.x=head.x-2;
                if(temp.x<0){
                    temp.x=9+temp.x;
                }
            }
            temp.graph=head.graph,temp.step=head.step+1;
             //交换这两点。
            swap(temp.graph[head.x],temp.graph[temp.x]);
            if(p[temp.graph])continue;
            p[temp.graph]++;
            q.push(temp);
        }
    }
}
void solve(){
    bfs();
}
int main() {
    res="012345678";
    solve();
    return 0;
}