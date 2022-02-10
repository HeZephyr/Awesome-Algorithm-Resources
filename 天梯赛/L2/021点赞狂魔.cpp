/**
  *@filename:021点赞狂魔
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-21 16:13
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 10000000 + 5;
const int mod = 1e9+7;

int n,temp;//待统计用户数量。
struct node{
    string name;
    int sum,cnt;//sum为标签出现数。cnt统计不同标签数。
    bool operator<(const node &a){
        if(cnt==a.cnt){
            return sum<a.sum;
        }
        return cnt>a.cnt;
    }
};
node info[105];
bool vis[maxn];//标记标签是否出现过。
void solve(){
    sort(info,info+n);
    for(int i=0;i<3;i++){
        if(i>=n){
            cout<<"-";
        }
        else{
            cout<<info[i].name;
        }
        i==2?cout<<endl:cout<<' ';
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>info[i].name>>info[i].sum;
        info[i].cnt=0;
        memset(vis,false,sizeof(vis));
        for(int j=0;j<info[i].sum;j++){
            cin>>temp;
            if(!vis[temp]){
                info[i].cnt++,vis[temp]=true;
            }
        }
    }
    solve();
    return 0;
}