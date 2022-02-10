/**
  *@filename:P4939-Agent2
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-26 13:36
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 10000000 + 5;
const int mod = 1e9+7;

int n,m;//n天活动安排表，m条命令。
int op,a,b;
int c[maxn];//树状数组，存储信息。
//区间修改单点查询。利用差分数组来实现。
int lowbit(int x){
    return x&(-x);
}
void add(int pos,int x){
    while(pos<=n){
        c[pos]+=x;
        pos+=lowbit(pos);
    }
}
void update(int l,int r){
    add(l,1);
    add(r+1,-1);
}
int get(int pos){
    int ans=0;
    while(pos>0){
        ans+=c[pos];
        pos-=lowbit(pos);
    }
    return ans;
}
int main(){
    cin>>n>>m;
    while(m--){
        cin>>op>>a;
        if(op==0){
            cin>>b;
            update(a,b);
        }
        else{
            cout<<get(a)<<endl;
        }
    }
    return 0;
}
